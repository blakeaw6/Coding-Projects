/*****************************************************************************
 ** File:    Student.cpp
 ** Project: UMBC Scheduler, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/15/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Student class
 *****************************************************************************/
#include "Student.h"

// Name: Student
// Description: Default Constructor
// Preconditions: None
// Postconditions: Creates new student object
Student::Student()
{
  m_fName = " ";
  m_lName = " ";
  m_id = 0; 
}

// Name: Student (fName, lName, id)
// Description: Overloaded Constructor
// Preconditions: Data being passed is valid
// Postconditions: Creates new student object
Student::Student(string fName, string lName, int id)
{
  m_fName = fName;
  m_lName = lName;
  m_id = id;
}

//Getter for FName
string Student::GetFName()
{
  return m_fName;
}

//Getter for LName
string Student::GetLName()
{
  return m_lName;
}

//Getter for id
int Student::GetID()
{
  return m_id;
}

//Setter for FName
void Student::SetFName(string fName)
{
  m_fName = fName;
}

//Setter for LName
void Student::SetLName(string lName)
{
  m_lName = lName;
}

//Setter for id
void Student::SetID(int id)
{
  m_id = id;
}

// Name: Overloaded <<
// Description: Prints the details of a student
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of student
ostream& operator<<(ostream& os, Student& stu)
{
  //uses the overloaded << operator to display the students last name
  //and first name
  os << stu.GetLName() << "," << stu.GetFName() << endl;
  return os;
}

// Name: Overloaded <
// Description: Overloaded comparison operator (used for sorting)
// Preconditions: Two students being compared
// Postconditions: Returns m_lName first and then m_fName if m_lName same
bool operator< (const Student &s1, const Student &s2)
{
  //if students1's last name is equal to student2's last name,
  //uses overloaded < operator to return the comparison 
  if (s1.m_lName == s2.m_lName) 
    {
      return (s1.m_fName < s2.m_fName);
    }    
  return (s1.m_lName < s2.m_lName);
    
  
}
