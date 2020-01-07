/*****************************************************************************
 ** File:    Scheduler.cpp
 ** Project: UMBC Scheduler, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/15/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Scheduler class
 ** 
 ** This class contains a default constructor, an overloaded constructor with 
 ** a passed string file name, and a destructor. 
 ** LoadFile() loads a .txt roster file and populates the roster 
 ** MainMenu() displays all the available options for the program. 
 ** DisplayCourses() displays the name and section of each course in 
 ** m_classes. DisplaySpecific() prompts the user to enter a specific course, 
 ** lists each class by their name and secton, and displays each student 
 ** enrolled in that course. SearchStudent() prompts user to enter a specific 
 ** student name and returns each course that the chosen name appears in. 
 ** SortRoster() sorts m_roster and m_waitlist by last name. Start() welcomes 
 ** the user to the program, loads the file and calls main menu. FindClass()
 ** searches for a specific class name in m_classes using a passed string name.
 ** The private member variables include string m_name and string m_filename, 
 **  a vector that holds Class pointers called m_classes. 
 *****************************************************************************/
#include "Scheduler.h"

//Name: Scheduler
//Desc: Default Constructor

//Precondition: None
//Postcondition: Creates Scheduler object
Scheduler::Scheduler()
{
  m_name = " ";
  m_fileName = " ";  
}

//Name: Scheduler
//Desc: Overloaded Constructor
//Precondition: Valid fileName
//Postcondition: Creates Scheduler object
Scheduler::Scheduler(string fileName)
{
  m_name = " ";
  m_fileName = fileName; 
}

//Name: ~Scheduler
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates everything dynamically allocated in Scheduler
Scheduler::~Scheduler()
{
  int classSize = m_classes.size(); //stores class size 

  //for loop that iteratoes through m_classes vector, deallocates the classes
  //and sets them equal to nullptr
  for (int i = 0; i < classSize; i++)
    {
      delete m_classes.at(i);
      m_classes.at(i) = nullptr;
    }

  //free memory
  m_classes.clear();
}

//Name: LoadFile
//Desc: Loads a roster file
//Precondition: Valid roster file
//Postcondition: Populates roster
void Scheduler::LoadFile()
{
  string fName;
  string lName;
  string tempStudentID;
  string courseName;
  int studentID;

  //input stream for reading in data from a .txt file
  ifstream inputStream;
  inputStream.open(m_fileName); //opens stream

  //while loop that uses getline and input stream to read in data from
  // .txt file
  while(getline(inputStream, fName, ','))
    {
      getline(inputStream, lName, ',');
      getline(inputStream, tempStudentID, ',');
      getline(inputStream, courseName);

      //after first name, last name, student ID, and course name have been
      //read in, ignores and temporarily stops input stream
      if(inputStream.peek() == '\n')
	inputStream.ignore();

      //used to convert temporarty student id string to an int
      studentID = atoi(tempStudentID.c_str());

      //creates a new student with the inputted data from the .txt file,
      //passing it the necessary parameters
      Student *newStudent = new Student(fName, lName, studentID);

      //calls AddStudent() to determine where to place the student
      AddStudent(newStudent, courseName);
    }
  inputStream.close(); //closes and ends input stream
}

//Name: MainMenu
//Desc: Displays the main menu of the program
// Has options for 1. Display All Courses, 2. Display Specific Course
//3. Search for Specific Student, 4. Sort Roster, and 5. Quit
//Precondition: Has roster loaded
//Postcondition: Keeps running until user chooses 5 (quit)
void Scheduler::MainMenu()
{
  bool running = true;
  int choice = 0;

  //do while loop that displays the main menu until the user decides to quit
  //the program
  do {
    
    while (choice < 1 || choice > 5)
      { cout << endl;
	cout << "1. Display All Courses" << endl;
	cout << "2. Display a Specific Course" << endl;
	cout << "3. Search for Specific Student" << endl;
	cout << "4. Sort Roster" << endl;
	cout << "5. Quit" << endl;
	cin >> choice;
	cout << endl;
      }
    cout << endl;

    //switch statement that allows user to choice and run an option from
    //the main menu
    switch(choice)
      {
      case 1:
	{
	  DisplayCourses();
	  choice = 0; //resets the student's choice to 0 in order to keep
	              //runnning do while loop 
 	}
	break;
	
      case 2:
	{
	  DisplaySpecific();
	  choice = 0;
	}
	break;
	
      case 3:
	{
	  SearchStudent();
	  choice = 0;
	}
	break;
	
      case 4:
	{
	  SortRoster();
	  choice = 0;
	}
	break;
	
      case 5:
	{
	  running = false;
	}
	break;
	
      }
  }while(running); //do while loop will continue as long as the boolean
                   //running has a value of true 

}
//Name: DisplayCourses()
//Desc: Displays each course in the m_classes (Just name and section)
//Precondition: Classes loaded into m_classes
//Postcondition: Displays Class info
void Scheduler::DisplayCourses()
{
  int classSize = m_classes.size(); //stores class size

  //for loop that iteratese through m_classes, displays the course and
  //section information for each class in the vector
  for (int i = 0; i < classSize; i++)
    {
      cout << "Course: " << m_classes[i]->GetName() << " " 
	   << "Section: " << m_classes[i]->GetSection();
      cout << endl;
    }
  
}

//Name: DisplaySpecific
//Desc: Prompts user for a specific course (lists each class by name/section)
//      Displays each student enrolled in course
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays student info by class
void Scheduler::DisplaySpecific()
{
 
  int choice = 0; 
  int classSize = m_classes.size();//stores class size

 
  //while loop used to prompt the user to enter which course they
  //wish to display
    while (choice < 1 || choice > classSize)
    {
      cout << "Which course would you like to display?" << endl;
      DisplayCourses();
      cin >> choice;
    }
  choice--;
  cout << endl;

  //displays the students in the user's specified class
  cout << "Displaying Student" << endl;
  cout << "Course: " << m_classes[choice]->GetName() << " "
       << "Section: " << m_classes[choice]->GetSection() << endl;
  m_classes[choice]->DisplayStudents(); 
 	 
  
}

//Name: SearchStudent
//Desc: Prompts user for a specific string to search for (student name)
//      Returns each course that name appears
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays classes that student is in
void Scheduler::SearchStudent()
{
  string choice;
  //prompts the user to search for a specific student 
  cout << "What name do you want to search for?" << endl;
  cin >> choice;

  cout << "Items with " << choice << " in them:" << endl;

  int classSize = m_classes.size(); //stores class size

  //for loop that iterates through m_classes at the index of the
  //specific student's name chosen and displays it 
  for (int i = 0; i < classSize; i++)
    {
      m_classes.at(i)->SearchClass(choice);
    }
  
}

//Name: SortRoster
//Desc: For each Class, each m_roster and m_waitlist is sorted by last name
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Does not display anything but rosters are sorted
void Scheduler::SortRoster()
{
  int classSize = m_classes.size(); //stores class size 

  //for loop that iterates m_classes and sorts the students by last name
  for (int i = 0; i < classSize; i++)
    {
      m_classes.at(i)->SortStudents();
    }
  
}

//Name: Start
//Desc: Welcomes users, loadsfile and calls mainmenu
//Precondition: None
//Postcondition: m_classes is populated
void Scheduler::Start()
{
 
  LoadFile(); //loads the .txt file
  cout << "Welcome to the UMBC Scheduler" << endl;
  MainMenu(); //calls main menu to start the UMBC Scheduler
   
}

//Name: FindClass
//Desc: Helper function that searches for a class name in m_classes and
//returns the index of where the Class exists to add the student
//HINT: May want to implement to go backwards through m_classes
//Precondition: None
//Postcondition: Returns the index of the "current" section of a class
int Scheduler::FindClass(string courseName)
{
  //if m_classes is empty, return an index of -1
  if (m_classes.size() == 0)
    {
      return -1;
    }

  //else, for loop that iterates through m_classes backwards to find
  //and return the index of the current section of a class 
  for (int i = m_classes.size()-1; i >=  0; i--)
    {
      //returns index of current section of that class if that index
      //is equivalent to the passed course name
      if (m_classes[i]->GetName() == courseName)
	{
	  return i;
	}
    }

  return 0;
}

//Name: AddStudent
//Desc: Helper function from LoadFile that decides what to do with a new student
//      Scenario 1 - No classes in m_classes - Creates new class and adds
//stud						\ent
//      Scenario 2 - Add Student to existing class where m_roster and m_waitlist
//      are not full
//      Scenario 3 - Add Student when existing class is full ->create new class
//and move m_waitlist to new section
//Precondition: None
//Postcondition: Student added to a class
 
void Scheduler::AddStudent(Student* student, string courseName)
{

  int index = FindClass(courseName); //calls FindClass() using a pased course
                                     //name and stores that information

  //if passed index is -1, create a new class with that passed course name
  //and a section number of 1. Additionally, adds a student in the next
  //index in the m_classes vector using the passed student pointer 
  if (index == -1)
    {

     
      m_classes.push_back(new Class(courseName,1)); //adds new class 
 
      m_classes[index+1]->AddStudent(student); //adds new student 
    }

  //else if index is not -1, check if waitlist is full and is so add a student
  //at the pased index. else, create a new class, transfers all students in
  //the current waitlist to the new class, and adds the new student to that
  //new class 
  else
    {
      //checks if waitlist is full, if not, adds student 
      if(m_classes[index]->IsWaitlistFull() == false)
	{
	  m_classes[index]->AddStudent(student);
	}

      //if waitlist is full 
      else
	{
	  //adds new classs 
	  m_classes.push_back(new Class(courseName,
					m_classes.at(index)->GetSection() + 1));
	  
	  //transfers all students in the current waitlist to the new class 
	  m_classes.at(index)->
	    TransferWaitToRoster(*m_classes.at(m_classes.size() - 1));

	  //adds the new student to the new class 
	  m_classes.at(m_classes.size() -1)->AddStudent(student);
	  
	}
    }
     
      
}
