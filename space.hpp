// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines a space base class

#ifndef SPACE_HPP
#define SPACE_HPP

#include "player.hpp"
#include "item.hpp"
#include "menu.hpp"


class Space
{
    protected:
        bool wantsToJump;
        Menu *sMenu = NULL;//for the space menu
        std::string name;
        std::string stype;//indoor, dangerous, moving
        std::string description;
        bool has_player;
        bool is_exit;
        Player *sPlayer = NULL;
        Item i;
    public:
        Space(std::string);
        Space();
        virtual Player * getPlayer() = 0;
        virtual void setPlayer(Player *) = 0;
        virtual void removePlayer(Player *) = 0;
        virtual bool hasPlayer() = 0;
        virtual void setExit() = 0;
        virtual bool isExit() = 0;
        virtual std::string getName() = 0;
        virtual std::string getType() = 0;
        virtual void addItem(Item) = 0;
        virtual Item getItem() = 0;
        virtual void setName(std::string) = 0;
        virtual bool jump() = 0;
        // virtual void setType(std::string) = 0;
        virtual void setDescription(std::string) = 0;
        virtual std::string getDescription() = 0;
        virtual ~Space() = 0;
};
#endif