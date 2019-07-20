// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .description: reusable menu
// .usage: enter the program name and number of options.

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <cstring>
#include <string>

// defines an option and its number
struct Option
{
    int number;
    std::string name;
};

class Menu
{
private:
    int choice;
    int numOptions;
    std::string programName;
    Option *options;

public:
    Menu();
    Menu(std::string, int);
    static int getInt();
    static bool checkInt(std::string);
    static std::string getName();
    static bool requireChar(std::string);
    static bool requireyn(std::string charInput);
    static char getYN();
    int validate();
    void setOptions(int, std::string);
    void setInteractiveOptions();
    int displayOptions();
    ~Menu();
};

#endif
