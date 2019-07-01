/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main file for the derived Space
**class Elevator.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Elevator.hpp"
#include "Player.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
Elevator::Elevator()
{
    setspaceEntered(false);
    setspaceName("Elevator");
}

//destructor
Elevator::~Elevator()
{
};


//returns space name
string Elevator::getspaceName()
{
    return spaceName;
}

//The following function displays the elevator story when character enters
void Elevator::story(Player & ply)
{
    //if character has not entered elevator before, prints the following message
    if (!getspaceEntered())
    {
        cout << endl << "The elevator doors are stuck open. It's a bit dark inside. The occasional flicker\n"
                        "from the corner light bulb casts just enough momentary light to see to roaches"
                        "scatter...\n\n"

                        "You stare at the buttons...probably best not try out an elevator that looks like\n"
                        "it last ran 40 years ago.\n\n";

        cout << "Looking around...\n"
                "There is a small panel to your right.\n"
                "The doors back to the lobby are on your left.\n"
                "There are only walls in front and behind.\n";

        setspaceEntered(true);
    }

    //if elevator has been entered before, prints the following message
    else
        cout << "Elevator looks the same. Might have a bit more of a bounce to it now.\n\n";
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void Elevator::roomInteract(char choice, Player & ply)
{
    //view wall
    if (choice == 'w')
    {
        cout << endl << "Yup, that's a wall...\n\n";
    }

    //view wall
    if (choice == 's')
    {
        cout << endl << "More walls, more fun...\n\n";
    }

    //inspect panel in elevator
    if (choice == 'd')
    {
        //if panel is unopened
        if (!panelOpen)
        {
            cout << "There's a panel on the wall. Most of the roaches scurry into it...\n"
                    "Would you like to open it?\n"
                    "Enter 1 for yes and 2 for no\n";

            //input validation
            int openPanel = yesNo();

            //if user decides to open panel
            if (openPanel == 1)
            {
                cout << "You carefully open the panel while making sure a roach doesn't land on you...\n"
                        "It now makes sense why it's such a popular area for the roaches. Inside is an\n"
                        "emergency medical kit with preserved food.\n"

                        "You open it and find a WWII preserved military calorie bar. You take a few bites\n"
                        "and toss the rest to the roaches. Everything else has been taken from the med kit.\n\n";

                cout << "*HEALTH GAINED!*\n\n";

                ply.addHealth(10);

                panelOpen = true;
            }

            //if user decides to not open panel
            else
                cout << "Maybe you'll check out the panel later...\n";
        }

        else
            cout << "Nothing else of use left in the panel and emergency kit...\n";
    }


}

//prints possible interactions for user
void Elevator::printInteraction()
{
    cout << "W. Inspect Wall\n"
            "A. Enter Lobby\n"
            "D. Inspect Panel\n"
            "S. Inspect Wall\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";
}


