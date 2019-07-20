// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: implementation file fora player.

#include "player.hpp"

//. constructor that with an argument of a player's name
//. sets the player's initial points
//. reserves space in memory for items collected
Player::Player(std::string n)
{
    name = n;
    points = 15;
    dies = false;
    // SpaceName = "";
    has_key = false;
}

//. adds an item to the vector
void Player::addItems(Item c)
{
    itemVect.push_back(c);
    points -= c.getCost();
    points += c.getGain();

    std::cout << "\nAdded " << c.getName() << std::endl;

    if (points <= 0)
    {
        dies = true;
        points = 0;
    }
    else if (c.isKey())
    {
        has_key = true;
    } 
}

//. subtracgts points from the player
void Player::subtractPoints(int p)
{
    points -= p;

    if (points <= 0)
    {
        dies = true;
        points = 0;
        std::cout << "\nYou have zero points.\n";
    }

    std::cout << "\nUpdated points: " << points << std::endl;
}

//. happens when the player has won
bool Player::won()
{
    return has_key;
}

//. happens when the player has the key
bool Player::hasKey()
{
    return has_key;
}

//. returns the string name of the player
std::string Player::getName()
{
    return name;
}

//. sets space name as the space in which the player is
void Player::setSpaceName(std::string s)
{
    SpaceName = s;
}

//. returns the name of the space in which the player is
std::string Player::getSpaceName()
{
    return SpaceName;
}

//. returns the player's points
int Player::getPoints()
{
    return points;
}

//. returns true if the player is dead, false otherwise
bool Player::isDead()
{
    return dies;
}

//. destructor
Player::~Player()
{
    //nothing for now.
}
