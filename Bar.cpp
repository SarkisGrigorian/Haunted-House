/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the main file for the derived Space
**class of Bar.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Bar.hpp"
#include "Player.hpp"
#include "inputVal.hpp"
#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

//constructor
Bar::Bar()
{
    setspaceEntered(false);
    setspaceName("Bar");
}

//destructor
Bar::~Bar()
{
}

//returns the name of the space
string Bar::getspaceName()
{
    return spaceName;
}

/*the following function prints the bar's story when the character
//enters for the first time*/
void Bar::story(Player & ply)
{
    //prints following if player is entering bar for first time
    if (getspaceEntered() == false)
    {
        cout << endl << endl << endl << endl << "You wake up";

        //makes program sleep for easier reading
        for (int x = 0; x < 3; x++)
        {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "." << " ";
        }


        cout << endl << "Your ears are ringing. Your face feels hot." << endl;
        cout << "You don't know where you are..." << endl;

        //makes program sleep for easier reading
        std::this_thread::sleep_for(std::chrono::seconds(2));

        cout << "The sound of the crowd around you slowly fills in." << endl;
        cout << "People laughing. Glasses clinking. A man in the distance bets "
                "he can do a handstand on the table..." << endl;

        cout << endl << "You're at a hotel bar." << endl;

        cout << "You shut your eyes. Your elbows keeping you balanced on the bar stool." << endl;

        cout << endl << "'HEY PAL!'" << endl << endl;

        //makes program sleep for easier reading
        for (int x = 0; x < 3; x++)
        {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "." << " ";
        }

        cout << endl << endl << "'HEY PAL! You ok?'\n\n"
        "You look up. A man in his late 40's smiles at you from behind the bar. \n"
        "His curled mustache almost tickles his own nose.\n"
        "'Want some water?' he says.\n\n";


        cout << "***Enter 1 to accept water or 2 to decline.***" << endl << endl;

        //input validation
        int water = yesNo();

        //prints if user accepts water
        if (water == 1)
        {
            cout << endl << endl << "You grab the water from his hands. He watches you as "
            "you finish it almost instantly." << endl << endl;
        }

        //prints if user declines water
        else
        {
            cout << endl << endl << "You shake shake your head no." << endl;
        }

        cout << "'What's your name?' he asks." << endl;


        cout << endl << "***Enter your name below: ***" << endl;

        string name;

        //collects user inputted name
        getline(cin, name);

        ply.setName(name);

        cout << endl << "'Ah, nice to meet you " << ply.getName() << ". My name's Floyd. Let me know if you need anything.\n\n" //"THE SHINING" REFERENCE :)

        "The voices around you get louder. You press your hands against your ears and shut your eyes.\n"
        "The room is spinning.\n"
        "You can hear two men arguing nearby...\n"
        "Their voices, now the only one's heard in the room as everyone else quiets down...\n"
        "Someone screams 'STOP! NO! NO!'";

        //makes program sleep for easier reading
        std::this_thread::sleep_for(std::chrono::seconds(3));

        cout << "A GUNSHOT ECHOS THROUGH THE ROOM! A CRASH! GLASS SHATTERING! SCREAMS!\n"
        "You open your eyes in shock and turn around.\n"
        "No one's there.\n"
        "The entire bar is empty.\n"
        "Almost as if no one has been here for years...\n";

        //makes program sleep for easier reading
        std::this_thread::sleep_for(std::chrono::seconds(3));

        cout << "A few of the tables and chairs are broken and to their side\n"
        "The bottles behind the bar are empty with broken glass across the counters\n"
        "You stand up. Confused. Thinking to yourself...Where is everyone? How did you get here?\n"
        "A sharp pains rings through your stomach.\n"
        "You look down. A clear gunshot on the left spews blood...but how?\n"
        "You press against the wound. You need to get out of here and get help. FAST!\n"

        "Your work satchel lays next to you. It's empty however...\n"



        "You toss it across your shoulder and look around...\n\n\n"

        "To your left is the bar...\n"
        "In front is the old jukebox...\n"
        "Behind you are narrow double doors with the words KITCHEN: EMPLOYEE'S ONLY written on them.\n"
        "And to your right is a door with the words 'LOBBY' handwritten above...\n\n\n"
        "*Use W, A, S, D to move around and interact with your surrounding...*\n"
        "*Enter B to view backpack contents and M to view a map. Find a way out soon, you're losing a lot of blood...\n\n\n";


        setspaceEntered(true);
    }

    //if jukebox is not on yet prints message
    else if (!getjukebox())
    {
        cout << "Rats scurry as you enter the bar. It remains just as you left it...hopefully.\n\n";
    }
}

/*If the player is interacting with objects/situations in the room rather
//than traveling to another location, the directional keys that do not
//make the character travel correspond with one of the options below*/
void Bar::roomInteract(char choice, Player & ply)
{
    //inspect jukebox
    if (choice == 'w')
    {

        //prints if jukebox is off
       if (!getjukebox())
       {

            cout << "Although old and covered in dust, the jukebox seems like it should work...\n"
		    "You wipe some of the dust revealing the album that was last played -\n"
		    "'The Key to Freedom' by an artist you've never heard before.\n"
                    "You pull the jukebox a bit forward to see if it's plugged in. The wire is a bit frayed.\n\n";

            cout << "Would you like to try and plug it in?\n\n";

            cout << "Enter 1 for yes and 2 for no\n\n";

            int jbPlug = yesNo();

            //WINNING MOVE! If user has Electric Tape they turn on the jukebox and can "escape" to the hotel...
            if (jbPlug == 1 && ply.matchItem("Electrical Tape"))
                {
                    cout << endl << "You used some of the Electric Tape in your backpack to wrap the frayed wire and turn on the jukebox.\n\n";
                    setjukebox(true);
                    cout << endl << endl << "The jukebox lights flicker. A small spark flies from the socket and the entire bar\n"
                                            "rattles...You step back. Too frozen to run. Your eyes are glued to the jukebox.\n"
                                            "The colors of the jukebox dance around. As the records inside begin to flop back and forth.\n"
                                            "'Heartbreak Hotel' by Elvis begins to play. You're transfixed. Still unsure of what's\n"
                                            "happening. The song plays until it reaches the lyrics 'You'll be so lonely...' and the \n"
                                            "record begins to loop........\n\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely..'\n"
                                            "'You'll be so lonely...you could die...'\n\n"
                                            "You fall back and land in a bar chair. Your head starts to pound.\n"
                                            "The room begins to fill with laughter. Glass clinking. A man bet's he can do a handstand...\n"
                                            "No...No...this can't be happening. You close your eyes.\n"
                                            "You shake your head...not real...not real...\n\n\n"
                                            "You finally wake up. You're back in your work hotel. Everything looks normal.\n"
                                            "You're fine. You get up and wash in the bathroom.\n"
                                            "Still stressed you head out of your room and down the hall to the bar.\n"
                                            "You sit down. Everything's normal. You grab a menu and look at what you can order.\n"
                                            "You lower the menu. ready to order and from the kitchen walks out a man in his 40's.\n"
                                            "Curled mustache an all...\n";
                                            cout << "'Welcome back " << ply.getName() << "...'\n\n\n";
                                            ply.setWinStatus(true);


                }

            //if user does not have Electric Tape prints the following message and reduces health
            else if (jbPlug == 1 && !ply.matchItem("Electric Tape"))
                {
                    cout << endl << "You attempt to connect the jukebox. The frayed wire shocks and hurts you in the process. You set the\n"
                    "wire down to avoid a fire.\n\n";
                    ply.takeHealth(5);

                    cout << "**HEALTH REMAINING: " << ply.getHealth() << " **\n\n";
                }

            else
                cout << "You decide it's best not to mess with the jukebox right now...\n\n";
       }

    }

    //inspect bar
    if (choice == 'a')
    {
        //prints if user has the Floyd pin already
        if (floydPin)
        {
        cout << endl << "You're thirsty...but there's nothing to drink at the bar. All the bottles are empty...\n\n";
        }

        //prints if user has not picked up Floyd's pin yet
        else
        {
            cout << endl << "Floyd's name tag with a safety pin back is sitting on the bar table. Take it with you?\n\n";
            cout << "Enter 1 for yes or 2 for no.\n";

            //input validation
            int takePin = yesNo();

            //if user takes pin, it is placed in player bag
            if (takePin == 1)
            {
                cout << endl << "You put the pin in your bag. Might come in handy later. If not, it at least looks cool...\n\n";
                ply.putInBag("Floyd Pin");
                floydPin = true;
            }

            //prints if user leaves pin behind
            else
                cout << endl << "You leave the pin on the bar table.\n\n";
        }
    }

}


//prints possible interactions for user
void Bar::printInteraction()
{
    cout << "W. Inspect Jukebox\n"
            "A. Inspect Bar\n"
            "D. Enter Lobby\n"
            "S. Enter Kitchen\n"
            "B. Backpack Contents\n"
            "M. View Map         \n"
            "Q. Quit to Main Menu\n\n";
}

//controls whether jukebox is on or off
void Bar::setjukebox(bool TF)
{
    jukeboxOn = TF;
}

//returns jukebox status (on or off)
bool Bar::getjukebox()
{
    return jukeboxOn;
}
