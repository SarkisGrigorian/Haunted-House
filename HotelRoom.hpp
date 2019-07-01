/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for HotelRoom.cpp
*************************************************************/

#ifndef HOTELROOM_HPP
#define HOTELROOM_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class HotelRoom : public Space
{
private:
    bool attacked = false;
    bool safeOpened = false;

public:

    HotelRoom();

    HotelRoom(Space*, Space*, Space*, Space*);

    ~HotelRoom();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();
};



#endif // HALLWAY_HPP
