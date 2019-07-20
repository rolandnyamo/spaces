#include "menu.hpp"
#include <string>
#include <limits>
#include <cstdio>
#include <cstdlib>

//input validation
//.this function checks if a string has any chars that are not numbers ([a-z],.).
//.returns false if any such chars are detected, true otherwise.
bool Menu::checkInt(std::string s)
{
    for(size_t i = 0; i < s.size(); i++)
    {
        if ((int (s[i]) < 48) || (int (s[i]) > 57) ) {
            std::cout << "\nIncorrect input. Enter an int: ";
            std::cin.clear();
            return false;
        }
    }
    
    return true;
}

//.this function gets user input in string format, then converts it to int if there 
//.are no non numeric characters in.
//.returns the int
int Menu::getInt()
{
    std::string strInput; 
    char chInput [256] = "";
    bool valid = false;
    
    while(!valid)
    {
        std::getline(std::cin, strInput);
        valid = checkInt(strInput);
    }
    
    for(size_t i = 0; i < strInput.size(); i++)
    {
        chInput[i] = strInput[i];  
    }
    
    return atoi(chInput);
}
//. adapted from past group project
bool Menu::requireChar(std::string charInput)
{
	return charInput.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890. ") == std::string::npos;
}
//. gets string input from the user for the character and team name
std::string Menu::getName()
{
    std::string answer;
    std::getline(std::cin, answer);
    std::cin.clear();
    bool valid = requireChar(answer);

    while (!valid || (answer.empty()))
    {
        std::cout << "Enter a valid name: ";
        std::getline(std::cin, answer);
        std::cin.clear();
        valid = requireChar(answer);
    }

    return answer;
}

//. y/n helper function
bool Menu::requireyn(std::string charInput)
{
	return charInput.find_first_not_of("yn") == std::string::npos;
}

//. gets y/n from the user

char Menu::getYN()
{
    std::string answer;
    std::getline(std::cin, answer);
    std::cin.clear();
    bool valid = requireyn(answer);

    while (!valid || (answer.empty()))
    {
        std::cout << "Enter 'y' or 'n': ";
        std::getline(std::cin, answer);
        std::cin.clear();
        valid = requireyn(answer);
    }

    return answer[0];
}
//. default constructor
Menu::Menu()
{
    //
}
//.constructor with menu name and number of options as arguments.
Menu::Menu(std::string pName, int nOptions)
{
    programName = pName;
    numOptions = nOptions; //add input validation for int
    options = new Option[numOptions]; //dynamically allocating memory for options
}
//.sets options interactively.
void Menu::setInteractiveOptions()
{
    //for each option, ask the user to enter the option name
    for(int i = 0; i < numOptions; i++)
    {
        std::cout << "\nEnter the option name for Option " << i + 1 << " : ";
        options[i].number = i;
        std::getline (std::cin, options[i].name);
    }
    
}
//.sets menu options with an option number and option name.
void Menu::setOptions(int num, std::string opt)
{
    options[num - 1].number = num;
    options[num - 1].name = opt;
}
//.displauys previously set options and asks for user choice.
int Menu::displayOptions()
{

    choice = -1; //initialize choice to an unusual number
    bool correctChoice = false;
    std::cout << programName << std::endl;

    for(int i = 1; i <= numOptions; i++)
        {
            std::cout << i << ". " << options[i - 1].name << std::endl;
        }
    std::cout << "\nEnter your choice: ";
    while (!correctChoice)
    {
        choice = getInt();
        if (choice > numOptions || choice < 1) 
        {
            std::cout << "Incorrect choice. Enter a choice between 1 and " << numOptions << std::endl;
            std::cout << "\nEnter your choice: ";
        }
        else
        {
            correctChoice = true;
        }
    }   
    return choice;    
}
//.deallocates previously allocated memory.
Menu::~Menu()
{
    delete [] options;
    options = NULL;
}