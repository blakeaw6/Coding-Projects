/******************************************************************************
 ** File:    Rogue.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 **
 ** This file contains the Rogue class and Rogue.h header file.
 ** This class is a child class of Character.cpp, and a grandchild class
 ** of Entity.cpp. 
 ** In this class, a Rogue is created and instantiated with a name and hp
 ** using its parent and grandfather class functions. 
 **  It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "Rogue.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: Rogue() - Default Constructor
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue() : Character() 
{
  SetName(" ");
  SetHealth(0);
}

// Name: Rogue(string name, int hp)
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue(string name, int hp) : Character(name, hp)
{
  SetName(name);
  SetHealth(hp);
}

// Name: ~Rogue - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Rogue::~Rogue()
{


}

// Name: SpecialAttack
// Description: Defines the Rogue's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Rogue::SpecialAttack()
{
  int damage = rand() % 13 + 2;
  cout << "damage = " << damage << endl;
  
  cout << GetName() << " performs a sneak attack!" << endl;

  return damage;
}
