/*****************************************************************************
 ** File:    Rogue.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the header file of the Rogue class
 *****************************************************************************/
#ifndef _ROGUE_H_
#define _ROGUE_H_

#include "Character.h"

class Rogue: public Character {
 public:
  // Name: Rogue() - Default Constructor
  // Description: Creates a new rogue
  // Preconditions: None
  // Postconditions: Can create a rogue
  Rogue();
  // Name: Rogue(string name, int hp)
  // Description: Creates a new rogue
  // Preconditions: None
  // Postconditions: Can create a rogue
  Rogue(string, int);
  // Name: ~Rogue - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Rogue();
  // Name: SpecialAttack
  // Description: Defines the Rogue's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
