/*****************************************************************************
 ** File:    Monster.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the header file of the Monster class
 *****************************************************************************/
#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Entity.h" //Entity class must be created first 

class Monster: public Entity {
 public:
  // Name: Monster() - Default Constructor
  // Description: Would be used to create a monster but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Monster();
  // Name: Monster(string name, int hp) - Overloaded Constructor
  // Description: Would be used to create a monster but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Monster(string, int);
  // Name: Attack()
  // Description: Describes attack statements for monster
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack()=0;
};
#endif
