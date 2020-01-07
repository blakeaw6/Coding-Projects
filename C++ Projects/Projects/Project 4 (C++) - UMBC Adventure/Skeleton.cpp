/******************************************************************************
 ** File:    Skeleton.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Skeleton class and Skeleton.h header file.
 ** This class is a child class of Monster.cpp, and a grandchild class
 ** of Entity.cpp.
 ** In this class, a Skeleton is created and instantiated with a name and hp
 ** using its parent and grandfather class functions.
 **  It also includes the purely virtual function SpecialAttack()
 *****************************************************************************/
#include "Skeleton.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Skeleton::Skeleton() : Monster() 
{
  

}

// Name: Skeleton(string name, int hp)
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton(string name, int hp) : Monster(name, hp)
{
  

}


// Name: SpecialAttack
// Description: Defines the Skeleton's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Skeleton::SpecialAttack()
{
  int damage = 1;

  cout << GetName() << " bashes you withs it's own arm!" << endl;

  return damage;
}
