/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main.cpp for the haunted house.
*************************************************************/

#include <iostream>
#include "inputVal.hpp"
#include "Space.hpp"
#include "startGame.hpp"
#include "Player.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    bool tryAgain = true;

    //menu repeats until user decides to quit.
    while(tryAgain)
    {

    //starting game introduction and instructions
    cout << "********************************************************\n"
            "             You'll be so lonely...                     \n"
            "              by Sarkis Grigorian                       \n"
            "                                                        \n"
            "Game Description: You find yourself injured at an old   \n"
            "and haunted hotel. You have no recollection how you got \n"
            "got there or how to get out. Using the keys W, A, S, D, \n"
            "B, and M explore the hotel and try and find a way out   \n"
            "before you bleed out from the injury...that is, if      \n"
            "there even is a way out.....                            \n"
            "********************************************************\n\n"

            "                    Main Menu                           \n\n"

            "1. Start Game\n"
            "2. Exit      \n"
            "Enter Option Here: ";



    int mmChoice = userVal();

    //menu choices based on what the user selects
    switch(mmChoice)
    {
        case 1:
            {
                cout << endl << endl;
                cout << "There's no turning back now...\n" << endl << endl << endl;
                startGame();
            }
            break;
        case 2:
            {
            tryAgain = false;
            return 0;
            }
            break;
    }
    }

    return 0;
}
