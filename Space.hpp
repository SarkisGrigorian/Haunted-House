/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for Space.cpp
*************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>

#include "Player.hpp"

using std::string;

class Space
{


protected:

    bool spaceEntered;


public:

    bool getspaceEntered();
    void setspaceEntered(bool);

    void setspaceName(string);

    Space * top;
    Space * right;
    Space * left;
    Space * bottom;

    void setLocations(Space *&, Space *&, Space *&, Space *&);

    //virtual functions
    virtual string getspaceName() = 0;
    virtual void story(Player &) = 0;
    virtual void roomInteract(char, Player &) = 0;
    virtual void printInteraction() = 0;

    string spaceName;

    Space();
    virtual ~Space();
};

#endif // SPAC_HPP

