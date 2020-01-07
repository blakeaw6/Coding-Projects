/*************************************************************
 ** File: Project1.cpp
 ** Project: CMSC 202 Project 1, Fall 2019
 ** Author: Blake Wishard 
 ** Date: tbd
 ** Section: tbd
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the main function and all other functions 
    in the program for Project 1. 
 ** This project...
.......
.....
***************************************************************/
#include <iostream> //imports iostream
#include <ctime>   //required for time
#include <iomanip>
#include <cmath>
#include <cstdlib> //required for rand
using namespace std; //adds std:: to all commands in std 

const int NUM_ROWS = 10;   //num of rows in the grid
const int NUM_COLS = 10;   //num of columns in the grid
const char FARMER = 'F';   //used to display the position of the farmer
                           //on the grid
const char RABBIT = 'R';   //used to display the position of the rabbit
                           //onthe grid

//function prototype for startRabbit function
void startRabbit(int rabbit[], char grid[][NUM_COLS], int gridSize);

void startFarmer(int farmer[], char grid[][NUM_COLS], int gridSize);

void displayGrid(int farmer[], int rabbit[],
		 char grid[][NUM_COLS], int gridSize);

void moveFarmer(int farmer[], char grid[][NUM_COLS], int gridSize);

void moveRabbit(int rabbit[], char grid[][NUM_COLS], int gridSize);

void displayDirection(int farmer[], int rabbit[]);

int main()
{
  
   srand(time(NULL));               //seeds random number generator 
   int gridSize = 10;              //sets the size of the grid to 10
  char grid[NUM_ROWS][NUM_COLS];   

  for (int i = 0; i < NUM_ROWS; i++) 
    {
      for (int j = 0; j < NUM_COLS; j++)
	{
	  grid[i][j] = ' ';
	}
    }
	  
 

  int farmer[] = {0, 1};
  int rabbit[] = {0, 1};

  bool running = true;

  while (running)
   {
      startFarmer(farmer, grid, gridSize);
      startRabbit(rabbit, grid, gridSize);
      
      do 
      {

	moveFarmer(farmer, grid, gridSize);

	if(!((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])))
	  {
	   moveRabbit(rabbit, grid, gridSize);
	  }
	
	displayDirection(farmer, rabbit);
      

	displayGrid(farmer, rabbit, grid, gridSize);

	cout << farmer[0] << endl;
	cout << farmer[1]<< endl;
	cout << rabbit[0]<< endl;
	cout << rabbit[1] << endl;


	
	
      }while(!((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])));
							       
 

      if(((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])))
			       
		 
      {
	cout << "The farmer has found the rabbit!\n";
	cout << "Congrats you've won!\n";
	cout << "Play again? (y/n)\n";
	char answer;
	cin >> answer;
	cin.ignore(256, '\n');
	running = answer == 'y';
      }
    
    }//end while 

    return 0;
}//end main

//Function name: displayDirection
//famer and rabbit are the arrays to display the postion of
//the farmer and rabbit in the grid
//Post-condition: the function will display the direction of the rabbit relative
//to the farmer, depending on the furthest 
void displayDirection(int farmer[], int rabbit[])
{
  int a, b;

 
  if(farmer[0] < rabbit[0] && farmer[1] != rabbit[1])
    {
      if (farmer[1] < rabbit[1])
	{
	  a = rabbit[0] - farmer[0];
	  b = rabbit[1] - farmer[1];
	  if(a >= b)
	    {
	      cout << "The rabbit is south of the farmer.\n";
	    }
	  if (b > a)
	    {
	      cout << "The rabbit is east of the farmer.\n";
	    }
	}
      if (farmer[1] > rabbit[1])
	{
	  a = rabbit[0] - farmer[0];
	  b = farmer[1] - rabbit[1];
	  if (a >= b)
	    {
	      cout << "The rabbit is south of the farmer.\n";
	    }
	  if (b > a)
	    {
	      cout << "The rabbit is west of the farmer.\n";
	    }
	}
    }
  
  if(farmer[0] > rabbit[0] && farmer[1] != rabbit[1])
    {
      if (farmer[1] < rabbit[1])
	{
	  a = farmer[0] - rabbit[0];
	  b = rabbit[1] - farmer[1];
	  if (a >= b)
	    {
	      cout << "The rabbit is north of the farmer.\n";
	    }
	  if (b > a)
	    {
	      cout << "The rabbit is east of the farmer.\n";
	    }
	}
      if( farmer[1] > rabbit[1])
	{
	  a = farmer[0] - rabbit[0];
	  b = farmer[1] - rabbit[1];
	  if (a >= b)
	    {
	      cout << "The rabbit is north of the farmer.\n";
	    }
	  if (b > a)
	    {
	      cout << "The rabbis is west of the farmer.\n";
	    }
	}
      
    }

  if(farmer[0] < rabbit[0] && farmer[1] == rabbit[1])
    {
      cout << "The rabbit is south of the farmer.\n";
    }

  if(farmer[0] > rabbit[0] && farmer[1] == rabbit[1])
    {
      cout << "The rabbit is north of the farmer.\n";
    }


  if(farmer[1] < rabbit[1] && farmer[0] == rabbit[0])
    {
      cout << "The rabbit is east of the farmer.\n";
    }

  if(farmer[1] > rabbit[1] && farmer[0] == rabbit[0])
    {
      cout << "The rabbit is west of the farmer.\n";
    }
  
						 
						 
					       

  
  
  
  
  
}//end displayDirection 
   
   
//Function name: startFarmer
//Pre-condition: 
void startFarmer(int farmer[], char grid[][NUM_COLS], int gridSize)
{
  int xNum;
  cout << "Welcome to Chase the Rabbit.\n";
  cout << "Where would you like to start the farmer?\n" << endl;
  cout << "Enter the column(x) (0-9)\n";
  cin >> xNum;

  while (xNum < 0 || xNum > 9)
    {
      cout << "That is not a valid entry. Try again.\n\n";
      cout << "Enter the column(x) (0-9)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> xNum;
    }

  farmer[1] = xNum;
  
  int yNum;
  cout << endl;
  cout << "Enter the row(y) (0-9)\n";
  cin >> yNum;

  while (yNum < 0 || yNum > 9)
    {
      cout << "That is not a valid entry. Try again.\n\n";
      cout << "Enter the column(y) (0-9)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> yNum;
    }

      farmer[0] = yNum;
      cout << endl;

      grid[farmer[0]][farmer[1]] = FARMER;
   
}

//Function name: startRabbit
//Pre-condition:  user enters 
void startRabbit(int rabbit[], char grid[][NUM_COLS], int gridSize)
{
  int xNum;
  xNum = rand() % 9; 
  rabbit[1] = xNum;
  
  int yNum;
  yNum = rand() % 9;
  rabbit[0] = yNum;

  grid[rabbit[0]][rabbit[1]] = RABBIT;
}

void displayGrid(int farmer[], int rabbit[], char grid[][NUM_COLS], int gridSize)
{
  for (int i = 0; i < NUM_ROWS; i++)
    {
      cout << endl;
      for (int j = 0; j < NUM_COLS; j++)
	{
	  
	  cout << "|";
	  cout << grid[i][j];
	  
	  if(j == (NUM_COLS -1))
	    {
	      cout << "|";
	    }
	  
	  // test part1
	  /* 
	  if ((grid[i][j] == FARMER) && (grid[i][j] == RABBIT))
	    {
	      grid[i][j] = FARMER; 
	      cout << grid[i][j];
	    }
	  
	  if (!((grid[i][j] == FARMER) && (grid[i][j] == RABBIT)))
	    {
	      cout << grid[i][j]; 
	    }
	  */

	  /*
	  if (((grid[i][j] == FARMER) && (grid[i][j] == RABBIT)))
	    {
	      grid[i][j] = FARMER; 
	      cout << grid[i][j];
	    }
	  */
	  
	  /*
	    
	  if((farmer[1] == i)  && (farmer[0] == j))
	    {

	      cout << "|" << FARMER;
	    }
	  if((rabbit[1] == i) && (rabbit[0] == j))
	    {
	      cout << "|" << RABBIT;
	    }
	  else
	    {
	      cout <<  "|" << " ";
	    }
	 
	  if (((grid[i][j] == FARMER) || (grid[i][j] == RABBIT)))
	    {
	      cout << grid[i][j] << "|";
	  */
    

	
	

	    
	  
        } cout << endl; 
    }cout << endl;
}
  	


void moveFarmer(int farmer[], char grid[][NUM_COLS], int gridSize)
 {
   grid[farmer[0]][farmer[1]] = ' ';
   
   int choice;
   
   cout << "What would you like to do?\n";
   cout << "1. Search north.\n";
   cout << "2. Search east.\n";
   cout << "3. Search south.\n";
   cout << "4. Search west.\n";

    
   cin >> choice;
   
   if (choice < 1 || choice > 4)
     {
       cout << "That is a not a valid option. Try again.\n";
       cout << "Enter an option(1-4):\n";
       cout << "1. Search north.\n";
       cout << "2. Search east.\n";
       cout << "3. Search south.\n";
       cout << "4. Search west.\n";
       cin.clear();
       cin.ignore(256, '\n');
       cin >> choice;
     }
   
   else{
       
     
    switch (choice)
    {
    case 1:
      {
	if (farmer[0] == 0)
	  {
	    cout << "The farmer can't leave the field\n" << endl;
	  }
	else
	  {
	    farmer[0]--;
	    cout << "The farmer moves north\n";
	  }
      }
      break;

    case 2:
      {
	if(farmer[1] == 0)
	  {
	    cout << "The farmer can't leave the field" << endl;
	  }
	else
	  {
	    farmer[1]++;
	    cout << "The farmer moves east\n";
	  }
      }
      break;
      
    case 3:
     
      { 
        if(farmer[0] == 9) 
	  {
	    cout << "The farmer can't leave the field" << endl;
	  }
	else
	  {
	    farmer[0]++;
	    cout << "The farmer moves south\n";
	  }
      }
      break;

 
    case 4:
     {
       if(farmer[1]== 9)
	 {
	   cout << "The farmer can't leave the field" << endl;
	 }
       else
	 {
           farmer[1]--;
	   cout << "The farmer moves south\n";
	 }
     }
     break;
     
   default:
     {
       cout << "bad data. exiting....";
   
     }
     
   }//end switch 

   }//end else  

   grid[farmer[0]][farmer[1]] = FARMER;



  
       
 }//end movefarmer

void moveRabbit(int rabbit[], char grid[][NUM_COLS], int gridSize)
{
  grid[rabbit[0]][rabbit[1]] = ' ';
       
  int randChoice;
  
  randChoice = rand() % 4;
 
  switch(randChoice)
    {
    case 1:
      {
	if (rabbit[1] == 0)
	  {
	    cout << "The rabbit nibbles on some food and does not move.\n";
	  }
	else
	  {
	    rabbit[1]--;
	    cout << "The rabbit moves to another location in search of food.\n";
	  }
      }//end case 1
      break;
      
    case 2:
      {
	if (rabbit[0] == 9)
	  {
	    cout << "The rabbit nibbles on some food and does not move.\n";
	  }
	else
	  {
	    rabbit[0]++;
	  }
      }//end case 2
      break;

    case 3:
      {
	if (rabbit[1] == 9)
	  {
	    cout << "The rabbit nibbles on some food and does not move.\n";
	  }
	else
	  {
	    rabbit[1]++;
	  }
      }// end case 3
      break;

    case 4:
      {
	if (rabbit[0] == 0)
	  {
	    cout << "The rabbit nibbles on some food and does not move.\n";
	  }
	else
	  {
	    rabbit[0]--;
	  }
      }//end case 4
      break;

    default:
      {
	cout << "The rabbit nibbles on some food and does not move.\n";
      }
    }//end switch

       grid[rabbit[0]][rabbit[1]] = RABBIT;
}//end moveRabbit
