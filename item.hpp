// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines the item class.
#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

class Item
{
    private:
        int cost;
        int gain;
        bool is_key;
        std::string name;
        int points;
    public:
        Item(std::string n, int c, int g);
        Item();
        virtual std::string getName();
        virtual int getCost();
        virtual int getGain();
        virtual bool isKey();
        virtual void setKey(bool);
        virtual ~Item();
};
#endif