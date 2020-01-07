/******************************************************************************
 ** File:    Game.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/3/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Game class and Game.h header file.
 ** This class manages the entire game. It includes the LoadMap() function 
 ** which is passed a paramter of the file name to load the .txt file. It has 
 ** a CharacterCreation() function that allows the user to choose a character
 ** they wish to play as. It has a StartGame() function that sets the starting
 ** room to 0 and calls Action(). The Action() function starts the game 
 ** and runs until the user quits or the player dies. The RandomMonster() 
 ** function creates a dynamically allocated monster, with a 25% chance 
 ** of one of the three monsters to be present in a new room the user moves
 ** into. The Attack() function is used for the user and monster to attack 
 ** each other. The Stats() function displays the stats of the character, 
 ** including the name, remaining rests, and remaining special attacks.

 *****************************************************************************/
#include "Game.h"

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: After asking for a file name, loads map, creates char
//and starts			  
Game::Game()
{
  //initializes private member variables to 0 or NULL
  m_myCharacter = NULL;
  m_curRoom = 0;
  m_curMonster = NULL;
  m_numRests = 0;
  m_numSpecial = 0;
}

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Uses filesname to LoadMap, calls create character,
// and sets both numRests and m_numSpecial using constants.
Game::Game(string fileName)
{
  //initializes private member variables to 0 or NULL 
  m_myCharacter = NULL;
  m_curRoom = 0;
  m_curMonster = NULL;
  
  //initializes private member variables to their global contant values
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;

  //calls LoadMap(), passing it the desired filename, and calls
  //CharacterCreation() to choose and create a new character 
  LoadMap(fileName);
  CharacterCreation();
}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game()
{


}

// Name: LoadMap(string fileName)
// Description: Dynamically creates rooms and inserts them into the m_myMap ve\
ctor
// Precondition: File contains map information
// Postcondition: Map is populated with Room objects.
void Game::LoadMap(string fileName)
{
  int count = 0;

  //declares all Room paramters as strings, including variables that will only
  //temporarily be strings 
  string tempRoomId;
  string roomName;
  string roomDesc;
  string tempRoomIdNorth;
  string tempRoomIdEast;
  string tempRoomIdSouth;
  string tempRoomIdWest;

  //declares ints of the Room parameters, that the temporary strings will be
  //converted too 
  int roomId;
  int roomIdNorth;
  int roomIdEast;
  int roomIdSouth;
  int roomIdWest; 

  //creates inputStream and opens file for reading 
  ifstream inputStream;
  inputStream.open(fileName);

  //while loop that will read in data from the .txt file as long as these 7
  //values are in a row and contained in the .txt file
  while (getline(inputStream, tempRoomId, '|' ))
    {
      getline(inputStream, roomName, '|');
      getline(inputStream, roomDesc, '|');
      getline(inputStream, tempRoomIdNorth, '|');
      getline(inputStream, tempRoomIdEast, '|');
      getline(inputStream, tempRoomIdSouth, '|');
      getline(inputStream, tempRoomIdWest, '|');
      //if the next character is a new line character, ignore it
      if(inputStream.peek() == '\n')
	inputStream.ignore(); 

      //converts the temporary string variables back to their intended
      //int values 
      roomId = atoi(tempRoomId.c_str());
      roomIdNorth = atoi(tempRoomIdNorth.c_str());
      roomIdEast = atoi(tempRoomIdEast.c_str());
      roomIdSouth = atoi(tempRoomIdSouth.c_str());
      roomIdWest = atoi(tempRoomIdWest.c_str());

      //creats a new room and passes it parameters of all the read in values
      //from the text file 
      Room *newRoom = new Room(roomId, roomName, roomDesc, roomIdNorth,
			       roomIdEast, roomIdSouth, roomIdWest); 

      //adds the new room to the end ofthe vector list
      m_myMap.push_back(newRoom);      	
    }
  //closes the inputStream
  inputStream.close();
}

// Name: CharacterCreation()
// Description: Allows user to create a new character (or child) to play with.\
// May be either character, paladin, rogue, or wizard.
// Preconditions: None
// Postconditions: m_myCharacter is populated
void Game::CharacterCreation()
{
  string charName;

  //welcomes the user to the game and prompts them to enter their name
  cout << "Welcome to UMBC Adventure!" << endl;
  cout << "Character Name: ";
  cin >> charName;

  int classChoice = 0;

  //error checking while loop that asks the user to choose their desired class
  //to play the game as 
  while(classChoice < 1 || classChoice > 4)
    {
      cout << endl;
      cout << "Select a class" << endl;
      cout << "1. Rogue" << endl;
      cout << "2. Wizard" << endl;
      cout << "3. Paladin" << endl;
      cout << "4. No Class" << endl;
      cin >> classChoice;
      cout << endl;
    }

  //switch function that will create a new Rogue, Wizard, Paladin, or
  //generic Character to play the game as. Passes the inputed name, and the
  //constant value for health of that character
  switch(classChoice)
    {
    case 1:
      {
	m_myCharacter = new Rogue(charName, ROGUE_HEALTH);

      }
      break;
    case 2:
    {
      m_myCharacter = new Wizard(charName, WIZARD_HEALTH);
    }
    break;
    
    case 3:
      {
	m_myCharacter = new Paladin(charName, PALADIN_HEALTH);
      }
      break;
    case 4:
      {
	m_myCharacter = new Character(charName, 10);
      }
      break;
    }

  StartGame(); //calls StartGame()         
}

//Name: StartGame()
//Description: After LoadMap and CharacterCreation, current room
//set (0 by default) and Action is called
//Preconditions: LoadMap and CharacterCreation must have been completed
//Postconditions: m_numRests, m_numSpecial and curRoom populated and action c\
alled
void Game::StartGame()
{
  m_myMap.at(m_curRoom)->PrintRoom(); //displays the room information
  m_curRoom = 0;                      //sets the first room as 0
  m_numRests = NUM_RESTS;             //sets the number of rests available
  m_numSpecial = NUM_SPECIAL;         //sets the number of special attacks
                                      //available
  RandomMonster();                    //has a 25% chance to spawn one of the
                                      //three random monsters in the room, 
                                      //or create an empty room with no monster
  Action();                           //calls the action menu
}

// Name: Action()
// Description: Menu for game
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action()
{
  cout << endl;

  int choice = 0;

  //boolean variable that is used to run the game and prompt the menu
  bool running = true;

  //do-while loop that will display the menu until the user has been defeated
  //or if the user quits the game using 6, and sets the boolean value to false 
  do
    {
      //error checking while loop that will display a menu prompting the
      //user to enter what they would like to do, will continue to display
      //if the inputed value is less than 1 or greater than 6
      while (choice < 1 || choice > 6)
      {
	cout << "What would you like to do?\n";
	cout << "1. Look" << endl;
	cout << "2. Move" << endl;
	cout << "3. Attack Monster" << endl;
	cout << "4. Rest" << endl;
	cout << "5. Check Stats" << endl;
	cout << "6. Quit" << endl;
	cin >> choice;
      }

      //switch statement that will the functions the user chooses in the menu,
      //and will reset the choice to 0
    switch(choice)
      {
	//prints the current room
      case 1:
	{
	  cout << endl;
	  m_myMap.at(m_curRoom)->PrintRoom();
	  cout << endl;
	  choice = 0;
	}
	break;

	//moves the character to a new room
      case 2:
	{
	  Move();
	  choice = 0;
	}
	break;
	
	//attacks the monster 
      case 3:
	{
	  Attack();
	  choice = 0;
	}
	break;

	//rest(if available) and heals the character back to its starting health
      case 4:
	{
	  if (m_curMonster != NULL)
	    {
	      cout << "You cannot rest with a monster in the room!" << endl;
	      cout << endl;
	      choice = 0;
	    }
	  else if (m_numRests != 0)
	    {
	      m_myCharacter->SetHealth(REST_HEAL);
	      m_numSpecial = NUM_SPECIAL;
	      m_numRests--;
	      cout << endl << "Resting..." << endl;
	      choice = 0; 
	    }
	  else
	    {
	      cout << "No rests remaining!" << endl;
	      choice = 0;
	    }
	  cout << endl;
	}
	break;

	//displays the character stats 
      case 5:
	{
	  Stats();
	  choice = 0;
	}
	break;

	//exits the program 
      case 6:
	{
	  cout << "Goodbye!" << endl;
	  running = false;
	}
	break;
	
      }//end switch
    }
  while((running) && (m_myCharacter != NULL)); //do while loop runs
                                                        //as long as bool value
                                                        //is true and character
                                                        //is not equal to NULL
  //deallocates m_myCharacter, sets it equal to NULL
  if(m_myCharacter != NULL)
    {
     delete m_myCharacter;
     m_myCharacter = NULL;
    }
  //if there is still a monster in m_curMonster, deallocates m_curMonster and
  //sets it equal to NULL 
  if (m_curMonster != NULL)
    {
      delete m_curMonster;
      m_curMonster = NULL;
    }

  //uses an unsigned int of the size of the amount of rooms in m_myMap,
  //iterates through and deletes each room in the vector 
  unsigned int vectorSize = m_myMap.size(); 
  for(unsigned int i  = 0; i < vectorSize; i++)
    {
      delete m_myMap.at(i);
      m_myMap.at(i) = NULL;
    }	  
}

// Name: RandomMonster()
// Description: Used to randomly create a dynamically allocated monster
//of Baby Dragon, Goblin, or Skeleton
// Preconditions: Has an entity pointer to hold monster child
// Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
Entity* Game::RandomMonster()
{
  //has a 25% chance to create and spawn one of the random monsters,
  //or leave the rooom empty without a monster
  int monsterNum = rand() % 4 + 1;

  //switch statement that will create as new monster and insert it
  //to m_curMonster, or leave the room empty and peaceful 
  switch(monsterNum)
    {
    case 1:
      {
	m_curMonster = new BabyDragon("Baby Dragon", DRAGON_HEALTH);
	cout << "A baby dragon is here practicing fire-breathing" << endl;
      }
      break;
    case 2:
      {
	m_curMonster = new Skeleton("Skeleton", SKELETON_HEALTH);
	cout <<  "A skeleton lumbers around the the room" << endl;
      }
      break;
    case 3:
      {
	m_curMonster = new Goblin("Goblin", GOBLIN_HEALTH);
	cout << "A goblin is here picking his nose" << endl;
      }
      break;
    case 4:
      {
	cout << "It is peaceful here." << endl;      
      }
      break;
    }//end switch
	
  return 0;
}

// Name: Move
// Description: Moves a player from one room to another (updates m_curRoom)
// Preconditions: Must be valid move (room must exist)
// Postconditions: Displays room information, checks for new monster (deletes \
old)
void Game::Move()
{
  //if there is a monster in m_curMonster, deallocates the memory and sets
  //m_curMonster equal to NULL
  if (m_curMonster != NULL)
    {
      delete m_curMonster;
      m_curMonster = NULL;
    }

  //creates a char for direction and an int for invalid direction
  char direction;
  int roomChangeNum = -1;

  //do while loop that asks the user which direction they would like to move,
  //will continue to ask the user until they select a valid room to move into.
  //uses CheckDirection() passing it the parametes of the selected direction
  //to make sure there is a room available in that direction to move into
  do
    {
      cout << endl;
      cout << "Which direction? (N E S W)" << endl;
      cin >> direction;
      roomChangeNum = m_myMap.at(m_curRoom)->CheckDirection(direction);
    }while(roomChangeNum == -1);
  cout << endl;
  //changes the room to the room in the selected direction 
  m_curRoom = roomChangeNum; 
  RandomMonster(); //spawns a random monster in that room or not 
  m_myMap.at(m_curRoom)->PrintRoom(); //prints that room information  
}

// Name: Attack
// Description: Allows player to attack an enemy entity.
// Preconditions: Must have enemy monster in room
// Postconditions: Indicates who wins and updates health(hp) as battle
//continues.
//May need to deallocate enemy monster to prevent memory leaks
void Game::Attack()
{

  //checks to see if there is a monster in m_curMonster, if so then deletes
  //that monster 
  if (m_curMonster == NULL)
    {
      cout << endl;
      cout << "Room is empty. No monster available to attack!" << endl;
      Action();
    }
  //attacks the monster 
  else
    { //while loop that runs and prompts the user what type of attack they
      //would like to perform on the monster, as long as the character's
      //health is greater than zero and the m_curMonster is not equal to NULL
      while ((m_myCharacter != NULL) && (m_curMonster != NULL))  
      {
	int choice = 0;
	while (choice < 1 || choice > 2)
	  {
	    cout << endl;
	    cout << "1. Normal Attack" << endl;
	    cout << "2. Special Attack" << endl;
	    cin >> choice;
	  }
      cout << endl;

      int characterDamage = 0;
      int monsterDamage = 0;
      int specialRemaining = m_numSpecial;

      //runs if user selects 1. Normal Attack
      if (choice == 1)
	{
	  characterDamage = m_myCharacter->Attack();
	}
      //runs if user selects 2. Special attack, and the user has at least
      //one special attack remaining.
      else if (choice == 2 && specialRemaining > 0)
	{
	  characterDamage = m_myCharacter->SpecialAttack();
	  m_numSpecial--;
	}
      //if no special attacks remaining, re-calls Attack(); 
      else
	{
	  cout << "No special attacks remaining!" << endl;
	  Attack(); 
	}

      //generates a 25% chance for the monster to use a special attack 
      int monsterAttack = rand() % 4 + 1;

      //if 4 is generated, have the monster use a SpecialAttack()
      if (monsterAttack == 4)
	{
	  monsterDamage = m_curMonster->SpecialAttack();
	}
      //else, the monter uses a normal Attack() 
      else
	{
	  monsterDamage = m_curMonster->Attack();
	}

      //stores the current value of the character and monster's health before
      //the attack damage is taken
      int curCharacterHealth = m_myCharacter->GetHealth();
      int curMonsterHealth = m_curMonster->GetHealth();

      //sets the character's and monster's health to their current health value
      //minus the value of attack damage taken
      m_myCharacter->SetHealth(curCharacterHealth - monsterDamage);
      m_curMonster->SetHealth(curMonsterHealth - characterDamage);

      //if the user's health goes below 1, he has been defeated and the game is
      //over and the game exits
      if (m_myCharacter->GetHealth() <= 0)
	{
	  cout << "You have been defeated." << endl << "Game Over." << endl;
	
	  delete m_myCharacter;
	  m_myCharacter = NULL;
	}

      //if the monster's health is less than 1, it has been defeated and
      //the monster is deallocated and set equal to NULL
      else if (m_curMonster->GetHealth() <= 0)
	{
	  cout << "You have defeated the " << m_curMonster->GetName()
	       << "." <<  endl;
	  
	  //deallocates monster, sets it equal to NULL, and calls Action()
	  delete m_curMonster;
	  m_curMonster = NULL;
	  Action();
	 
	}
      //if after both the character and the monster attack each other, neither
      //is defeated, it will display the name and remaining health of the
      //character and monster 
      else
	{
	  cout << endl;
	  cout << m_myCharacter->GetName() << "'s health: "
	       << m_myCharacter->GetHealth() << endl;
	  
	  cout << m_curMonster->GetName() << "'s health: "
	       << m_curMonster->GetHealth() << endl;
	}
      }
    }
}

// Name: Stats()
// Description: Displays the information about the player (name, hp, rests, sp\
ecials)
// Preconditions: None
// Postconditions: None
void Game::Stats()
{
  //uses the Entity classes overloaded << operator function to display the
  //statistics of the character- name, rests, and special's remaining
  cout << endl;
  cout << *m_myCharacter;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
  cout << endl;
  
}
