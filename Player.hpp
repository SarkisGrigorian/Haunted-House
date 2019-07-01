/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This is the header file for player.cpp
*************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>


using std::string;

using std::vector;


class Player
{
private:
    int health;
    bool wonGame;
    string pName;
    vector <string> bag;

public:
    Player();

    void checkBag();

    bool matchItem(string );

    void putInBag(string);

    string getName();
    void setName(string);

    void addHealth(int);
    void takeHealth(int);
    int getHealth();

    bool getWinStatus();
    void setWinStatus(bool);

};

#endif // PLAYER_HPP
