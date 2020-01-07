/*****************************************************************************
 ** File:    Goblin.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the header file of the Goblin class
 *****************************************************************************/
#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "Monster.h" //Monster must be created first 

class Goblin: public Monster {
 public:
  // Name: Goblin() - Default Constructor
  // Description: Creates a new goblin
  // Preconditions: None
  // Postconditions: Can create a goblin
  Goblin();
  // Name: Goblin(string name, int hp)
  // Description: Creates a new goblin
  // Preconditions: None
  // Postconditions: Can create a goblin
  Goblin(string, int);
  // Name: SpecialAttack
  // Description: Defines the Goblin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
