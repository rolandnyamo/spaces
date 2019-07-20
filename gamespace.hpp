// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: header file that defines a gamespace, which is a collection of several
// .linked spaces.

#ifndef GAMESPACE_HPP
#define GAMESPACE_HPP

#include "space.hpp"
#include "sindoor.hpp"
#include "moving.hpp"
#include "dangerous.hpp"

struct SpaceInGame
{
   Space *space;
   SpaceInGame *top;
   SpaceInGame *bottom;
   SpaceInGame *left;
   SpaceInGame *right;

   SpaceInGame(Space *s = NULL, SpaceInGame *t = NULL, SpaceInGame *b = NULL, SpaceInGame *l = NULL, SpaceInGame *r = NULL)
   {
       space = s;
       top = t;
       bottom = b;
       left = l;
       right = r;
   }
};

class Gamespace//have setups 1, 2, 3 that get randomly selected for different space setups
{
    private:

        Item *energy;
        Item *energy_drain;
        Item *flower;
        Item *coin;
        Item *pkey;
        Item *dementor;
        Item *treasure;

        SpaceInGame *start;//starting point in the game
        SpaceInGame *sgTrain;
        SpaceInGame *sgForest;
        SpaceInGame *sgDesert;
        SpaceInGame *sgUnderwater;
        SpaceInGame *sgBedroom;
        SpaceInGame *sgSafe;

        //declare all 6 spaces, they will be of several types
        Space *train;
        Space *forest;
        Space *bedroom;
        Space *safe;
        Space *desert;
        Space *underwater;

        Player *p;

    public:
        Gamespace(/* args */);
        void addPlayer(Player *);
        std::string getTop();
        std::string getBottom();
        std::string getLeft();
        std::string getRight();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        SpaceInGame * getSpace();
        void setSpace(Space *);
        std::string getspaceName();
        void whereAmI();
        Item getItem();
        ~Gamespace();
};
#endif

