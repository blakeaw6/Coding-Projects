/******************************************************************************
 ** File:    Wizard.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Wizard class and Wizard.h header file.
 ** This class is a child class of Character.cpp, and a grandchild class
 ** of Entity.cpp.
 ** In this class, a Rogue is created and instantiated with a name and hp
 ** using its parent and grandfather class functions.
 **  It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "Wizard.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: Wizard() - Default Constructor
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard() : Character()
{
  SetName(" ");
  SetHealth(0);
}

// Name: Wizard(string name, int hp)
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(string name, int hp) : Character(name, hp)
{
  SetName(name);
  SetHealth(hp);
}

// Name: ~Wizard - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Wizard::~Wizard()
{

}

// Name: SpecialAttack
// Description: Defines the Wizard's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Wizard::SpecialAttack()
{
  int damage = rand() % 13 + 3;

  cout << GetName() << " casts magic missle!" << endl;

  return damage;
}
