/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Hallway.cpp
*************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Hallway : public Space
{
private:
    bool door = false;
    bool dayMark = false;

public:

    Hallway();

    Hallway(Space*, Space*, Space*, Space*);

    ~Hallway();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();
};



#endif // HALLWAY_HPP



