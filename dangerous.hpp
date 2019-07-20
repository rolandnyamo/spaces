// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines an indoor space, inherited from Space class

#ifndef DANGEROUS_HPP
#define DANGEROUS_HPP

#include "space.hpp"
#include <string>

class Dangerous: public Space
{
    private:
    public:
        Dangerous(std::string);
        virtual Player * getPlayer();
        virtual void setPlayer(Player *);
        virtual void removePlayer(Player *);
        virtual bool hasPlayer();
        virtual void setExit();
        virtual bool isExit();
        virtual std::string getName();
        virtual std::string getType();
        virtual void setName(std::string);
        virtual void addItem(Item);
        virtual Item getItem();
        virtual bool jump();
        // virtual void setType(std::string);
        virtual void setDescription(std::string);
        virtual std::string getDescription();
        virtual ~Dangerous();
};
#endif