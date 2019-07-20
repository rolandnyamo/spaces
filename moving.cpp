// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: implementation file that defines an indoor space, inherited from Space class

#include "moving.hpp"

//. constructor for indoor space, sets the name
Moving::Moving(std::string n)
{
    wantsToJump = false;
    sMenu = new Menu("\nJumping Menu\n", 2);
    setName(n);
    sPlayer = NULL;
    is_exit = false;
    has_player = false;
    stype = "Moving";
    description = name + " is a moving space. Choose to jump into another space.\n";
}

//. sets the space name to a user specified string.
void Moving::setName(std::string n)
{
    name = n;
}

//. returns the player in this space with all its attributes.
Player * Moving::getPlayer()
{    
    return sPlayer;
}

//. adds an item to the space
void Moving::addItem(Item i_add)
{
    i = i_add;
}

//. gets the item from the space
Item Moving::getItem()
{
    return i;
}

//. sets (adds) a player in this space
void Moving::setPlayer(Player *p)
{
    sPlayer = p;
    has_player = true;
    
    //Checks if this player would rather move to another space.
    std::cout << "\nWould you like to jump? y/n: ";
    char ans = sMenu->getYN();

    if (ans == 'y')
    {
        wantsToJump = true;
    }
}

//. checks if the player chose to move to another space
bool Moving::jump()
{
    return wantsToJump;
}

//. removes a player from this space
void Moving::removePlayer(Player *p)
{
    sPlayer = NULL;
    has_player = false;
}

//. sets this space as the game's exit/winning point
void Moving::setExit()
{
    is_exit = true;
}

//. returns true if this space is the game's exit, false if it's not
bool Moving::isExit()
{
    return is_exit;
}

//. returns the space's name in string format.
std::string Moving::getName()
{
    return name;
}

//. returns the space's type in string format.
std::string Moving::getType()
{
    return stype;
}

//. adds a user-specified string to the space's description.
void Moving::setDescription(std::string d)
{
    description += " " + d;
}

//. returns the entire space description
std::string Moving::getDescription()
{
    return description;
}
//. returns true if there's a player in this space
bool Moving::hasPlayer()
{
    if (!sPlayer)
    {
        return false;
    }

    return true;
}

//. destructor
Moving::~Moving()
{
    delete sMenu;
    sMenu = NULL;
}