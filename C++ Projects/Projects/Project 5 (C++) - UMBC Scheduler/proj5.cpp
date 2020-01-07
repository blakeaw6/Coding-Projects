/*****************************************************************************
 ** File:    proj5.cpp
 ** Project: UMBC Scheduler, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/15/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the main driver for project 5
 *****************************************************************************/
#include "Scheduler.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//main - makes sure the user enters a .txt file to be run with the project
//prompts the user to enter a .txt file if they do not when they run the program
int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a roster file to be loaded." << endl;
    cout << "Usage: ./proj5 proj5_test1.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string rosterFile = argv[1];
  Scheduler s(rosterFile);
  s.Start(); //calls Start() and begins the program
  return 0;
}
