/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main input validation file that
**checks user inputs to ensure that the input is either
**a directional/menu input of w,a,s,d,b or a menu/yes/no
**input of 1 or 2.
*************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

//input validation that checks to see if user input an integer value
int userVal()
{
    string userChoice;
    int stringToInt;
    getline(cin, userChoice);

    while(cin.fail() || cin.eof() || userChoice.find_first_not_of("12") != string::npos || userChoice.empty())
    {
        cout << endl;
        cout << "Inputed option is not correct.\n";
        cout << "Input 1 to Start Game and 2 to Exit.\n\n";
        cout << "Enter option here: ";

        cin.clear();

        getline(std::cin, userChoice);
    }

    stringToInt = atoi(userChoice.c_str());
    return stringToInt;
}


//input validation to check if user has inputted direction/menu keys of w,a,s,d,b
char direction()
{
    string userChoice;
    getline(cin, userChoice);

    while(cin.fail() || cin.eof() || userChoice.find_first_not_of("wasdbqmWASDBQM") != string::npos || userChoice.empty() || userChoice.size() > 1)
    {
        cout << endl;
        cout << "Inputted option is not correct.\n";
        cout << "Make selections or moves with w, a, s, d and b\n";
        cout << "Enter option here: \n";

        cin.clear();

        getline(std::cin, userChoice);
    }

    return userChoice[0];
}

//input validation that checks to see if user input an integer value of 1 or 2
int yesNo()
{
    string userChoice;
    int stringToInt;
    getline(cin, userChoice);

    while(cin.fail() || cin.eof() || userChoice.find_first_not_of("12") != string::npos || userChoice.empty())
    {
        cout << endl;
        cout << "Enter 1 to accept, 2 to decline..." << endl;

        cin.clear();

        getline(std::cin, userChoice);
    }

    stringToInt = atoi(userChoice.c_str());
    return stringToInt;
}

