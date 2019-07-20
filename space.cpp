// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: Space base class implementation file

#include "space.hpp"

//. constructor for space, sets the name
Space::Space(std::string n)
{
    //nothing
}

//. default constructor for space
Space::Space()
{
    //nothing
}

//. sets the space name to a user specified string.
void Space::setName(std::string n)
{
    name = n;
}

//. returns the player in this space with all its attributes.
Player * Space::getPlayer()
{    
    return sPlayer;
}

//. sets (adds) a player in this space
void Space::setPlayer(Player *p)
{
    sPlayer = p;
    has_player = true;
    
}

//. adds an item to the space
void Space::addItem(Item i_add)
{
    i = i_add;
}

//. gets the item from the space
Item Space::getItem()
{
    return i;
}
//. removes a player from this space
void Space::removePlayer(Player *p)
{
    sPlayer = NULL;
    has_player = false;
}

//. sets this space as the game's exit/winning point
void Space::setExit()
{
    is_exit = true;
}

//. returns true if this space is the game's exit, false if it's not
bool Space::isExit()
{
    return is_exit;
}

//. returns the space's name in string format.
std::string Space::getName()
{
    return name;
}

//. returns the space's type in string format.
std::string Space::getType()
{
    return stype;
}

//. adds a user-specified string to the space's description.
void Space::setDescription(std::string d)
{
    description += "\n" + d;
}

//. returns the entire space description
std::string Space::getDescription()
{
    return description;
}
//. returns true if there's a player in this space
bool Space::hasPlayer()
{
    if (!sPlayer)
    {
        return false;
    }

    return true;
}

//. destructor
Space::~Space()
{
    //nothing yet
}