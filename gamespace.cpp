// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: June 9th, 2019
// .description: implementation file for gamespace; a collection of difference linked spaces

#include "gamespace.hpp"

//. default constructor
Gamespace::Gamespace()
{
    energy = new Item ("Energy", 0, 3);
    pkey = new Item ("Key!", 0, 3);
    pkey->setKey(true);
    energy_drain = new Item ("Energy Drain", 10, 0);
    dementor = new Item ("Dementor", 10, 0);
    flower = new Item ("Flower", 1, 2);
    coin = new Item ("Coin", 3, 2);
    treasure = new Item ("Treasure", 5, 10);

    //Assign the 6 spaces to type
    train = new Moving("Train");
    train->addItem(*coin);
    forest = new Dangerous("Forest");
    forest->addItem(*flower);
    bedroom = new Sindoor("Bedroom");
    bedroom->addItem(*energy);
    safe = new Sindoor ("Safe");
    safe->addItem(*coin);
    safe->setExit();//this is how you win the game
    desert = new Dangerous("Desert");
    desert->addItem(*pkey);
    underwater = new Dangerous("Underwater");
    underwater->addItem(*energy_drain);

    //assign the spaces to Spaces in games
    sgBedroom = new SpaceInGame (bedroom);
    sgSafe = new SpaceInGame (safe);
    sgTrain = new SpaceInGame (train);
    sgForest = new SpaceInGame (forest);
    sgDesert = new SpaceInGame (desert);
    sgUnderwater = new SpaceInGame (underwater);

    sgBedroom->top = sgTrain;
    sgBedroom->bottom = sgForest;
    sgBedroom->left = sgDesert;
    sgBedroom->right = sgUnderwater;

    
    sgSafe->top = NULL;
    sgSafe->bottom = sgUnderwater;
    sgSafe->left = sgTrain;
    sgSafe->right = NULL;
  
    sgTrain->top = NULL;
    sgTrain->bottom = sgBedroom;
    sgTrain->left = NULL;
    sgTrain->right = sgSafe;

    sgForest->top = sgBedroom;
    sgForest->bottom = NULL;
    sgForest->left = NULL;
    sgForest->right = NULL;

    sgDesert->top = NULL;
    sgDesert->bottom = NULL;
    sgDesert->left = NULL;
    sgDesert->right = sgBedroom;

    sgUnderwater->top = sgSafe;
    sgUnderwater->bottom = NULL;
    sgUnderwater->left = sgBedroom;
    sgUnderwater->right = NULL;

    //Set bedroom as the start of the game
    start = sgBedroom;
}

//. adds a player to the start of the game
//. parameter: a player pointer
void Gamespace::addPlayer(Player *p)
{
    start->space->setPlayer(p);
    std::cout << p->getName() << " is in space " << start->space->getName() <<
    "\nSpace Description: " << start->space->getDescription() << std::endl;
}


//.returns the name of the space on top of current space
std::string Gamespace::getTop()
{
    if (!start->top)
    {
        return "There's Nothing at the top of " +
        start->space->getName();
    }

    return start->top->space->getName(); 
}

//.returns the name of the space on bottom of current space
std::string Gamespace::getBottom()
{
    if (!start->bottom)
    {
        return "There's Nothing at the Bottom of " +
        start->space->getName();
    }

    return start->bottom->space->getName(); 
}

//.returns the name of the space on left of current space
std::string Gamespace::getLeft()
{
    if (!start->left)
    {
        return "There's Nothing at the left of " +
        start->space->getName();
    }

    return start->left->space->getName(); 
}

//.returns the name of the space on right of current space
std::string Gamespace::getRight()
{
    if (!start->right)
    {
        return "There's Nothing at the right of " +
        start->space->getName();
    }

    return start->right->space->getName(); 
}

//. moves the player up if it's not null
void Gamespace::moveUp()
{
    if ((start->top) == NULL)
    {
        std::cout << getTop() <<
        " .Choose another direction.\n";
    }
    else
    {
        //put the player in the other space
        std::cout << start->top->space->getDescription();
        start->top->space->setPlayer(start->space->getPlayer());

        //put the player in the other space
        start->space->removePlayer(start->space->getPlayer());

        //set current space
        start = start->top;
    }
}

//. moves the player down if it's not null
void Gamespace::moveDown()
{
    if (!start->bottom)
    {
        std::cout << getBottom() <<
        " .Choose another direction.\n";
    }
    else
    {
        //put the player in the other space
        std::cout << start->bottom->space->getDescription();
        start->bottom->space->setPlayer(start->space->getPlayer());

        //put the player in the other space
        start->space->removePlayer(start->space->getPlayer());

        //set current space
        start = start->bottom;
        std::cout << start->space->getDescription();
    }
}

//. moves the player left if it's not null
void Gamespace::moveLeft()
{
    if (!start->left)
    {
        std::cout << getLeft() <<
        " .Choose another direction.\n";
    }
    else
    {
        //put the player in the other space
        std::cout << start->left->space->getDescription();
        start->left->space->setPlayer(start->space->getPlayer());

        //put the player in the other space
        start->space->removePlayer(start->space->getPlayer());

        //set current space
        start = start->left;
        std::cout << start->space->getDescription();
    }
}

//. moves the player right if it's not null
void Gamespace::moveRight()
{
    if (!start->right)
    {
        std::cout << getBottom() <<
        " .Choose another direction.\n";
    }
    else
    {
        //put the player in the other space
        std::cout << start->right->space->getDescription();
        start->right->space->setPlayer(start->space->getPlayer());

        //put the player in the other space
        start->space->removePlayer(start->space->getPlayer());

        //set current space
        start = start->right;
        std::cout << start->space->getDescription();
    }
}

//.print the player's current location and neighboring space names
void Gamespace::whereAmI()
{
    std::cout << "\n**********\nYou are in space " << start->space->getName()
    << "\nLeft: " << getLeft()
    << "\nRight: " << getRight()
    << "\nTop: " << getTop()
    << "\nBottom: " << getBottom()
    << "\n**********\n";
}

//.returns the item in current space in which the player is
Item Gamespace::getItem()
{
    return start->space->getItem();
}

//. returns the space name
std::string Gamespace::getspaceName()
{
    return start->space->getType();
}

//. returns the current player space
SpaceInGame * Gamespace::getSpace()
{
    return start;
}

//. sets space to a user specified space
void Gamespace::setSpace(Space *s)
{
    Player *p = start->space->getPlayer();
    start->space->removePlayer(start->space->getPlayer());

    if (s->getType() == "Desert")
    {
        //set current space
        start = start->bottom->left;
        start->space->setPlayer(p);
    }
    else if (s->getType() == "Forest")
    {
        start = start->bottom->bottom;
        start->space->setPlayer(p);
    }
    else
    {
        start = start->bottom->right;
        start->space->setPlayer(p);
    }

    

    // //set current space to s
    // start->space = s;
    // s->setPlayer(p);
    
}
//. destructor
Gamespace::~Gamespace()
{
    delete energy;
    energy = NULL;
    delete energy_drain;
    energy_drain = NULL;
    delete flower;
    flower = NULL;
    delete coin;
    coin = NULL;
    delete pkey;
    pkey = NULL;
    delete dementor;
    dementor = NULL;
    delete treasure;
    treasure = NULL;

    delete train;
    train = NULL;
    delete forest;
    forest = NULL;
    delete bedroom;
    bedroom = NULL;
    delete safe;
    safe = NULL;
    delete desert;
    desert = NULL;
    delete underwater;
    underwater = NULL;

    delete sgBedroom;
    sgBedroom = NULL;
    delete sgSafe;
    sgSafe = NULL;
    delete sgTrain;
    sgTrain = NULL;
    delete sgForest;
    sgForest = NULL;
    delete sgDesert;
    sgDesert = NULL;
    delete sgUnderwater;
    sgUnderwater = NULL;
    // delete start;
    // start = NULL;
}