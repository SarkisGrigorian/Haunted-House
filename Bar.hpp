/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Bar.cpp
*************************************************************/

#ifndef BAR_HPP
#define BAR_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Bar : public Space
{
private:
    bool visited = false;
    bool jukeboxOn = false;
    bool floydPin = false;

public:

    Bar();
    Bar(Space*, Space*, Space*, Space*);

    ~Bar();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();

   void setjukebox(bool);
   bool getjukebox();

};



#endif // BAR_HPP

