/**************************************************************************
 ** File: Game.cpp
 ** Project: CMSC 202 Project 2, Fall 2019
 ** Author: Blake Wishard
 ** Date: September 30, 2019
 ** Section: 21
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the Game class and includes
 ** the Game.h, Wizard.h, and Foundable.h Header files
 ** In the Game.cpp class, a new game will start, welcome the user,
 ** and prompt them for their Wizard's name. It will then load all 192 
 ** Foundables from proj2.txt into a Foundable object called m_allFoundables. 
 ** While the Wizard's level is less than the amount of Foundables (192), 
 ** the Main Menu will be displayed, prompting the user to make a choice of 
 ** 1-5, depending on their desired action. The user can display their Wizard
 ** information, display  a list of all their defeated Foundables, display
 ** a list of all 192 Foundables, Attack a Foundable, or exit the game.
 ** Once the user has attacked and defeated all 192 Foundables, a message 
 ** will be displyed informing the user that they have won, and prompting them
 ** to enter a 'y' if they would like to play again.  
 **************************************************************************/

//allows Game.cpp to access the functions, global constants,
//and private member variables in the Header file Game.h
#include "Game.h"

//allows Game.cpp to access the functions, global constants,
//and private class objects in the Header file Wizard.h
#include "Wizard.h"

//allows Game.cpp to access the functions, global constants,
//and private class objects in the Header file Foundable.h
#include "Foundable.h"

#include <iostream> //imports iostream
#include <fstream> //allows use of filestream 
#include <string>  //imports string class
#include <iomanip> //used for setting precision after the decimal place 
using namespace std; //adds std:: to all commands in std

//default constructor
Game::Game()
{
  //creates a boolean value that is used to start the game,
  //or play again if the user wants to once they win
  bool running = true;

  //while loop that will start/restart the game if the boolean value of
  //running is true
  while (running)
    {
      cout << endl;
      cout << "Welcome to Harry Potter: Wizards Unite\n";

      //loads all of the Foundables in proj2.txt to m_allFoundables,
      //formatted correctly 
      LoadFoundables();

      //if statment that will run if LoadFoundables() successfuly
      //works and loads all 192 Foundables into m_allFoundables
      cout << LoadFoundables() << " Foundables loaded\n" << endl;
	

      //calls the GetWizardName() function, which will
      //prompt the user to enter their Wizard nam
      GetWizardName();

      //do-while loop that will continue to run and call the MainMen()
      //function as long as the Wizard level is less than 192
      do
      {
	MainMenu();

      }while(m_wizard.GetLevel() < NUM_FOUNDABLE);

      //if statment that will run if the Wizard reaches level 192,
      //and will prompt the user to enter 'y' if they wish to play again,
      //else, ends the game
      if (m_wizard.GetLevel() ==  NUM_FOUNDABLE)
	{
	  cout << "Congratultation you've reached level " << NUM_FOUNDABLE
	       << " and won the game!\n";
	  cout << "Play again? (y/n)\n";
	  char answer;
	  cin >> answer;
	  cin.ignore(256, '\n');
	  running = answer == 'y';
	}
    }//end while
  
}//end Game

//prompts the user to enter their Wizard name, calls the SetName()
//function in the Wizard class, effectively updating the value of
//m_name for the Wizard
void Game::GetWizardName()
{
  string name;
  cout << "What is your wizard's name?\n";
  getline(cin, name); //allows the user to enter a name with a space
  
  m_wizard.SetName(name); //calls the SetName() function in the Wizard class,
                          //effectively updating hte value of m_name
  cout << endl;
}

//loads all 192 Foundables in proj2.txt into m_allFoundables
int Game::LoadFoundables()
{
  bool load;
  string name;
  string type;
  int rarity;
  int toughness;
  ifstream myFile(FILE_NAME); //declares and opens file

  char delimiter = ',';      //declares and initializes a char
  //called delimiter to account fo the commas
  //in the proj2.txt file

  int counter = 0;           //declares and initializes a counter
  //to get the amount of Foundables loaded
  //into m_allFoundables from proj2.txt

  //checks to see if the file exits and then loads all of the Foundables
  //into m_allFoundables
  if (myFile.is_open())
    {
      //for loop that will iterate between 0 and 192,
      //reading every line of Foundables and correctly formatting
      //and storing them into m_allFoundables
      for (int i = 0; i < NUM_FOUNDABLE; i++)
	{
	  //for string name and string type, uses getline() function
          //account for the comma and correctly insert the name and type
  	  //attributes of the Foundable into m_allFoundables
	  getline(myFile, name, delimiter);
	  getline(myFile, type, delimiter);

          //For int rarity, uses the insertion operator, .peek(), and
	  //.ignore() functions to look for and ignore following commas
	  myFile >> rarity;
	  if(myFile.peek() == ',')
	  myFile.ignore();

	  //for the int toughness, uses the insertion operator, .peek() and
	  //.ignore() function to loof for and ignore and following newline
	  //in order to read and add the next Foundable's name after the
	  //previous Foundable's toughness has been added to m_allFoundables
	  myFile >> toughness;
	  if(myFile.peek() == '\n')
	  myFile.ignore();

	  //stores the Foundable and it's attributes in m_allFoundables
	  m_allFoundables[i] = Foundable(name, type, rarity, toughness);
	  //increases the count for the amount of Foundables loaded
	  counter++;
	}
	  //returns the number of Foundables loaded
	  return counter;
	}
      return false;
    }

//the MainMenu() function that will run as long as the Wizard level
//is less than 192. Prompts the user to enter an option 1-5, depending
//on what action they wish to take
void Game::MainMenu()
{
  int choice = 0;
  while(choice < 1 || choice > 5)
  {
   cout << "What would you like to do?\n";
   cout << "1. Wizard information\n";
   cout << "2. List My Foundables\n";
   cout << "3. List All Foundables\n";
   cout << "4. Attack Foundable\n";
   cout << "5. Quit\n";
   cin >> choice;
   }
   
  //switch stament that will run the case that matches the use inputed choice. 
  switch(choice)
   {
     //calls the WizardStat() function, with prints the Wizard statistics-
     //name, level, toughness, foundables found, wins, losses, and win rate
     case 1:
      {
	WizardStat(); 
      }
     break;
      
     //calls the PrintMyFoundables() function and displays the Foundables
     //that are copied into m_foundables, once they are defeated
     //by the Wizard
     case 2:
      {
	PrintMyFoundables();
      }
      break;
      
     //calls the PrintFoundables() function and displays all 192
     //Foundables that are loaded in m_allFoundables
     case 3:
      {
	PrintFoundables();
      }
     break;

     //calls the AttackFoudnable() function, which will compare the
     //Wizard toughness to the enemy toughness, and return false if
     //the Wizard toughness is greater than the enemy toughness 
     case 4:
     {
       AttackFoundable();
     }
     break;

     //exits the program
     case 5:
     {
       exit(0);
     }

     //this should never run because the choice will always be
     //validated to be between 1-5 before the MainMenu() function
     //is run 
     default:
      {
	cout << "error in menu. this should never be displayed\n";
      }
     break;
  }
}

//AttackFoundable() function will attack a Foundable of a specific rarity,
//and calls the CheckFoundable() function to make sure that foundable
//has not already been defeated and added to m_foundables
void Game::AttackFoundable()
{
  Foundable enemy;  //Declares a new Foundable object called enemy
  Foundable newFoundable; //Declares a new Foundable object called newFoundable

  //Declares and initializes 4 new arrays of type string, string, int
  //and int that will be used to temporarily hold all the Foundables
  //of a specific rarity
  string nameArr[NUM_FOUNDABLE] = {" "};
  string typeArr[NUM_FOUNDABLE] = {" "};
  int rarityArr[NUM_FOUNDABLE] = {0};
  int toughnessArr[NUM_FOUNDABLE] = {0};
  int choice = 0;
  
  //do-while loop that prompts the user to enter what rarity of
  //Foundable they wish to attack. Will  run as long as the user enters
  //an integer that is less than 1 or greater than 5.
  do {
    cout << endl;
    cout << "What rarity of Foundable would you like to challenge (1-5)?"
	 <<endl;
    cin.clear();
    cin.ignore();
    cin >> choice;

  }while(choice < 1 || choice > 5);

  
   int size = 0; //size counter that will be used to store the size of
                 //the total amount of Foundables in m_allFoundables that
                 //are of the user's chosen rarity

   //for loop that will temporarily store the name, type, rarity, and
   //toughness values of all the Foundables in m_allFoundables that are
   //of the user's chosen rarity
   for (int i = 0; i < NUM_FOUNDABLE; i++)
    {
   if (m_allFoundables[i].GetRarity() == choice)
     {
       //adds the name, type, rarity, and toughness values in m_allFoundables
       //to the cooresponding arrays
       nameArr[size] += m_allFoundables[i].GetName();
       typeArr[size] += m_allFoundables[i].GetType();
       rarityArr[size] += m_allFoundables[i].GetRarity();
       toughnessArr[size] += m_allFoundables[i].GetToughness();
       size++; //increment the total size counter		
      }
    }

   //declares and initializes a random integer that is between 0
   //and the total size of all Foundables of the user's chosen rarity
   int randNum; 
   randNum = rand() % size;

   //declares and initializes name, type, rarity, and toughness values
   //that will be used to temporarily store the newFoundable attributes
   string name = " ";
   string type = " ";
   int rarity = 0;
   int toughness = 0;

   //for loop that will iterate between the random number chosen and
   //the size of the total amount of Foundables of the user's chosen
   //rarity 
   for (int i = randNum; i < size; i++)
     {
       //temporarily stores the values from the name, type, rarity, and
       //toughness arrays to the string and int values of the attributes
       name = nameArr[i];
       type = typeArr[i];
       rarity = rarityArr[i];
       toughness = toughnessArr[i];
       //assigns the Foundable object newFoundable to the temporarily
       //stored attributes of the Foundable
       newFoundable = Foundable(name, type, rarity, toughness);
       cout << endl;
	
       //if statment that will call the CheckFoundable() function in the
       //Wizard.cpp class, passing it the Foundable object newFoundable
       //that has temporarily stored the attributes of the Foundable to be
       //checked. If CheckFoundable() returns false, the Foundable has
       //not already been defeated and is not in m_foundables,
       //and thus the Wizard will attack that Foudnable 
       if (!(m_wizard.CheckFoundable(newFoundable)))
	 {
	   cout << "The Wizard " << m_wizard.GetName() <<
	   " attacks " << newFoundable.GetName() << "!!"<< endl;
	   cout << endl;
	   enemy = newFoundable; //creates a newFoundable "pointer"
	                         //that will be passed to the
	                         //AttackFoundables() function in
	                         //Wizard.cppp
	       
	   //if statment that will call the AttackFounables() function
	   //in Wizard.cpp, passing it the enemy object. If this
	   //returns false, then the Wizard's toughness was greater
	   //than the enemy's toughness, and the foundable was defeated.
	   //If the foundable is defeated, then the InsertFoundable()
	   //function is called in the Wizard.cpp classes, which will add
	   //a copy of that Foundable to m_foundables. Else, informs the
	   //user that the Foundable was not defeated
	   if(!(m_wizard.AttackFoundable(enemy)))
	     {
	       cout << "You defeat the " << enemy.GetName() << "!!"
		    << endl;
	       //adds a copy of the Foundable defeated to m_foundables
	       m_wizard.InsertFoundable(enemy);
	       cout << endl; 
	       return;
	     }
	   else
	     {
	       cout << "You do not successfully defeat the foundable.\n";
	       cout << endl;
	       return;
	     }
	 }//end if
     }//end for

   //for loop that will only be run if in the previous for loop,
   //there are no Foundables left of the chosen rarity that have not
   //been defeated in the range of the random number chosen to total size
   //of Foundables of that rarity.
   //This for loop  will iterate between 0, and the random number chosen, 
   //checking all of the previously unchecked Foudnables of the chosen rarity
   //in m_allFoundables 
   for (int i = 0; i <= randNum; i++)
     {
       //temporarily stores the values from the name, type, rarity, and
       //toughness arrays to the string and int values of the attributes
       name = nameArr[i];
       type = typeArr[i];
       rarity = rarityArr[i];
       toughness = toughnessArr[i];
       //assigns the Foundable object newFoundable to the temporarily
       //stored attributes of the Foundable
       newFoundable = Foundable(name, type, rarity, toughness);
       cout << endl;

       //if statment that will call the CheckFoundable() function in the
       //Wizard.cpp class, passing it the Foundable object newFoundable
       //that has temporarily stored the attributes of the Foundable to be
       //checked. If CheckFoundable() returns false, the Foundable has
       //not already been defeated and is not in m_foundables,
       //and thus the Wizard will attack that Foudnable
       if (!(m_wizard.CheckFoundable(newFoundable)))
	 {
	   cout << "The Wizard " << m_wizard.GetName() <<
	   " attacks " << newFoundable.GetName() << "!!"<< endl;
	   enemy = newFoundable; //creates a newFoundable "pointer"
	                         //that will be passed to the
	                         //AttackFoundables() function in
	                         //user that the Foundable was not defeated

	   //if statment that will call the AttackFounables() function
	   //in Wizard.cpp, passing it the enemy object. If this
	   //returns false, then the Wizard's toughness was greater
	   //than the enemy's toughness, and the foundable was defeated.
	   //If the foundable is defeated, then the InsertFoundable()
	   //function is called in the Wizard.cpp classes, which will add
	   //a copy of that Foundable to m_foundables. Else, informs the
	   //user that the Foundable was not defeated
	   if(!(m_wizard.AttackFoundable(enemy)))
	     {
	       cout << "You defeat the " << enemy.GetName() << "!!" << endl;
	       //adds a copy of the Foundable defeated to m_foundables
	       m_wizard.InsertFoundable(newFoundable);
	       cout << endl;
	       return;
	     }
	   else
	     {
	      cout << "You do not successfully defeat the foundable.\n";
	      cout << endl;
	      return;
	     }
	 }//end
     }//end for

     //if both for loops have been ran and checked through, and both
     //CheckFoundables() have returned true, indicating there are no
     //Foundables left of that chosen rarity in their range,
     //this statment will display- informing the user that there
     //are no more Foundables left to find that are of the chosen rarity
     cout << "You have found all Foundables at that";
     cout << " level of rarity!\n";
     cout << endl;
   
}//end AttackFoundables()

//if the wizard is level 1, it has not defeated any Foundables yet and
//thus will inform the user. Else, displays the formatted, numbered list
//of every Foundable they have defeated thus far with their correct attributes.
void Game::PrintMyFoundables()
{
  if (m_wizard.GetLevel() == 1)
    {
      cout << endl;
      cout << "You have not defeated any foundables yet.\n" << endl;
    }
  else
    {
      m_wizard.PrintMyFoundables(); 
    }
} 

//displays a numbered, formatted list of every single one of the 192
//Foundables in m_allFoundables
void Game::PrintFoundables()
{
  cout << endl;
  for (int i = 0; i < NUM_FOUNDABLE; i++)
   {
    cout << i+1 << ". " << m_allFoundables[i].GetName() << "| "; 
    cout << m_allFoundables[i].GetType() << "| ";
    cout << m_allFoundables[i].GetRarity() << "| ";
    cout << m_allFoundables[i].GetToughness() << endl;
    cout << endl;
   }
}

//Displays the wizards game statistics: the wizard name, level,
//toughness, list of Foundables found, wins, losses, and their
//win rate formated to 2 places after the decimal
void Game::WizardStat()
{
  //displays the wizard name, level, and toughness
  cout << endl;
  cout << "**************************************************************\n";
  cout << endl;
  cout << "Information About Wizard " << m_wizard.GetName() << endl;
  cout << endl;
  cout << "Level: " << m_wizard.GetLevel()  << endl;
  cout << endl;
  cout << "Toughness: " << m_wizard.GetToughness() << endl;
  cout << endl;
  
  //if the wizard is still level 1, they have not defeated any Foudnables
  //yet and will then be informed. Else, displays a list of every Foundable
  //that has been defeated and added to m_foundables
  if (m_wizard.GetLevel() == 1)
    {
      cout << "Foundables Found: 0\n" << endl;
    }
  else
    {
      cout << "Foundables Found: "; m_wizard.PrintMyFoundables();
    }

  //displays the wizards wins and losses
  cout << "Wins:" << " " << m_wizard.GetWins() << " " << "Losses: "
       << m_wizard.GetLosses() << endl;
  cout << endl;

  //if the wizard has 0 wins, it will display a win rate of 0.00%
  //to acount for the divide by zero error in the code. Else, will display the
  //formatted winrate with two places after the decimal.
  if (m_wizard.GetLosses() == 0)
    {
      cout << "Win Rate: 0.00%";
      cout << endl << endl;
      cout <<"**************************************************************\n";
      cout << endl;
    }
  else
    {
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      double winRate = double(m_wizard.GetWins()) /
      double(m_wizard.GetLosses());
      cout  << "Win Rate: "
	   << winRate << "%" << endl;
      cout << noshowpoint;
      cout << endl << endl;
      cout <<"**************************************************************\n";
      cout << endl;
    }
}
 
