/**************************************************************************
 ** File: proj2.cpp
 ** Project: CMSC 202 Project 2, Fall 2019
 ** Author: Blake Wishard
 ** Date: September 30, 2019
 ** Section: 21
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the main driver for the Foundable, Wizard, and Game 
 ** classes (Foundable.cpp, Wizard.cpp, Game.cpp). Also includes the
 ** Foundable.h, Wizard.h and Game.h header files
 ** the Game.h, Wizard.h, and Foundable.h Header files
 **************************************************************************/
#include <iostream> //imports iostream
#include <ctime>    //used for time function
#include <cstdlib> //used for rand

//allows proj2.cpp to access the functions, global constants,
//and private class objects in the Header file Foundable.h
#include "Foundable.h"

//allows proj2.cpp to access the functions, global constants,
//and private class objects in the Header file Wizard.h
#include "Wizard.h"

//allows Game.cpp to access the functions, global constants,
//and private member variables in the Header file Game.h
#include "Game.h"

using namespace std; //adds std:: to all commands in std

int main () {
  srand(time(NULL)); //seeds the random generator 
  Game();    //calls the Game Class Object, effectively creating a new game
  return 0;
}
