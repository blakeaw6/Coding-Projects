/**************************************************************************
 ** File: Foundable.cpp
** Project: CMSC 202 Project 2, Fall 2019
 ** Author: Blake Wishard
 ** Date: September 30, 2019
 ** Section: 21
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the Foundable Class and includes 
 ** the Foundable.h Header file
 ** This class is used to create and store, and access the name, type
 ** rarity, and toughness attributes for each of the 192 Foundables.
 **************************************************************************/

//allows Foundable.cpp to access the functions, global constants,
//and private member variables in the Header file Foundable.h
#include "Foundable.h"

//default constructor
Foundable::Foundable()
{
  SetName(" ");
  SetType(" ");
  SetRarity(0);
  SetToughness(0);
}

//overloaded constructor - creates new Foundable with passed data
Foundable::Foundable(string name, string type, int rarity, int toughness)
{
  SetName(name);
  SetType(type);
  SetRarity(rarity);
  SetToughness(toughness);
}

//returns m_name
string Foundable::GetName()
{
  return m_name;
}

//returns m_type
string Foundable::GetType()
{
  return m_type;
}

//returns m_rarity
int Foundable::GetRarity()
{
  return m_rarity;
}

//returns toughness
int Foundable::GetToughness()
{
  return m_toughness;
}

//updates the value of m_name
void Foundable:: SetName(string name)
{
  m_name = name;
}

//updates the value of m_type
void Foundable::SetType(string type)
{
  m_type = type;      
}

//checks to make sure rarity is between 1-5 and then updates
//the value of m__rarity
void Foundable::SetRarity(int rarity)
{
  if(rarity > 0 && rarity <= 5)
    {
      m_rarity = rarity;
    }
}

//checks to make sure toughnes is an int greater than zero
//and then updates m_toughness
void Foundable::SetToughness(int toughness)
{
  if (toughness > 0)
    {
      m_toughness = toughness;
    }  
}
