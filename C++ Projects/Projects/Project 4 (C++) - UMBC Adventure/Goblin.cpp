/******************************************************************************
 ** File:    Goblin.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Goblin class and Goblin.h header file.
 ** This class is a child class of Monster.cpp, and a grandchild class
 ** of Entity.cpp.
 ** In this class, a Goblin is created and instantiated with a name and hp
 ** using its parent and grandfather class functions.
 **  It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "Goblin.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: Goblin() - Default Constructor
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin() : Monster()
{
  SetName(" ");
  SetHealth(0);
}


// Name: Goblin(string name, int hp)
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin(string name, int hp) : Monster(name, hp)
{
  SetName(name);
  SetHealth(hp);
}

// Name: SpecialAttack
// Description: Defines the Goblin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Goblin::SpecialAttack()
{
  int damage = 2;

  cout << GetName() <<  " knaws at your ankles!" << endl;

  return damage;

}
