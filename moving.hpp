// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines an indoor space, inherited from Space class

#ifndef MOVING_HPP
#define MOVING_HPP

#include "space.hpp"

#include <string>

class Moving: public Space
{
    private:
    public:
        Moving(std::string);
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
        virtual ~Moving();
};
#endif