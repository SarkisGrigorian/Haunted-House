/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main file for the derived Space
**class of HotelRoom.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "HotelRoom.hpp"
#include "Player.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
HotelRoom::HotelRoom()
{
    setspaceEntered(false);
    setspaceName("Room 17");
}

//destructor
HotelRoom::~HotelRoom(){};

//returns the spaces name.
string HotelRoom::getspaceName(){return spaceName;}

//the following function prints the Hotel's story
void HotelRoom::story(Player & ply)
{
    //prints if user enters hotel room for first time
    if (!getspaceEntered())
    {
        cout << endl << "To your surprise the door wasn't locked...\n\n"
                "The room lights are on and the room looks like it has never been touched.\n"
                "Not a single rat, roach, or even dirt can be found. It's spotless.\n"
                "A chill run downs your spine.\n\n";

        cout << "You'd rather not be in the room too long. Crying can be heard from behind the restroom.\n"
                "You start looking around the room...\n\n"

                "In front of you is the restroom door.\n"
                "To your left is a hotel safe that's been left out.\n"
                "To your right is the bed.\n"
                "Behind you is the door to the hallway.\n\n";


        setspaceEntered(true);
    }

    //prints if user has entered hotel room and has been attacked
    else if (attacked)
    {
        cout << "You quietly enter the hotel room making sure not to alarm the monster behind the door.\n\n";
    }

    //prints if user has entered hotel room and has not been attacked
    else
        cout << "You enter the hotel room. Everything looks just like you had seen last. Still creepy...\n\n";
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void HotelRoom::roomInteract(char choice, Player & ply)
{
    //inspect restroom
    if (choice == 'w')
    {
        //prints if user has not been attacked previously
        if (!attacked)
        {
            cout << "Oh no. You had a feeling that something was wrong about this place. \n"
                    "As you open the door, an older woman sits at the rim of the tub. Her \n"
                    "appearance the opposite of the room - dirty, weathered and unholy. She\n"
                    "smiles revealing blackened teeth. Her hair falls out in clumps as she stands.\n"
                    "You're frozen with fear. She starts to approach you and right as you are \n"
                    "about to close the door her hand stops the door. She screams 'DON'T EVER\n"
                    "COME HERE AGAIN!' and she digs her long demonic nails deep into your chest.\n"
                    "You fall back. She slams the door closed. You have taken A LOT of damage.\n\n";

            cout << "*MASSIVE DAMAGE TAKEN*" << endl;

            //user takes health damage
            ply.takeHealth(15);

        }

        //prints if user enters restroom again.
        else
        {
            cout << "Seems like you didn't learn your lesson the first time. This time, as you open the restroom door\n"
                    "the woman is already standing and waiting. Now with both hands, she dives her nails into your chest.\n";

            cout << "*MASSIVE DAMAGE TAKEN*" << endl;

            ply.takeHealth(25);

        }
    }

    //inspect safe
    if (choice == 'a')
    {
        //prints if safe has not been opened previously
        if (!safeOpened)
        {
            cout << "You inspect the safe. A bit too heavy to lift...\n"
                    "Would you like to try and open it?\n"
                    "Enter 1 for yes and 2 for no\n";

            //input validation
            int trySafe = yesNo();

            //prints if user decides to open safe and has the room key
            if (trySafe == 1 && ply.matchItem("Room Key"))
            {
                cout << endl << "Seems like the room key wasn't for the door. The key\n"
                                "opens the safe. No money. However there are 2 items. Electrical\n"
                                "Tape and a a single painkiller. \n"
                                "You place the Electrical Tape in your bag and take the painkiller.\n";

                                //collects electrical tape
                                ply.putInBag("Electrical Tape");

                                //adds health to user
                                ply.addHealth(25);
                                cout <<"*HEALTH REMAINING " << ply.getHealth() << "* " << endl << endl;
            }

            //prints if user does not have the key
            else
                cout << endl << "The safe is locked. Maybe there's a way to open it?\n\n";
        }

        //prints if the safe has already been opened
        else
            cout << endl << "The safe is now empty.\n\n";
    }

    //inspect bed
    if (choice == 'd')
    {
        cout << "Just a regular bed. A bit too clean compared to everything else in the hotel...\n\n";
    }

}

//prints possible interactions for user
void HotelRoom::printInteraction()
{
    cout << "W. Inspect Restroom\n"
            "A. Inspect Safe\n"
            "D. Inspect Bed\n"
            "S. Enter Hallway\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";
}


