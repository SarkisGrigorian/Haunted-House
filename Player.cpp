/************************************************************
**Author: Sarkis Grigorian
**Email: grigoris@oregonstate.edu
**Username: grigoris
**CS 162 - Final
**Date: 6/11/2019
**Description: This contains the Player class. The Player
**class represents the user in the game. It creates and
**sets a player variable with a starting health and win
**status. It also controls the bag size.
*************************************************************/

#include <iostream>
#include "Player.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor
Player::Player()
{
    health = 100;
    setWinStatus(false);
}

//Prints items in bag currently
void Player::checkBag()
{
    //error message if bag is empty
    if (bag.size() == 0)
    {
        cout << endl << "BAG IS EMPTY" << endl;
    }

    //if bag is not empty, prints items
    else
    {
    cout << "BAG ITEMS: \n";
    for (int x = 0; x < bag.size(); x++)
    {
        cout << x + 1 << ". " << bag[x] << endl;
    }
    }
    cout << endl;
}

/*checks for a matching item in bag
//returns true or false based on item being found in bag*/
bool Player::matchItem(string item)
{
    bool foundItem = false;

    for (int x = 0; x < bag.size(); x++)
    {
        if(bag[x] == item)
        {
            foundItem = true;
        }
    }

    return foundItem;
}

//Allows user to store items in bag (Max capacity of 5)
//REFERENCE: https://piazza.com/class/jtwllvly29p204?cid=530
void Player::putInBag(string item)
{
    //if bag has less than 5 items, add item to bag
    if (bag.size() < 5)
    {
        bag.push_back(item);
    }

    //error message if bag is full
    else
        cout << endl << "BAG IS FULL." << endl;
}

//prints out the players name set by user at start of game
string Player::getName()
{
    return pName;
}


//sets the players name
void Player::setName(string name)
{
    pName = name;
}

//adds health to the players current health
void Player::addHealth(int num)
{
    health = health + num;
}

//removes health from player (attacked/bleeding out)
void Player::takeHealth(int num)
{
    health = health - num;
}


//prints out the player's current health
int Player::getHealth()
{

    if (health < 0)
    {
        health = 0;
    }

    return health;
}

//returns true or false based on if the user won
bool Player::getWinStatus()
{
    return wonGame;
}

//sets players winner status
void Player::setWinStatus(bool stat)
{
    wonGame = stat;
}
