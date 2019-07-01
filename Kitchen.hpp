/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Kitchen.cpp
*************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Kitchen : public Space
{

private:
    bool cabinInspect;
    bool eatRice;
public:

    Kitchen();

    Kitchen(Space*, Space*, Space*, Space*);

    ~Kitchen();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();
};



#endif // KITCHEN_HPP

