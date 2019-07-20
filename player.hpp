// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines a player.

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include "item.hpp"
#include <vector>

class Player
{
private:
    std::string name;
    std::string SpaceName;
    int points;
    std::vector <Item> itemVect;// Item ** items;//use items = new Item [num] to initialize
    bool dies;
    bool has_key;
public:
    Player(std::string n);
    void addItems(Item);
    std::string getSpaceName();
    void setSpaceName(std::string);
    int getPoints();
    bool isDead();
    bool hasKey();
    std::string getName();
    bool won();
    void subtractPoints(int);
    ~Player();
};
#endif
