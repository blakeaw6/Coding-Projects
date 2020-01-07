/******************************************************************************
 ** File:    Monster.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Monster class and the Monster.h header file.
 ** This class is a child class of Entity.cpp, and a parent class to 
 ** Skeleton.cpp, Goblin.cpp, and BabyDragon.cpp. 
 **  In this class, a monster  is created and instantiated with a name an hp 
 ** using it's parent class functions.
 **  It also includes the purely virtual function Attack()
 *****************************************************************************/
#include "Monster.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: Monster() - Default Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster() : Entity() 
{
  SetName(" ");
  SetHealth(0);
}

// Name: Monster(string name, int hp) - Overloaded Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster(string name, int hp) : Entity(name, hp) 
{
  SetName(name);
  SetHealth(hp);
}


// Name: Attack()
// Description: Describes attack statements for monster
// Preconditions: None
//sd Postconditions: Returns damage
int Monster::Attack()
{
  int damage = 1;

  cout << GetName() << " deals 1 point of damage! " << endl;

  return damage;
}


