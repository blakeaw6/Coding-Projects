/******************************************************************************
 ** File:    BabyDragon.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the BabyDragon class and BabyDragon.h header file.
 ** This class is a child class of Monster.cpp, and a grandchild class
 ** of Entity.cpp.
 ** In this class, a BabyDragon is created and instantiated with a name and hp
 ** using its parent and grandfather class functions.
 ** It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "BabyDragon.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Name: BabyDragon() - Default Constructor
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon() : Monster() 
{
  SetName(" ");
  SetHealth(0);
}

// Name: Baby Dragon(string name, int hp)
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon(string name, int hp) : Monster(name, hp)
{
  SetName(name);
  SetHealth(hp);
}

// Name: SpecialAttack
// Description: Defines the Baby Dragon's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int BabyDragon::SpecialAttack()
{
  int damage = 4;

  cout << GetName() << " breathes a cone of fire at you!" << endl;

  return damage; 
  
}
