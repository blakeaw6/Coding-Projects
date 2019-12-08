/*************************************************************
 ** File: Project1.cpp
 ** Project: CMSC 202 Project 1, Fall 2019
 ** Author: Blake Wishard 
 ** Date: September 16, 2019
 ** Section: 20
 ** E-mail: blakew1@umbc.edu
 **
 ** This file contains the main function and all other functions 
    in the program for Project 1.
 ** In this project, a rabbit and farmer will be generated on a 10 x 10 grid 
 ** of "|" and the farmer will move once space at a time in a direction 
 ** to attempt to catch the rabbit. The rabbit will either move one space 
 ** or not.
 ** This project will create a two dimensional array called grid, and an array
 ** of two elements each called rabbit and farmer. A randomly generated number
 ** between 0 and 4 will be assigned to the first and second element of the 
 ** rabbit, and the user will enter their desired x and y values for 
 ** the starting position of the farmer. As long as both the first element
 ** of the farmer and first element of the rabbit, AND the second element 
 ** of the farmer and second element of the rabbit do not equal each other, 
 ** the rabbit will move 1 space in a random direction, or not move at all,
 ** and the farmer will move one space in a direction as chosen by the user.
 ** If either the farmer or the rabbit is at the boundaries of the grid,
 ** they will not be able to move in that direction and leave the grid. 
 ** the direction of the rabbit in relation to farmer is then calculated 
 ** and displayed, and a 10 x 10 grid of "|" will be displayed along with the 
 ** positions of the farmer and the rabbit being displayed with a 'F' and 'R'.
 ** Once the rabbit is caught by the farmer, only a 'F' will be displayed 
 ** on the grid and a congratulatory message will be displayed, 
 ** and the user will be prompted if they wish to play again.
***************************************************************/
#include <iostream> //imports iostream
#include <ctime>   //used for TIME 
#include <iomanip> //used for precision
#include <cmath>   //used to import math functions 
#include <cstdlib> //allows use of srand() function 
using namespace std; //adds std:: to all commands in std 

const int NUM_ROWS = 10;   //num of rows in the grid
const int NUM_COLS = 10;   //num of columns in the grid
const char FARMER = 'F';   //used to display the position of the farmer
                           //on the grid
const char RABBIT = 'R';   //used to display the position of the rabbit
                           //on the grid

//Function name: startRabbit
//Pre-condition: rabbit is an array with two integers,
//   and grid is an two-dimensional array.
//Post-condition:a random number is generated between 0 and 9 and
//   assigned to the second integer in the rabbit array. Next, another
//   random number is generated between 0 and 9 and assigned to the first
//   integer of the rabbit array. Then, the value of first and second
//   integer of the rabbit array are passed to the first and second index
//   of the grid array, and the grid array is set equal to the constant
//   char RABBIT- which is how the rabbit's position is displayed on the grid.
void startRabbit(int rabbit[], char grid[][NUM_COLS], int NUM_ROWS);

//Function name: startFarmer
//Pre-condition: farmer is an array with two integers,
//   and grid is an two-dimensional array.
//Post-condition:a random number is generated between 0 and 9 and
//   assigned to  the second integer in the farmer array. Next, another
//   random number is generated between 0 and 9 and assigned to the first
//   integer of the farmer array. Then, the value of first and second
//   integer of the farmer array are passed to the first and second index
//   of the grid array, and the grid array is set equal to the constant
//   char RABBIT- which is how the rabbit's position is displayed on the grid.
void startFarmer(int farmer[], char grid[][NUM_COLS], int NUM_ROWS);

//Function Name: moveRabbit
//Pre-condition: rabbit is an array of two integers, grid is a
//   two-dimensional array, and NUM_ROWS is the size of the grid array.
//Post-condition: the grid array containing the values of the first and
//   second integers of the rabbit array is set equal to spaces. Next, a
//   random number between 0 and 4 is generated and assigned to the
//   randChoice integer. Then, a switch statement is called that moves
//   the rabbit one space in a direction(north, east, south, or west)
//   if 1-4 is generated, or, doesn't move at all if 0 is generated.
//   if the rabbit is at the boundaries of the grid and tries to move
//   out of it, the rabbit will not move for that that turn. Lastly,
//   the grid array of rabbit integer1 and integer2 values is set equal
//   to the constant char RABBIT - which is used to display the rabbit's
//   position on the grid.
void moveRabbit(int rabbit[], char grid[][NUM_COLS], int NUM_ROWS);

//Function Name: moveFarmer
//Pre-condition: farmer is an array of two integers, grid is a
//   two-dimensional array, and NUM_ROWS is the size of the grid array.
//Post-condition: the grid array containing the values of the first and
//   second integers of the farmer array is set equal to spaces. Next,
//   the user enters a number 1-4 depending on the direction they wish
//   to move the farmer(north, east, south, west). Then, a switch
//   statement is called that moves the farmer one space in the desired
//   direction. If the farmer is at the boundaries of the grid and tries
//   to move out of it, a messaged will be displayed informing the user
//   that the farmer cannot leave the grid, and will prompt them to enter
//   a new number. Lastly, the grid array of farmer integer1 and integer2
//   values is set equal to the constant char FARMER - which is used to
//   display the farmer's position on the grid.
void moveFarmer(int farmer[], char grid[][NUM_COLS], int NUM_ROWS);

//Function name: displayDirection
//Pre-condition: farmer and rabbit are arrays of two integers.
//Post-condition: the function will display the direction of the rabbit
//relative to the farmer, depending on which the x or y element is
//greater for the farmer or rabbit.
void displayDirection(int farmer[], int rabbit[]);

//Function name: displayGrid
//Pre-condition: grid is a two-dimensional array and NUM_ROWS is the
//   size of the array.
//Post-condition: the function will loop through the rows and columns
//   of the grid array and print a '|' for int i < NUM_ROWS and
//   int j < NUM_COLS. It will also display the grid of i and j values.
//   Lastly, it checks if the j int is at the boundary(NUM_COLS) minus 1,
//   it will display a "|";
void displayGrid(char grid[][NUM_COLS], int NUM_ROWS, int farmer[],
		 int rabbit[]);

int main()
{
  
  srand(time(NULL));               //seeds the randomizer
  
  char grid[NUM_ROWS][NUM_COLS];   //declares a two-dimensional grid
                                   //of char with size NUM_ROWS x NUM_COLS
  
  //for loop that will loop through the entire grid and set the
  //first and second index equal to spaces 
  for (int i = 0; i < NUM_ROWS; i++)
        {
      for (int j = 0; j < NUM_COLS; j++)
	{
	  grid[i][j] = ' ';
	}
    }
  
  bool running = true;            //sets the boolean variable 'running'
                                  //equal to true

  int farmer[] = {0, 1};           //declares an array of integers with
                                   //two elements

  int rabbit[] = {0, 1};
  
  //while loop that will run as long as the user wants to keep playing the
  //game. When the user has won, it will prompt the user to enter yes if
  //want to continue playing, and if not it will set the boolean variable
  //'running' equal to false and thus end the game.
  while (running)
    {
      //calls the startFarmer function with parameters farmer array,
      //grid array, and int NUM_ROWS
      startFarmer(farmer, grid, NUM_ROWS);
      //calls the startRabbit function with parameters rabbit array,
      //grid array, and int NUM_ROWS
      startRabbit(rabbit, grid, NUM_ROWS);

     //do-while loop - will continue to run as long as the conditions in
     //while are true. Here, the do-while loop will continue to run as
     //long as the first element in the farmer array is not equivalent
     //to the first element in the rabbit array, and the second elements
     //in each array are not equivalent eiter
     do 
      {
	//calls the moveFarmer function with parameter farmer array,
	//grid array, and int NUM_ROWS
	moveFarmer(farmer, grid, NUM_ROWS);

	//if statement that will run and call the moveRabbit function as
	//long as the first and second elements in the farmer and rabbit array
	//are not equivalent 
	if(!((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])))
	  {
	    //call the moveRabbit function with parameters rabbit array,
	    //grid array, and int NUM_ROWS
	    moveRabbit(rabbit, grid, NUM_ROWS);
	  }

	//calls the displayDirection array with parameters farmer
	//array and rabbit array
	displayDirection(farmer, rabbit);
	//calls the displayGrid function with parameters grid array,
	// and int NUM_ROWS
	displayGrid(grid, NUM_ROWS, farmer, rabbit);
	cout << endl;
	//sets the grid of farmer 1 and 2
                                         //equal to spaces
      
      }while(!((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])));
     
     //if statement that will run if the first and second elements in the
     //farmer and rabbit arrays are equivalent to each other. It will
     //inform the user that they have won the game and congratulate them,
     //and prompt them to enter 'y' for yes if they wish to play again
     if(((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1])))
      {
        cout << "The farmer has found the rabbit!\n";
	grid[farmer[0]][farmer[1]] = ' '; //sets the grid of farmer element 1
	                                  //and farmer element 2 to spaces 
	cout << "Congrats you've won!\n";
	cout << "Play again? (y/n)\n";
	char answer;                     //declares a char that will store
	                                 //the users anwser if they wish to
	                                 //play again
	cin >> answer;
	cin.ignore(256, '\n');
	running = answer == 'y';	
      }
    }//end while
  
  return 0;
  
}//end main

//the function body of the startRabbit function
void startRabbit(int rabbit[], char grid[][NUM_COLS], int NUM_ROWS)
{
  int xNum;            //declares variable to store the x value(second element)
                       //of the rabbit array
  xNum = rand() % 9;  //generates a random integer between 0 and 9 and
                      //sets it equal to xNum
  rabbit[1] = xNum;   //sets the second element of the rabbit array equal
                      //to the randomly generated x value 

  int yNum;          //declares variable to store the y value(first element)
                     //of the rabbit array
  yNum = rand() % 9; //generates random integer between 0 and 9 and sets it
                     //equal to yNum
  rabbit[0] = yNum;  //sets the first element of the rabbit array equal to
                     //the randomly generated x value 

  grid[rabbit[0]][rabbit[1]] = RABBIT;  //passes the first and second
                                        //elements of the rabbit array to
                                        //the grid array and sets it equal
                                        //to RABBIT - which is used to display
                                        //the position of the rabbit on the grid
  
}

//the function body of the startFarmer function
void startFarmer(int farmer[], char grid[][NUM_COLS], int NUM_ROWS)
{
  cout << endl;
  int xNum;            //declares variable to store the x value (second element)
                       //of the farmer array
  
  //welcomes the user to the game and prompts them to enter an integer value
  //for their desired starting row position for the farmer and stores that
  //value in xNum
  cout << "Welcome to Chase the Rabbit.\n"; 
  cout << "Where would you like to start the farmer?\n" << endl;
  cout << "Enter the column(x) (0-9)\n";
  cin >> xNum;
  
  //an error checking while loop that will run if the user enters
  //a number < 0 or > 9. it will inform them that their number is invalid,
  //and re-prompt them to enter an integer between 0 and 9.
  while (xNum < 0 || xNum > 9)
    {
      cout << "That is not a valid entry. Try again.\n\n";
      cout << "Enter the column(x) (0-9)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> xNum;
    }

  farmer[1] = xNum; //sets the second element of the farmer array equal to
                   //the number the user entered 

  int yNum;        //declares variable to store the y value (first element)
                  //of the farmer array
  cout << endl;
  //prompts the user to enter an integer value for their desired starting
  //column position for the farmer and stores that value in yNum
  cout << "Enter the row(y) (0-9)\n";
  cin >> yNum;

  //error checking while looop that will run if the user enters a number
  // < 0 or > 9. It will inform them that their number is invalid,
  //and re-promt the user to enter an integer between 0 and 9.
  while (yNum < 0 || yNum > 9)
    {
      cout << "That is not a valid entry. Try again.\n\n";
      cout << "Enter the column(y) (0-9)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> yNum;
    }

  farmer[0] = yNum; //sets the first element of the farmer array equal to
                    //the number the user entered  
  cout << endl;
  grid[farmer[0]][farmer[1]] = FARMER; //passes the first and second
                                      //elements of the farmer array to
                                      //the grid array and sets it equal
                                      //to FARMER - which is used to display
                                      //the position of the farmer on the grid
  
}

//the function body for the moveRabbit function
void moveRabbit(int rabbit[], char grid[][NUM_COLS], int NUM_ROWS)
{
  grid[rabbit[0]][rabbit[1]] = ' '; //sets the grid array equal to spaces
  int randChoice;                   //declares an integer that will store a
                                    //randomly generated number
  randChoice = rand() % 4;         //randomly generates a number between 0
                                   //and 4 and stores it in randChoice

  //switch statement that will run depending on the randChoice randomly
  //generated value. If it is a 1, case 1 will run. If 2, case 2 will run, etc. 
  switch(randChoice)
    {
      //if the second element of the rabbit array is equal to 0, the rabbit
      //is at the north boundary of the grid and thus does not move.
      //else, the rabbit will move up one space(north)
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

      //if the first element of the rabbit array is equal to 9, the rabbit
      //is at the eastmost boundary of the grid and thus does not move
      //for the turn. else, the rabbit will move one space to the right(east)
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

      //if the second element of the rabbit array is equal to 9, the rabbit
      //is at the southmost boundary of the grid and thus does not move
      //for that turn. Else, the rabbit will move one space down(south)
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

      //if the first element of the rabbit array is equal to 0, the rabbit
      //is at the westmost boundary of the grid and thus does not move
      //for that turn. Else, the rabbit will move once space to the left
      //(west)
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

      //if the random number generated is 0, the rabbit will not move for
      //that turn
    default:
      {
	cout << "The rabbit nibbles on some food and does not move.\n";
      }
    }//end switch
  
  grid[rabbit[0]][rabbit[1]] = RABBIT; //sets the grid of rabbit 1, rabbit 2
                                       // equal to RABBIT - which is used to
                                       //display the position of the rabbit
  
}//end moveRabbit

void moveFarmer(int farmer[], char grid[][NUM_COLS], int NUM_ROWS)
{
  grid[farmer[0]][farmer[1]] = ' ';  //sets the grid array equal to spaces

  int choice;                       //declares a variable for the integer
                                    //the user enters 

  //prompts the user to enter an integer between 1 and 4 depending on the
  //direction they wish to move the farmer, and stores the value in choice
  cout << "What would you like to do?\n";
  cout << "1. Search north.\n";
  cout << "2. Search east.\n";
  cout << "3. Search south.\n";
  cout << "4. Search west.\n";
  cin >> choice;
  
  //error checking if statement that will run if the user enters an integer
  //that is < 1 or > 4. It will display an invalid option statement
  //and re-prompt the user to enter an integer between 1 and 4.
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

  //else statement that will run if the user correctly enters an integer
  //between 1 and 4. Depending on the integer chosen by the user, the
  //farmer will move one space in a direction(north, east, south, west).
  //if the user attempts to move the farmer outisde of the boundaries of
  //the grid, it will display a message to the user and re-prompt them
  //to enter a different integer to move another direction.
  else{
    
    //if the first element of the farmer is at equal to zero, the farmer
    //is at the northmost boundary of the grid and therfore is unable to move
    //else, the farmer will move up one space(north)
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
	}//end case 1
	break;

       //if the second element of the farmer is equal to 9, the farmer
       //is in the eastmost boundary of the grid and therefore is unable to
       //move to that space. Else, the farmer will move to the right
       //one space(east)
      case 2:
	{
	  if(farmer[1] == 9)
	    {
	      cout << "The farmer can't leave the field" << endl;
	    }
	  else
	    {
	      farmer[1]++;
	      cout << "The farmer moves east\n";
	    }
	}//end case 2
	break;

	//if the first element of the farmer is equal to 9, the farmer
	//is at southmost boundary of the grid, and the farmer is thus unable
	//to move to that space. Else, the farmer will move down once space
	//(south)
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
	}//end case 3
	break;

	//if the second element of the farmer array is equal to 0, the farmer
	//is at the westmost boundary of the grid, and the farmer is thus
	//unable to move. else, the farmer will move one space to left(west)
      case 4:
	{
	  if(farmer[1] == 0)
	    {
	      cout << "The farmer can't leave the field" << endl;
	    }
	  else
	    {
	      farmer[1]--;
	      cout << "The farmer moves west\n";
	    }
	}//end case 4
	break;

	//this case should never run since the choice value is first checked
	//to make sure it is a 1 - 4.
      default:
	{
	  cout << "bad data";

	}

      }//end switch

  }//end else
 
  grid[farmer[0]][farmer[1]] = FARMER; //sets the grid array of farmer element
                                       //1 and 2 equal to FARMER - which is used
                                       //to display the position of the farmer
                                       //on the grid

}//end movefarmer

//function body for the displayDirection function 
void displayDirection(int farmer[], int rabbit[])
{
  int num1, num2;     //declares two integer values that will be used
                      //for comparison purposes when outputting the direction
                      //of the rabbit in relation to the farmer 

  //if statement that is used to check the direction the rabbit is in relation
  //to the farmer. checks the array values of both the farmer and rabbit and
  //compares them to see if the farmer is more South East or South West of
  //the farmer
  if(farmer[0] < rabbit[0] && farmer[1] != rabbit[1])
    {
      //if statement that will run if the value of the first element of the
      //rabbit is less than the value of the first element of the farmer,
      //and the same for the second elements
      if (farmer[1] < rabbit[1])
	{
	  num1 = rabbit[0] - farmer[0];
	  num2 = rabbit[1] - farmer[1];

	  //if statement comparing the two values to see if the
	  //rabbit is more south or east of the farmer
	  if(num1 >= num2)
	    {
	      cout << "The rabbit is south of the farmer.\n";
	    }
	  if (num2 > num1)
	    {
	      cout << "The rabbit is east of the farmer.\n";
	    }
	}
      //if statement that will run if the value of the second element of the
      //farmer is greaer than the value of the first element of the rabbit
      //and the same for the second elements
      if (farmer[1] > rabbit[1])
	{
	  num1 = rabbit[0] - farmer[0];
	  num2 = farmer[1] - rabbit[1];
	  //if statement that compares the two numbers to see 
	  if (num1 >= num2)
	    {
	      cout << "The rabbit is south of the farmer.\n";
	    }
	  if (num2 > num1)
	    {
	      cout << "The rabbit is west of the farmer.\n";
	    }
	}
    }

  //if statement that will first check conditions and then compare
  //to check if the rabbit is more north or east of the farmer 
  if(farmer[0] > rabbit[0] && farmer[1] != rabbit[1])
    {
      //compares the second elements of the farmer and rabbit arrays
      if (farmer[1] < rabbit[1])
	{
	  num1 = farmer[0] - rabbit[0];
	  num2 = rabbit[1] - farmer[1];

	  //compares the two numbers to see direction of rabbit
	  //in relation to the farmer
	  if (num1 >= num2)
	    {
	      cout << "The rabbit is north of the farmer.\n";
	    }
	  if (num2 > num1)
	    {
	      cout << "The rabbit is east of the farmer.\n";
	    }
	}

      //compares the second elements of the farmer and rabbit arrays
      if( farmer[1] > rabbit[1])
	{
	  num1 = farmer[0] - rabbit[0];
	  num2 = farmer[1] - rabbit[1];

	  //compares the two number to see the direction of rabbit in
	  //relation to the farmer
	  if (num1 >= num2)
	    {
	      cout << "The rabbit is north of the farmer.\n";
	    }
	  if (num2 > num1)
	    {
	      cout << "The rabbis is west of the farmer.\n";
	    }
	}      
    }

  //checks to see if the rabbit is directly below the farmer
  if(farmer[0] < rabbit[0] && farmer[1] == rabbit[1])
    {
      cout << "The rabbit is south of the farmer.\n";
    }
  //checks to see if the rabbit is directly above the farmer
  if(farmer[0] > rabbit[0] && farmer[1] == rabbit[1])
    {
      cout << "The rabbit is north of the farmer.\n";
    }

  //checks to see if the rabbit is directly east of the farmer
  if(farmer[1] < rabbit[1] && farmer[0] == rabbit[0])
    {
      cout << "The rabbit is east of the farmer.\n";
    }
  //checks to see if the rabbit is directly west of the farmer
  if(farmer[1] > rabbit[1] && farmer[0] == rabbit[0])
    {
      cout << "The rabbit is west of the farmer.\n";
    }  
}//end displayDirection

//function body for the displayGrid function
void displayGrid(char grid[][NUM_COLS], int NUM_ROWS, int farmer[],
		                                      int rabbit[])
{
  //and inner and outer for loop that will run through the grid and display
  // "|" and the position of the farmer and the rabbit
  for (int i = 0; i < NUM_ROWS; i++)
    {
      cout << endl;
      
      for (int j = 0; j < NUM_COLS; j++)
	{
	      cout << "|";
	      cout << grid[i][j];

	      //if statement that will print a "|" on the grid if either
	      //the farmer or the rabbit is at the boundaries of the grid
	      if (j == (NUM_COLS -1))
		{
		  cout << "|";
		}

	      if ((farmer[0] == rabbit[0]) && (farmer[1] == rabbit[1]))
	        {
		  grid[farmer[0]][farmer[1]] = FARMER;
		}
		
        } cout << endl;
    }cout << endl;
}
  	
