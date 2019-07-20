// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: implementation file that defines an indoor space, inherited from Space class

#include "sindoor.hpp"
#include <ctime>

//. constructor for indoor space, sets the name
Sindoor::Sindoor(std::string n)
{
    setName(n);
    sPlayer = NULL;
    is_exit = false;
    has_player = false;
    stype = "Indoor";
    description = name + " is an Indoor space.\n";
}

//. sets the space name to a user specified string.
void Sindoor::setName(std::string n)
{
    name = n;
}

//. returns the player in this space with all its attributes.
Player * Sindoor::getPlayer()
{    
    return sPlayer;
}


//. checks if the player chose to move to another space
bool Sindoor::jump()
{
    return wantsToJump;
}

//. sets (adds) a player in this space
void Sindoor::setPlayer(Player *p)
{
    sPlayer = p;
    has_player = true;

    srand(time(NULL));
    int ran = 1 + rand()% 2;
    if (name != "Bedroom")
    {
        std::cout << "\nWould you like to open a window? You may or may gain or lose points.\ny/n: ";
        //Checks if this player would like to open a window.
        
        char ans = Menu::getYN();

        if (ans == 'y')
        {
            if (ran == 1)
            {
                // sPlayer->subtractPoints(2);
                std::cout << "\nYou have lost 2 points\n";
            }
            else
            {
                // sPlayer->subtractPoints(-3);
                std::cout << "\nYou have earned 3 points\n";
            }
        }
        else
        {
            if (ran == 1)
            {
                // sPlayer->subtractPoints(4);
                std::cout << "\nYou have lost 4 points\n";
            }
            else
            {
                // sPlayer->subtractPoints(-1);
                std::cout << "\nYou have earned 1 point\n";
            }
        }
    }
}

//. adds an item to the space
void Sindoor::addItem(Item i_add)
{
    i = i_add;
}

//. gets the item from the space
Item Sindoor::getItem()
{
    return i;
}

//. removes a player from this space
void Sindoor::removePlayer(Player *p)
{
    sPlayer = NULL;
    has_player = false;
}

//. sets this space as the game's exit/winning point
void Sindoor::setExit()
{
    is_exit = true;
}

//. returns true if this space is the game's exit, false if it's not
bool Sindoor::isExit()
{
    return is_exit;
}

//. returns the space's name in string format.
std::string Sindoor::getName()
{
    return name;
}

//. returns the space's type in string format.
std::string Sindoor::getType()
{
    return stype;
}

//. adds a user-specified string to the space's description.
void Sindoor::setDescription(std::string d)
{
    description += " " + d;
}

//. returns the entire space description
std::string Sindoor::getDescription()
{
    return description;
}
//. returns true if there's a player in this space
bool Sindoor::hasPlayer()
{
    if (!sPlayer)
    {
        return false;
    }

    return true;
}

//. destructor
Sindoor::~Sindoor()
{
    //nothing yet
}