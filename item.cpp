#include "item.hpp"

//. description: default constructor
Item::Item()
{
    //nothing
}
//. description: Item default constructor that initializes the item properties
//. argument: name string, cost and gain ints
Item::Item(std::string n, int c, int g)
{
    name = n;
    is_key = false;
    cost = c;
    gain = g;
}

//. returns the item's name
std::string Item::getName()
{
    return name;
}

//. returns the item's cost to the player
int Item::getCost()
{
    return cost;
}

//. returns the item's gain to the player
int Item::getGain()
{
    return gain;
}

//. sets the key flag on this item. i.e. true if item is the key.
void Item::setKey(bool b)
{
    is_key = b;
}

//. returns whether the item is the key to outside or not
bool Item::isKey()
{
    return is_key;
}

//. destructor, deletes dynamically allocated memory, if any
Item::~Item()
{
    //nothing
}