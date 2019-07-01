/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is a derived class of space. It contains
**the lobby, one of the first locations the user can visit
**during the game.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Lobby.hpp"
#include "Player.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
Lobby::Lobby()
{
    setspaceEntered(false);
    setspaceName("Lobby");
}
//destructor
Lobby::~Lobby(){};

//returns the name of the space
string Lobby::getspaceName()
{
    return spaceName;
}

//starts the story of the lobby when player enters
void Lobby::story(Player & ply)
{
    //if space has not been visited displays the following message
    if (!getspaceEntered())
    {
        cout << "The lobby's fairly empty. Not much except a check in desk next to the hotel entrance.\n"
                "You can tell that this place was once really bustling with people from all\n"
                "the photos around the lobby.\n\n"
                "Looking around, the doors and windows have been hammered shut. This place must have been evacuated\n"
                "a long time ago. No way you'd be able to get out of anywhere here.\n\n"
                "Standing in the center of the lobby...\n"
                "In front is an entrance to a hallway\n"
                "To your left is the bar...\n"
                "To your right is an elevator...\n"
                "Behind you is the check in desk...\n";

        setspaceEntered(true);

    }

    //if space has been previously visited displays the following message
    else
    {
        cout << "Lobby is just as you left it. Dead rats and all...\n\n";
        printInteraction();
    }
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void Lobby::roomInteract(char choice, Player & ply)
{

    //chracter inspects drawer
    if (choice == 's')
    {
        //if drawer has not been previously opened
        if (!drawer)
        {
            cout << "Not much on the desk. Rats must have eaten most of the papers...\n"
                    "You check around. Most of the drawers are empty except for a drawer right in the center.\n"
                    "Seems to be locked. Try and open it?\n"
                    "Enter 1 for yes and 2 for no.\n";

                    //input validation
                    int openDrawer = yesNo();

            //drawer opens if user has Floyd's pin
            if (openDrawer == 1 && ply.matchItem("Floyd Pin"))
            {
                cout << endl << "Seems like Floyd's name tag came in handy. You used the pin in the back to open the drawer.\n";
                cout << "Inside there is a room key. You place it in your bag. Never know when you'll need it...\n\n";

                ply.putInBag("Room Key");
                drawer = true;
            }

            //drawer won't open if user does not have Floyd's pin
            else if (openDrawer == 1 && !ply.matchItem("Floyd Pin"))
            {
                cout << "The drawer won't budge. Better try and find something to open it with...\n\n";
            }

            //if user decides to not open drawer
            if (openDrawer == 2)
            {
                cout << endl << "Opening drawers is a waste of time. You rush to search for a way out elsewhere.\n\n";
            }


        }

        //if drawer has been previously opened
        else
            cout << "Not much else left to inspect on the drawer.\n\n";
    }

}

//prints possible interactions for user
void Lobby::printInteraction()
{
    cout << "W. Enter Hallway\n"
            "A. Enter Bar\n"
            "D. Enter Elevator\n"
            "S. Inspect Desk\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";

}
