/*****************************************************************************
 ** File:    Wizard.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the header file of the Wizard class
 *****************************************************************************/
#ifndef _WIZARD_H_
#define _WIZARD_H_

#include "Character.h"

class Wizard: public Character {
 public:
  // Name: Wizard() - Default Constructor
  // Description: Creates a new wizard
  // Preconditions: None
  // Postconditions: Can create a wizard
  Wizard();
  // Name: Wizard(string name, int hp)
  // Description: Creates a new wizard
  // Preconditions: None
  // Postconditions: Can create a wizard
  Wizard(string, int);
  // Name: ~Wizard - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Wizard();
  // Name: SpecialAttack
  // Description: Defines the Wizard's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
