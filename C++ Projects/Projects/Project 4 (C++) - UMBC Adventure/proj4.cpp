/****************************************************************************
 ** File:    proj4.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** 
 ** This file is the main driver for project4. It includes the main(), 
 ** using the user inpute file name and calls the Game() overloaded constructor 
 ** in order to start the game
 ***************************************************************************/
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a room file to be loaded." << endl;
    cout << "Usage: ./proj2 map2_data.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string mapName = argv[1];
  srand (time(NULL));
  Game g(mapName);
  return 0;
}
