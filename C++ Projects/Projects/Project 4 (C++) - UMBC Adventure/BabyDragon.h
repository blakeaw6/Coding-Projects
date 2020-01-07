/*****************************************************************************
 ** File:    BabyDragon.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the header file of the BabyDragon class
 *****************************************************************************/
#ifndef _BABYDRAGON_H_
#define _BABYDRAGON_H_

#include "Monster.h" //Monster must be created first 

class BabyDragon: public Monster {
 public:
  // Name: BabyDragon() - Default Constructor
  // Description: Creates a new baby dragon
  // Preconditions: None
  // Postconditions: Can create a baby dragon
  BabyDragon();
  // Name: Baby Dragon(string name, int hp)
  // Description: Creates a new baby dragon
  // Preconditions: None
  // Postconditions: Can create a baby dragon
  BabyDragon(string, int);
  // Name: SpecialAttack
  // Description: Defines the Baby Dragon's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
