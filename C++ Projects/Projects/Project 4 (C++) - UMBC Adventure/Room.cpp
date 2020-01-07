/******************************************************************************
 ** File:    Room.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Room class and Room.h header file.
 ** In this class, a Room is created and instantiated with a room Id, room name,
 ** room description, room Id to Norht, East, South, and West. 
 ** This file includes getters and setters, a CheckDirection() function that 
 ** will return the room ID of the availabe rooms to move too, and -1 if there 
 ** is no exit in that direction. It also includes PrintRoom() that will output
 ** the room name, description, and possible exits.
 *****************************************************************************/
#include "Room.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Name: Room (Overloaded Constructor)
//Precondition: Must have valid input for each part of a room
//Postcondition: Creates a new room
Room::Room(int roomID, string roomName, string roomDesc, int roomIdToNorth,
	  int roomIdToEast, int roomIdToSouth, int roomIdToWest)
{
  m_ID = roomID;
  m_name = roomName;
  m_desc = roomDesc;
  //sets the room ID directions 
  m_direction[n] = roomIdToNorth;
  m_direction[e] = roomIdToEast;
  m_direction[s] = roomIdToSouth;
  m_direction[w] = roomIdToWest;  
}

//Name: GetName
//Precondition: Must have valid room
//Postcondition: Returns room name as string
string Room::GetName()
{
  return  m_name;
}

//Name: GetID
//Precondition: Must have valid room
//Postcondition: Returns room id as int
int Room::GetID()
{
  return m_ID;
}

//Name: GetDesc
//Precondition: Must have valid room
//Postcondition: Returns room desc as string
string Room::GetDesc()
{
  return m_desc;;
}

//Name: CheckDirection
//Precondition: Must have valid room
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the room in that direction
//Postcondition: Returns id of room in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection)
{
  if ((myDirection == 'N') || (myDirection == 'n'))
    {
      return m_direction[n];
    }

  else if ((myDirection == 'E') || (myDirection == 'e'))
    {
      return m_direction[e];
    }

  else if ((myDirection == 'S') || (myDirection == 's'))
    {
      return m_direction[s];

    }
  else if ((myDirection == 'W') || (myDirection == 'w'))
    {
      return m_direction[w];
    }
  else
    {
      return -1;
    }
}

//Name: PrintRoom
//Precondition: Room must be complete
//Postcondition: Outputs the room name, room desc, then possible exits
void Room::PrintRoom()
{
  cout << GetName() << endl;
  cout << GetDesc() << endl;
  
  cout << "Possible exits: ";

  for(int i = 0; i < 4; i++)
    {
      if(m_direction[i] != -1)
	{
	  switch(i)
	    {
	    case 0:
	      {
		cout << "N ";
	      }
	      break;
	    case 1:
	      {
		cout << "E";
	      }
	      break;
	      
	    case 2: 
	      {
		cout << "S";
	      }
	      break;

	    case 3:
	      {
		cout << "W";
	      }
	      break;
	    }
 
	}
    }
  cout << endl;
}
