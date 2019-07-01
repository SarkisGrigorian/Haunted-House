/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main file for the derived Space
**class of Kitchen
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Kitchen.hpp"
#include "Player.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
Kitchen::Kitchen()
{
    setspaceEntered(false);
    setspaceName("Kitchen");
    cabinInspect = false;
    eatRice = false;
}

//destructor
Kitchen::~Kitchen()
{};

//returns space name
string Kitchen::getspaceName()
{
    return spaceName;
}

//the following function prints the Kitchen's story
void Kitchen::story(Player & ply)
{
    //prints if user has not entered kitchen previously
    if (!getspaceEntered())
    {
        cout << "As you enter a rat jumps from the hanging lamp above and scurries away.\n"
                "The lamp sways back and forth.\n"
                "You look around. A bloodied butcher's knife lays on the counter. Most of the cabinets\n"
                "are opened with nothing inside. Bags of uncooked rice lay on the floor. Most torn open by\n"
                "animals making their way through the kitchen.\n\n";

        cout << "Looking around...\n"
                "An unopened cabinet is in front of you...\n"
                "A picture of a group of men is to your left...\n"
                "Am opened bag of uncooked rice is to your right...\n"
                "Behind you is the door back to the bar.\n\n";

        setspaceEntered(true);
    }

    //prints if user has entered kitchen previously
    else
        cout << "The kitchen smells..." << endl;
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void Kitchen::roomInteract(char choice, Player & ply)
{

    //inspect cabinet
    if(choice == 'w')
    {
        //prints if cabinet has not been opened before
        if (!cabinInspect)
        {
            cout << "You look inside the cabinet.\n"
                    "There are some untouched dry packaged crackers.\n"
                    "Would you like to eat them?\n"
                    "Enter 1 for yes and 2 for no.\n";

            //input validation
            int eatCracker = yesNo();

            //prints if user eats the cracker they gain health points
            if (eatCracker == 1)
            {
                cout << endl << "You eat a few crackers. This may hold you for a bit longer..." << endl;
                ply.addHealth(10);
            }

            //prints if user chooses not to eat cracker
            else
                cout << endl << "You open the crackers but decide not to eat them. Might make you sick...\n\n";

            cabinInspect = true;
        }

        //prints if user opened or ate crackers previously
        else
            cout << endl << "Only the packaging of the opened crackers remains now. Seems like the rats got at them...\n\n";
    }

    //inspect photo
    if(choice == 'a')
    {
        cout << endl << "Seems like a 40 year old group photo of all the kitchen workers...Is that Floyd in the background?\n\n";
    }

    //inspect rice
    if(choice == 'd')
    {
        //prints if user has not eaten the rice before
        if(!eatRice)
        {
            cout << "You're a bit weak and hungry. The rice seems old and uncooked.\n"
                    "Would you like to try and eat it?\n"
                    "Enter 1 for yes and 2 for no\n";

            //input validation
            int rice = yesNo();

            //prints if user eats rice. Reduces health
            if (rice == 1)
            {
                cout << "You eat the rice. It was old and makes you feel nauseous.\n"
                        "Definitely not a good idea. Your condition is worse.\n\n";

                ply.takeHealth(10);

                eatRice = true;
            }

            //prints if user does not eat rice
            else
            {
                cout << "You decide not to eat the rice. Maybe save it for later?\n\n";
            }
        }

        //prints if user has eaten the rice previously
        else
        {
            cout << endl << "Made you sick last time...Maybe different this time?\n"
                    "Try to eat uncooked old rice again?\n"
                    "Enter 1 for yes and 2 for no\n";

            //input validation
            int eatAgain = yesNo();

            //prints if user chooses to eat rice again. Reduces health.
            if (eatAgain == 1)
            {
                cout << endl << "Seems like you didn't learn from the last time. The rice makes you sick\n"
                                "again and takes some health...\n";
                ply.takeHealth(10);
            }

            //prints if user decides not to eat the rice again.
            else
            {
                cout << endl << "The thought of eating the rice again sounds gross to you. You walk away from it...\n\n";
            }
        }
    }


}

//prints possible interactions for user
void Kitchen::printInteraction()
{

    cout << "W. Inspect Cabinet\n"
            "A. Inspect Picture\n"
            "D. Inspect Rice\n"
            "S. Enter Bar\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";

}


