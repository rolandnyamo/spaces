// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines an indoor space, inherited from Space class

#ifndef SINDOOR_HPP
#define SINDOOR_HPP

#include "space.hpp"
#include <string>

class Sindoor: public Space
{
    private:
    public:
        Sindoor(std::string);
        virtual Player * getPlayer();
        virtual void setPlayer(Player *);
        virtual void removePlayer(Player *);
        virtual bool hasPlayer();
        virtual void setExit();
        virtual bool isExit();
        virtual std::string getName();
        virtual std::string getType();
        virtual void addItem(Item);
        virtual Item getItem();
        virtual bool jump();
        virtual void setName(std::string);
        // virtual void setType(std::string);
        virtual void setDescription(std::string);
        virtual std::string getDescription();
        virtual ~Sindoor();
};
#endif