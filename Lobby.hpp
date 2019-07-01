/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Lobby.cpp
*************************************************************/

#ifndef LOBBY_HPP
#define LOBBY_HPP

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Lobby : public Space
{
private:
    bool drawer = false;

public:

    Lobby();
    Lobby(Space*, Space*, Space*, Space*);

    ~Lobby();
   string getspaceName();

   void story(Player &);
   void roomInteract(char, Player &);
   void printInteraction();
};



#endif // LOBBY_HPP

