/******************************************************************************
 ** File:    Paladin.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Paladin class and Paladin.h header file.
 ** This class is a child class of Character.cpp, and a grandchild class
 ** of Entity.cpp.
 ** In this class, a Paladin is created and instantiated with a name and hp
 ** using its parent and grandfather class functions.
 **  It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "Paladin.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: Paladin() - Default Constructor
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin() : Character()
{
  SetName(" ");
  SetHealth(0);
}

// Name: Paladin(string name, int hp)
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin(string name, int hp) : Character(name, hp)
{
  SetName(name);
  SetHealth(hp);
}


// Name: ~Paladin - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Paladin::~Paladin()
{

}
// Name: SpecialAttack
// Description: Defines the Paladin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Paladin::SpecialAttack()
{
  int damage = rand() % 9 + 1;

  cout << GetName() << " uses smite evil!" << endl;

  return damage;
}
