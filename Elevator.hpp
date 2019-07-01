/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Elevator.cpp
*************************************************************/

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Elevator : public Space
{
private:
    bool panelOpen = false;


public:

    Elevator();
    Elevator(Space*, Space*, Space*, Space*);

    ~Elevator();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();
};



#endif // ELEVATOR_HPP
