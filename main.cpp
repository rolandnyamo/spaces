#include "gamespace.hpp"
#include "menu.hpp"
#include "item.hpp"

int main()
{
    Gamespace g1;

    std::string gDescr = "\nYou're stuck in an unsafe space ";
    gDescr += " and need to move between different spaces to get to safe space.\n";
    gDescr += "\nOne space contains a key, which you need to unlock the safe space.";
    gDescr += " Without a key you can't get into the safe space (and win the game).\n";

    gDescr += "However, each item that you collect deducts from your points, so you may run out of points ";
    gDescr +=  "and die either before you collect the key or get to the sace space.\n\n";


    Menu menu1("\n\nSPACES: A TEXT-BASED ADVENTURE GAME\n" + gDescr, 2);

    menu1.setOptions(1, "Start");
    menu1.setOptions(2, "Quit");

    int choice = menu1.displayOptions();



    while (choice !=2)
    {
        std::cout << "\nPlease enter the player's name: ";
        std::string pName = menu1.getName();
        Player *p1 = new Player(pName);

        g1.whereAmI();
        std::cout << "\n";
        std::cout << "Points: " << p1->getPoints() << std::endl;

        Menu menu2("\n\nChoose next step\n", 7);

        menu2.setOptions(1, "Move up");
        menu2.setOptions(2, "Move down");
        menu2.setOptions(3, "Move left");
        menu2.setOptions(4, "Move right");
        menu2.setOptions(5, "Where am I?");
        menu2.setOptions(6, "Show " + p1->getName() + "\'s points");
        menu2.setOptions(7, "Go back");

        int choice2 = menu2.displayOptions();

        while (choice2 != 7)
        {
            if (choice2 == 1)
            {
                g1.moveUp();
                p1->setSpaceName(g1.getspaceName());
                Item i = g1.getItem();
                std::cout << "\nPick item \"" << i.getName() << "\"? y/n: ";

                char ans = menu2.getYN();

                if (ans == 'y')
                {
                    p1->addItems(i);
                    std::cout << "\nUpdated Points: " << p1->getPoints() << std::endl;
                }
                

                //if the player wants to jump
                if ((p1->getSpaceName() == "Moving") && (g1.getSpace()->space->jump()))
                {
                    Menu menu3("\n\n  Where?\n", 3);
                    menu3.setOptions(1, "Desert");
                    menu3.setOptions(2, "Forest");
                    menu3.setOptions(3, "Underwater");

                    int choice3 = menu3.displayOptions();
                    SpaceInGame *s1 = g1.getSpace();

                    if (choice3 == 1)
                    {
                        g1.setSpace(s1->bottom->left->space);
                    }

                    else if (choice3 == 2)
                    {
                        g1.setSpace(s1->bottom->bottom->space);
                    }
                    else if (choice3 == 3)
                    {
                        g1.setSpace(s1->bottom->right->space);
                    }
                }
                else if (p1->getSpaceName() == "Dangerous")
                {
                    p1->subtractPoints(6);
                }                

                choice2 = -1;
                
                std::cout << "\nPlayer points: " << p1->getPoints();
                g1.whereAmI();
            }
            else if (choice2 == 2)
            {
                g1.moveDown();
                p1->setSpaceName(g1.getspaceName());

                Item i = g1.getItem();
                std::cout << "\nPick item \"" << i.getName() << "\"? y/n: ";

                char ans = menu2.getYN();

                if (ans == 'y')
                {
                    p1->addItems(i);
                    std::cout << "\nUpdated Points: " << p1->getPoints() << std::endl;
                }
                //if the player wants to jump
                if ((p1->getSpaceName() == "Moving") && (g1.getSpace()->space->jump()))
                {
                    Menu menu3("\n\n  Where?\n", 3);
                    menu3.setOptions(1, "Desert");
                    menu3.setOptions(2, "Forest");
                    menu3.setOptions(3, "Underwater");

                    int choice3 = menu3.displayOptions();
                    SpaceInGame *s1 = g1.getSpace();

                    if (choice3 == 1)
                    {
                        g1.setSpace(s1->bottom->left->space);
                    }

                    else if (choice3 == 2)
                    {
                        g1.setSpace(s1->bottom->bottom->space);
                    }
                    else if (choice3 == 3)
                    {
                        g1.setSpace(s1->bottom->right->space);
                    }
                }
                else if (p1->getSpaceName() == "Dangerous")
                {
                    p1->subtractPoints(6);
                }                

                choice2 = -1;

                std::cout << "\nPlayer points: " << p1->getPoints();
                g1.whereAmI();
            }
            else if (choice2 == 3)
            {
                g1.moveLeft();
                p1->setSpaceName(g1.getspaceName());

                Item i = g1.getItem();
                std::cout << "\nPick item \"" << i.getName() << "\"? y/n: ";

                char ans = menu2.getYN();

                if (ans == 'y')
                {
                    p1->addItems(i);
                    std::cout << "\nUpdated Points: " << p1->getPoints() << std::endl;
                }

                //if the player wants to jump
                if ((p1->getSpaceName() == "Moving") && (g1.getSpace()->space->jump()))
                {
                    Menu menu3("\n\n  Where?\n", 3);
                    menu3.setOptions(1, "Desert");
                    menu3.setOptions(2, "Forest");
                    menu3.setOptions(3, "Underwater");

                    int choice3 = menu3.displayOptions();
                    SpaceInGame *s1 = g1.getSpace();

                    if (choice3 == 1)
                    {
                        g1.setSpace(s1->bottom->left->space);
                    }

                    else if (choice3 == 2)
                    {
                        g1.setSpace(s1->bottom->bottom->space);
                    }
                    else if (choice3 == 3)
                    {
                        g1.setSpace(s1->bottom->right->space);
                    }
                }
                else if (p1->getSpaceName() == "Dangerous")
                {
                    p1->subtractPoints(6);
                }   
                choice2 = -1;

                std::cout << "\nPlayer points: " << p1->getPoints();
                g1.whereAmI();
            }            
            else if (choice2 == 4)
            {
                g1.moveRight();
                p1->setSpaceName(g1.getspaceName());

                Item i = g1.getItem();
                std::cout << "\nPick item \"" << i.getName() << "\"? y/n: ";

                char ans = menu2.getYN();

                if (ans == 'y')
                {
                    p1->addItems(i);
                    std::cout << "\nUpdated Points: " << p1->getPoints() << std::endl;
                }

                //if the player wants to jump
                if ((p1->getSpaceName() == "Moving") && (g1.getSpace()->space->jump()))
                {
                    Menu menu3("\n\n  Where?\n", 3);
                    menu3.setOptions(1, "Desert");
                    menu3.setOptions(2, "Forest");
                    menu3.setOptions(3, "Underwater");

                    int choice3 = menu3.displayOptions();
                    SpaceInGame *s1 = g1.getSpace();

                    if (choice3 == 1)
                    {
                        g1.setSpace(s1->bottom->left->space);
                    }

                    else if (choice3 == 2)
                    {
                        g1.setSpace(s1->bottom->bottom->space);
                    }
                    else if (choice3 == 3)
                    {
                        g1.setSpace(s1->bottom->right->space);
                    }
                }
                else if (p1->getSpaceName() == "Dangerous")
                {
                    p1->subtractPoints(6);
                }   
                choice2 = -1;

                std::cout << "\nPlayer points: " << p1->getPoints();
                g1.whereAmI();
            }
            else if (choice2 == 5)
            {
                g1.whereAmI();
            }
            else if (choice2 == 6)
            {
                std::cout << p1->getName() << "\'s points: " << p1->getPoints()
                << std::endl;
            }

            if (p1->getSpaceName() == "Safe" && p1->hasKey())
            {
                std::cout << "\nCongrats, you won!\n\nBack to Menu\n\n";
                choice2 = 7;
            }
            else if (p1->isDead())
            {
                std::cout << "\n\nGame Over.\n\nBetter luck next time.\n\nBack to Menu\n\n";
                choice2 = 7;
            }
            else
            {
                choice2 = menu2.displayOptions();
            }
        }

        choice = menu1.displayOptions();

        delete p1;
        p1 = NULL;        
    }
}