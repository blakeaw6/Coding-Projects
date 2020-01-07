/*****************************************************************************
 ** File:    Class.h
 ** Project: UMBC Scheduler, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/15/2019
 **
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Class class
 ** 
 ** This class contains a default constructor, an overloaded constructor that 
 ** passes a string name and int section, and a desctructor. 
 ** The DisplayStudents() function is used to display students in m_roster, 
 ** and if there are any, in m_waitlist. It lists all students for a specific 
 ** class and shows the count of students in that class. AddStudent() is 
 ** passed a Student pointer, and adds student to m_roster if there is room, 
 ** and if not, adds student to m_waitlist. If there is no room in m_waitlist, 
 ** a new section is added, the waitlist is moved to the new section, and the
 ** new student is added to that new section. SortStudents() sorts the 
 ** students alphabetically by last name for both the roster and the waitlist.
 ** GetName(), GetSection(), SetName(), and SetSection() are getters and setters
 ** for section and for name. TransferWaitToRoster() is passed a destination 
 ** class, and copies all sutdents in m_waitlist to that class once m_roster 
 ** and m_waitlist are full. IsRosterFull() and IsWaitlistFull() return a 
 ** boolean if either are at there capacity. SearchClass() searches m_roster 
 ** and m_waitlist for a specific string, and displays that information if it 
 ** exists. The ostream& operator<< is the overloaded << operator, and prints 
 ** the Class name and section details for a class. 
 ** Class's private member variables include string m_name, and int m_section,
 ** and two Tqueue's of Student pointers and a max size, called m_roster and 
 ** m_waitlist.
 *****************************************************************************/
#include "Class.h"

//Name: Class
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Class object
Class::Class()
{
  m_name = "CMSC201";
  m_section = 1;
}

//Name: Class
//Desc: Overloaded Constructor
//Precondition: Have name and number
//Postcondition: Creates Class object
Class::Class(string name, int section)
{
  m_name = name;
  m_section = section;
}

//Name: ~Class
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates anything dynamically allocated in a Class
Class::~Class()
{
  int rosterSize = m_roster.Size(); //stores roster size
  int waitlistSize = m_waitlist.Size();  //stores waitlist size

  //for loop that iterates from 0 to roster size, deletes m_roster[i] and sets it
  //equal to nullptr
  for (int i = 0; i < rosterSize; i++)
    {
      delete m_roster[i];
      m_roster[i] = nullptr;
    }

  //for loop that iterates from 0 to waitlist size, deletes m_waitlist[i] and sets it
  //equal to nullptr
  for (int i = 0; i < waitlistSize; i++)
    {
      delete m_waitlist[i];
      m_waitlist[i] = nullptr;
    }  	       
}

//Name: DisplayStudents
//Desc: Displays all students in Class. Displays students in the m_roster
//and if there are students in the m_waitlist, displays them
//Additionally shows count of students in m_roster and count in m_waitlist
//Precondition: Class has students enrolled
//Postcondition: Lists all students for a specific Class
void Class::DisplayStudents()
{
  int rosterSize = m_roster.Size(); //stores roster size
  int waitlistSize = m_waitlist.Size(); //stores waitlist size 

  //if roster size is greater than 0, display the students in the roster 
  if (rosterSize > 0)
    {
      cout << "Enrolled (" << rosterSize << " enrolled)" << endl;
      cout << endl;

      //for loop that displays students in the roster 
      for (int i = 0; i < rosterSize; i++)
	{
	  cout << *m_roster[i] << endl;
	}
    }

  //if waitlist size is greater than 0, display the students in the waitlist
  if (waitlistSize > 0)
    {
      cout << "Waitlisted (" << waitlistSize << " waitlisted)" << endl;

      //for loop that displays the students in the waitlist 
      for (int i = 0; i < waitlistSize; i++)
	{
	  cout << *m_waitlist[i] << endl;
	}
    }
}

//Name: AddStudent
//Desc: A student is added to a Class. If there is room in the m_roster, added
//there. If the m_roster is full, attempts to add student to m_waitlist.
//Else new section added, waitlist moved to new section and new student added.
//Precondition: Class exists
//Postcondition: Adds a student to a Class; returns true if added else false
bool Class::AddStudent(Student* student)
{
  int rosterSize = m_roster.Size();    //stores roster size 
  int waitlistSize = m_waitlist.Size(); //stores waitlist size 

  //if roster size is not equal to roster max, calls Enqueue passing it the student object as a 
  //parameter, returns true
  if(!(rosterSize == ROSTER_MAX))
    {
      m_roster.Enqueue(student);
      return true; 
    }
  //ese if waitlist size is not equal to waitlist max size, calls Enqueue passing it the
  //student object as a paramter 
  else if (!(waitlistSize == WAIT_MAX))
    {
      //cout << "waitlist updated"; 
      m_waitlist.Enqueue(student);
      return true; 
    }
  else
    {
      //cout << "roster and waitlist full, false returned" << endl;
      return false;

    }
}

//Name: Sort
//Desc: Sorts the students alphabetically by last name for both roster and
//waitlist						
//Precondition: None
//Postcondition: m_roster and m_waitlist are sorted
void Class::SortStudents()
{
  //if roster size is greater than 1, calls Sort() on m_roster 
  if (m_roster.Size() > 1)
    {
      m_roster.Sort();
    }

  //if waitlist size is greater than 1, calls Sort() on m_waitlist
  if (m_waitlist.Size() > 1)
    {
      m_waitlist.Sort();
    }
}

//Name: GetName
//Desc: Returns name of Class
//Precondition: None
//Postcondition: Class name is returned
string Class::GetName()
{
  return m_name;
}

//Name: GetSection
//Desc: Returns section of Class
//Precondition: None
//Postcondition: Class section is returned
int Class::GetSection()
{
  return m_section;
}

//Name: SetName
//Desc: Allows Class name to be set
//Precondition: name is a valid string
//Postcondition: Class name is updated
void Class::SetName(string name)
{
  m_name = name;
}

//Name: SetSection
//Desc: Allows Class section to be set
//Precondition: section is a valid integer
//Postcondition: Class section is updated
void Class::SetSection(int section)
{
  m_section = section;
}

//Name: TransferWaitToRoster
//Desc: When an m_roster is full and m_waitlist is full, copies all students in
//m_waitlist to a destination Class
//Precondition: m_waitlist is full
//Postcondition: m_waitlist is empty and all students were transferred to new 
//Class
void Class::TransferWaitToRoster(Class& destination)
{
  int waitlistSize = m_waitlist.Size(); //stores waitlist size

  //for loop that iterates from 0 to waitlist size, calls Enqueue() and passses it m_waitlist[i]
  //as a parameter, copying the student data to the destination class 
  for(int i = 0; i < waitlistSize; i++)
    {
      destination.m_roster.Enqueue(m_waitlist[i]);
    }

  //for loop that iteratres through 0 to waitlist size, calls Dequeue on m_waitlist
  for (int i = 0; i < waitlistSize; i++)
    {
      m_waitlist.Dequeue();
    }
}

//Name: IsRosterFull()
//Desc: Returns bool of if the m_roster is at capacity
//Precondition: None
//Postcondition: Returns bool
bool Class::IsRosterFull()
{
  int rosterSize = m_roster.Size(); //stores size of roster 

  //if roster size is equal to max roster size, returns true
  if (rosterSize == ROSTER_MAX)
    {
      return true;
    }
  return false;
  
}

//Name: IsWaitlistFull()
//Desc: Returns bool of if the m_waitlist is at capacity
//Precondition: None
//Postcondition: Returns bool
bool Class::IsWaitlistFull()
{
  int waitlistSize = m_waitlist.Size(); //stores size of waitlist

  //if waitlist size is equal to max size, returns true 
  if (waitlistSize == WAIT_MAX)
    {
      return true;
    }
  return false;
}

//Name: SearchClass
//Desc: Searches m_roster and m_waitlist for a string.
//If string exists in m_roster or m_waitlist, Class information printed
//Precondition: None
//Postcondition: Returns bool
bool Class::SearchClass(string item)
{
  bool nameBool; //boolean for name 

  int rosterSize = m_roster.Size(); //stores roster size

  //for loop that iterates between 0 and roster size
  for (int i = 0; i < rosterSize; i++)
    {
      //if the passed item name is equal to the either the first or last name of the name in m_roster[i],
      //displays that name and sets the name boolean equal to true 
      if ((item == m_roster[i]->GetFName()) || (item == m_roster[i]->GetLName()))
	{
	  cout << *this;
	  nameBool = true;
	}
    }
  return nameBool;
}

// Name: Overloaded <<
// Description: Prints the details of a Class (Class name and section)
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of the Class
ostream& operator<<(ostream& os, Class& cls)
{
  //overloaded << operator that displays the name and section of the class, returns the ostream object
  os << "Name: " << cls.m_name << " " << "Section: " << cls.m_section << endl;
  os << endl;
  return os; 
}
