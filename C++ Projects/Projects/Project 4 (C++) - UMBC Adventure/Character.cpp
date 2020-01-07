/******************************************************************************
 ** File:    Character.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Character class and the Character.h header file. 
 ** This class is a child class of Entity.cpp, and a parent class to Rogue.cpp, 
 ** Wizard.cpp, and Paladin.cpp. In this class, a Character is created and 
 ** instantiated with a name an hp using it's parent class functions.
 **  It also includes the purely virtual functions Attack() and SpecialAttack()
 *****************************************************************************/
#include "Character.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Name: Character() - Default Constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can create a character
Character::Character() : Entity() 
{
  SetName(" ");
  SetHealth(0);
}

// Name: Character(string name, int hp) - Overloaded constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can be used to populate character or child classes
Character::Character(string name, int hp) :  Entity(name, hp)
{
  SetName(name);
  SetHealth(hp);
}

// Name: ~Character - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Character::~Character()
{

}

// Name: Attack()
// Description: Describes attack statements for character
// Preconditions: None
// Postconditions: Returns damage
int Character::Attack()
{
  int damage = rand() % 7 + 1;

  cout << GetName() << " attacks dealing " << damage << " damage" << endl;
  
  return damage;
}

// Name: SpecialAttack()
// Description: Tells player that character does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
int Character:: SpecialAttack()
{
  cout << "Character does not have a special attack." << endl;
  cout << "You do not atack this turn." << endl;

  return 0;
}
