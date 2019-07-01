/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the space class which represents the
**space in which the player can be in.
*************************************************************/

#include <iostream>
#include "Space.hpp"
#include "Player.hpp"

//constructor
Space::Space()
{
    Space * T = NULL;
    Space * L = NULL;
    Space * R = NULL;
    Space * B = NULL;

    setLocations(T, L, R, B);
}

//destructor
Space::~Space(){};

//this function sets the locations of the 4 space pointers
void Space::setLocations(Space *& T, Space *& L, Space *& R, Space *& B)
{
    top = T;
    left = L;
    right = R;
    bottom = B;
}

//returns true or false if a space has been visited previously by player
bool Space::getspaceEntered()
{
    return spaceEntered;
}

//sets the location previously visited to true or false
void Space::setspaceEntered(bool TF)
{
    spaceEntered = TF;
}

//sets the name of the space
void Space::setspaceName(string sName)
{
    spaceName = sName;
}
