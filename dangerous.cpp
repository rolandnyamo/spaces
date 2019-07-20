// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: implementation file that defines an indoor space, inherited from Space class

#include "dangerous.hpp"

//. constructor for indoor space, sets the name
Dangerous::Dangerous(std::string n)
{
    setName(n);
    sPlayer = NULL;
    is_exit = false;
    has_player = false;
    stype = "Dangerous";
    description = name + " is an Dangerous space. You lose 6 point just for being here.\n";
}

//. sets the space name to a user specified string.
void Dangerous::setName(std::string n)
{
    name = n;
}

//. returns the player in this space with all its attributes.
Player * Dangerous::getPlayer()
{    
    return sPlayer;
}

//. sets (adds) a player in this space
void Dangerous::setPlayer(Player *p)
{
    sPlayer = p;
    has_player = true;
}


//. checks if the player chose to move to another space
bool Dangerous::jump()
{
    return wantsToJump;
}

//. removes a player from this space
void Dangerous::removePlayer(Player *p)
{
    sPlayer = NULL;
    has_player = false;
}

//. adds an item to the space
void Dangerous::addItem(Item i_add)
{
    i = i_add;
}

//. gets the item from the space
Item Dangerous::getItem()
{
    return i;
}

//. sets this space as the game's exit/winning point
void Dangerous::setExit()
{
    is_exit = true;
}

//. returns true if this space is the game's exit, false if it's not
bool Dangerous::isExit()
{
    return is_exit;
}

//. returns the space's name in string format.
std::string Dangerous::getName()
{
    return name;
}

//. returns the space's type in string format.
std::string Dangerous::getType()
{
    return stype;
}

//. adds a user-specified string to the space's description.
void Dangerous::setDescription(std::string d)
{
    description += " " + d;
}

//. returns the entire space description
std::string Dangerous::getDescription()
{
    return description;
}
//. returns true if there's a player in this space
bool Dangerous::hasPlayer()
{
    if (!sPlayer)
    {
        return false;
    }

    return true;
}

//. destructor
Dangerous::~Dangerous()
{
    //nothing yet
}