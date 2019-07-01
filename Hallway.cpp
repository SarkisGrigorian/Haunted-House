/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main file for the derived Space
**class of Hallway.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Hallway.hpp"
#include "Player.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
Hallway::Hallway()
{
    setspaceEntered(false);
    setspaceName("Hallway");
}

//destructor
Hallway::~Hallway(){};

//returns the spaces name
string Hallway::getspaceName()
{
    return spaceName;
}

//displays Hallway story when user enters space
void Hallway::story(Player & ply)
{
    //prints if user enters hallway for first time
    if (!getspaceEntered())
    {
    cout << "You enter the hallway. A few lights scatters along side the room doors\n"
            "keep the hallway lit. Some flicker and from the side of your eye it \n"
            "looks like a person is standing at the very end.\n\n"
            "You rub your eyes and look again. Nothing there. Must be the tired...\n\n";

    cout << "Looking around, most of the doors are boarded up again...\n"
            "In front, at the very end of the hallway, a single door \n"
            "seems to have had it's boards removed.\n"
            "To your left and your right are walls.\n"
            "Behind you is the lobby\n\n";


    setspaceEntered(true);

    }

    //prints if user has previously entered the hallway
    else
        cout << "Is the hallway getting longer? No...must be seeing things...\n\n";
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void Hallway::roomInteract(char choice, Player & ply)
{
    //inspect wall
    if (choice == 'a')
    {
        cout << endl << "There isn't much on this wall.\n\n";
    }

    //inspect wall
    if (choice == 'd')
    {
        //if this wall has not been inspected yet
        if (!dayMark)
        {
        cout << endl << "The wall is covered in lines which seem to count to the number of days that have passed.\n"
                        "Seems like you weren't the first to go down this path...\n"
                        "Jokingly, you take out the Floyd's bobby pin and add your own 'day' mark.\n\n";
        dayMark = true;
        }

        //if wall has been inspected previously
        else
            cout << "You've already added your 'day' mark. You look at the other marks and chuckle as to how someone could be\n"
            "stuck here this long.\n A day is all you need. \n\n";
    }

}

//prints possible interactions for user
void Hallway::printInteraction()
{
    cout << "W. Enter room\n"
            "A. Inspect Wall\n"
            "D. Inspect Wall\n"
            "S. Enter Lobby\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";
}
