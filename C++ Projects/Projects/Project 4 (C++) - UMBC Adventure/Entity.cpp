/****************************************************************************
 ** File:    Entity.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard 
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Entity class and the Entity.h header file
 ** In this file, an Entity object is created. It is the Parent class of
 ** Character.cpp and Monster.cpp, and the Grandfather class of Rogue.cpp, 
 ** Wizard.cpp, Paladin.cpp, Skeleton.cpp, Goblin.cpp, and BabyDragon.cpp.
 ** An Entity is created and instatiated with a name and a starting health(hp). 
 ** Additionally, it includes an overloaded << operator used to print the 
 ** stats of the Entity in Game.cpp. The Entity.h header file inluces two 
 ** purely virual functions that are found in its child and grandchild classes.
 ***************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include "Entity.h" //includes the Entity.h header file 
using namespace std;

// Name: Entity() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (not specifically\
 used)
Entity::Entity()
{
  m_name = " ";
  m_health = 0;
  m_level = 0; 
}

// Name: Entity(string, int) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes
Entity::Entity(string name, int hp)
{
  m_name = name;
  m_health = hp;
}


// Name: virtual ~Entity - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Entity::~Entity()
{

}

// Name: GetName()
// Description: Returns name of entity
// Preconditions: Entity has name
// Postconditions: None
string Entity::GetName()
{
  return m_name;
}


// Name: GetHealth()
// Description: Returns health of entity
// Preconditions: Entity has health
// Postconditions: None
int Entity::GetHealth()
{
  return m_health;
}

// Name: SetName()
// Description: Sets name of entity
// Preconditions: None
// Postconditions: Name is set
void Entity::SetName(string name)
{
  m_name = name;
}

// Name: SetHealth()
// Description: Sets health of entity
// Preconditions: None
// Postconditions: Health is set
void Entity::SetHealth(int health)
{
  m_health = health;
}

// Name: Overloaded <<
// Description: Prints the details of an entity
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of entity
ostream& operator<<(ostream& os, Entity& ent)
{
   os << "Name: " << ent.GetName() << endl << "HP: " << ent.GetHealth() << endl;
   return os;
}



