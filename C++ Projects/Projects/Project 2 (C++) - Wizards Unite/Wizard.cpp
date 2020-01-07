/**************************************************************************
 ** File: Wizard.cpp
 ** Project: CMSC 202 Project 2, Fall 2019
 ** Author: Blake Wishard
 ** Date: September 30, 2019
 ** Section: 21
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the Wizard Class and includes
 ** the Wizard.h and Foundable.h Header files
 ** 
 ** In the Wizard Class, a new Wizard is created with a user inputted name,
 ** a random toughness value between 150-300, a level of one, and zero 
 ** wins and losses. The CheckFoundable() function is included in this Class, 
 ** allowing the user to check to see if they have already defeated a certain 
 ** Foundable and added it to m_foundables. The InsertFoundable() function 
 ** copies the Foundable defeated from m_allFoundables to m_foundables.
 ** The AttackFoundable() function will attack a random Foundable of a 
 ** user specified rarity (1-5) and compare the Wizard's toughness to the 
 ** Foundables toughness, with the Wizard defeating the Foundable if it has a 
 ** greater toughness. The IncreaseLevel() function will be use to update the 
 ** Wizard's level every time they defeat a Foundable from level 1 to 
 ** level 192, the total number of Foundables in m_allFoundables
 **************************************************************************/

//allows Wizard.cpp to access the functions, global constants,
//and private member variables in the Header file Wizard.h 
#include "Wizard.h"

//allows Wizard.cpp to access the functions, global constants,
//and private class objects in the Header file Foundable.h
#include "Foundable.h"

#include <iostream> //imports iostream
#include <string> //imports string library 
using namespace std; //adds std:: to all the commands in std

//default constructor
Wizard::Wizard()
{
  m_name = " ";
  //intiatlizes the starting m_toughness value to a random number
  //between 150 and 300
  m_toughness = (rand() % (MAX_START_TOUGH + 1 - MIN_START_TOUGH))
                +MIN_START_TOUGH;
  //initializes the starting level to 1;
  m_level = 1;
  m_wins = 0;
  m_losses = 0; 
}
//overloaded constructor
Wizard::Wizard(string name)
{
  //updates the value of m_name with the passed name 
  m_name = name;
  m_wins = 0;
  m_losses = 0;
  m_level = 1;
  m_toughness = (rand() % (MAX_START_TOUGH + 1 - MIN_START_TOUGH))
                +MIN_START_TOUGH;
}

//returns m_name
string Wizard::GetName()
{
  return m_name;
}

//returns m_toughness
int Wizard::GetToughness()
{
  return m_toughness;
}

//returns m_level
int Wizard::GetLevel()
{
  return m_level;
}

//returns m_wins
int Wizard::GetWins()
{
  return m_wins;
}

//returns m_losses
int Wizard::GetLosses()
{
  return m_losses;
}

//updates the value of m_ name
void Wizard::SetName(string name)
{
  m_name = name;
}

//checks to make sure that starting toughness is between
//150-300 and then updates the value of m_toughness
void Wizard::SetToughness(int toughness)
{
  if (toughness >= MIN_START_TOUGH && toughness <= MAX_START_TOUGH)
    {
      m_toughness = toughness;
    }
}

//In Game.cpp, this function will only be called if the
//AttackFoundables() function returns false - thus indicating that
//the Wizard defeated the enemy Foundable.
//It calls CheckFoundable() with a parameter of the newFoundable.
//If that Foundable already exists in m_foundables,
//CheckFoundables(newFoundable) returns true, and this function is not run.
//Else, adds a copy of newFoundable to m_foundables.
void Wizard::InsertFoundable(Foundable newFoundable)
{
  if(!CheckFoundable(newFoundable))
    {
      m_foundables[m_level] = newFoundable; //adds a copy of newFoundable to
                                            //m_foundables
      m_wins++;         //updated the m_wins counter by 1
      IncreaseLevel();  //increases the wizard's level by 1
    }
}

//checks to see if there is already a Foundable in m_foundables
//with the same name, type, rarity and toughness values. Returns true if
//aready exists in m_foundables, else false
bool Wizard::CheckFoundable(Foundable newFoundable)
{
  for (int i = 0; i < m_level; i++)
    {
      if ((m_foundables[i].GetName() == newFoundable.GetName()) &&
	  (m_foundables[i].GetType() == newFoundable.GetType()) &&
	  (m_foundables[i].GetRarity() == newFoundable.GetRarity()) &&
	  (m_foundables[i].GetToughness() == newFoundable.GetToughness()))
        return true;
    }
  
  return false;	   
}
	  
//In Game.cpp, AttackFoundables() is only called if CheckFoundables() returns
//false - thus indicating that the Foundable is not already in m_foundables.
//If CheckFoundables() is false, it will compares Wizard toughness to the
//enemy(Foundable pointer) toughness, and returns true if the Wizard
//toughness is less than or equal to the enemy's toughness. Additionally,
//it will increase the loss count by 1. Else, returns false -
//indicating the Wizard successfullly defeated the enemy.
bool Wizard::AttackFoundable(Foundable enemy)
{
  
  int enemyToughness = enemy.GetToughness(); //stores the value of the enemy's
                                             //toughness in enemyToughness

  //checks to see if the enemy toughness value is greater
  //than or equal to m_toughness
  if (m_toughness <= enemyToughness)
    {
      m_losses++;  //updates loss count by 1
      return true;
    }

  return false;     
}

//Displays a numbered and formatted list of every Foundable defeated by
//the Wizard and added to m_foundables. Else, indicates none found.
void Wizard::PrintMyFoundables()
{
  cout << endl;
  //checks to make sure that m_level has been updated at least one time -
  //thus indicating that the Wizard has defeated at least one Foundable.
  if (GetLevel() > 1)
    {
      for (int i = 1; i < m_level; i++)
	{
	  cout << i << ". " << m_foundables[i].GetName() << "| ";
	  cout << m_foundables[i].GetType() << "| ";
	  cout << m_foundables[i].GetRarity() << "| ";
	  cout << m_foundables[i].GetToughness() << endl;
	  cout << endl;
	}
    }
  else
    {
      cout << "None Found.\n";
    }
}

//Updates m_level by one and increases toughness to a random
//value ranging from 0 to 100
void Wizard::IncreaseLevel()
{
  m_level += 1;
  m_toughness += rand() % LEVEL_TOUGH_INCREASE; 
}

  

