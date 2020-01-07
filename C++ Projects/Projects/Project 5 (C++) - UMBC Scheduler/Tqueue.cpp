/******************************************************************************
 ** File:    Tqueue.cpp
 ** Project: UMBC Scheduler, Fall 2019
 ** Author:  Blake Wishard
 ** Date     11/15/2019
 ** Section: 21
 ** E-mail:  blakew1@umbc.edu
 ** This file contains the Tqueue templated class.
 ** 
 ** This class contains a Templated Queue, used to manage each Classes roster 
 ** and waitlist. It stores Student pointers. It is a dynamically allocated 
 ** array, and has a passed maximum capactiy of N. 
 ** This class contains a default, copy, and overloaded constructor. It also 
 ** has a destructor. It contains the functions ClearData(), which is used to 
 ** empty m_data, and is called by the desctructor. Enqueue() is a function 
 ** used to add an item to the back of th queue. Dequeue() is used to remove 
 ** an item from the front of the queue. Sort() is used to alphabetically 
 ** sort the contents of Tqueue. IsEmpty() checks to se if the queue is empty 
 ** or not. IsFull() checks to see if the queue is full. Size() returns the 
 ** size of the queue. The Overloaded assignment operator is used to set 
 ** one Tqueue to the same as the second Tqueue using =. The Overloaded [] 
 ** operator is used to pull data from queue and return it using []. 
 ** Tqueue's private member variables include m_front and m_back, used to store
 ** the data at the front and back of the queue, and T* m_data, which is a 
 ** dynamically allocated array that holds the data in the queue 
 *****************************************************************************/

#ifndef TQUEUE_CPP //header guard
#define TQUEUE_CPP //header guard 

#include <iostream>
#include <cstdlib>
using namespace std;

//template definition for class Tqueue
template <class T, int N>
class Tqueue {
public:
  
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
 
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor

  //Name: Destructor
  //Desc: Empties m_dataint rosterSize = m_roster.Size();
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor

  //Name: ClearData
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Empty m_data
  void ClearData();

  //Name: Enqueue 
  //Desc: Adds item to the back of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Enqueue(T data); //Adds item to queue (to back)
 
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //Precondition: Existing Tqueueint rosterSize = m_roster.Size();
  //Postcondition: Returns true if successful else false
  void Dequeue();

  //Name: Sort
  //Desc: Sorts the contents of the Tqueue
  //NOTE: You may implement to only deal with dereferenced pointers
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (ascending)
  void Sort();

  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0

  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0

  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int Size();

  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator
                                          //for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
  
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//*** class definitions ****

//Default Constructor 
template <class T, int N>
Tqueue<T, N>::Tqueue()
{
  m_data = new T[N]; 
  m_front = 0;
  m_back = 0;
}

//Copy Constructor
template <class T, int N>
Tqueue<T, N>::Tqueue(const Tqueue<T,N>& x)
{
  m_front = x.m_front; //copies m_front 
  m_back = x.m_back; //copies m_back 
  m_data = new T[N]; //creates a new T array of N size

  //for loop used to m_data to new T array 
  for (int i = 0; i < N; i++)
    {
      m_data[i] = x.m_data[i];
    }
}

//Enqueue
template <class T, int N>
void Tqueue<T, N>::Enqueue(T data) //Adds item to queue (to back)
{
  //if Tqueue is at max capacity, let the user know and return
  if (N == m_back)
    {
      cout << "Tqueue is full!" << endl;
      return;
    }
  //else, add item to back of queue, increase size of m_back
  else
    {
      m_data[m_back] = data;
      m_back++;
    }
  return; 
}

//Destructor
template <class T, int N>
Tqueue<T, N>::~Tqueue()
{
  //calls clear data
  ClearData();  
}

//Size() 
template <class T, int N>
int Tqueue<T, N>::Size()
{
  return (m_back - m_front); //returns size of Tqueue 
}

//Overloaded assignment operator
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=(Tqueue<T,N> y)
{
  m_front = 0;
  m_back = 0;

  //if 'this' pointer is not equal to the passed parameter y
  if (this != &y)
    {
      //for loop that copies and inserts y.m_data[i] into m_data[i],
      //increases size of m_back
      for (int i = 0; i < N; i++)
	{
	  m_data[i] = y.m_data[i];
	  m_back++;
	}
    }
  //returns value of 'this' pointer
  return *this;    
}

//Dequeue
template <class T, int N>
void Tqueue<T,N>::Dequeue()
{
  //if Tqueue is empty, let user know 
  if (m_front == m_back)
    {
      cout << "The queue is empty!" << endl;
    }
  //else, removes item from front of queue, decreases size of m_back
  else
    {
      for (int i = 0; i < N-1; i++)
	{
	  m_data[i] = m_data[i+1]; 
	}
      m_back--;
    }  
}

//overloaded [] operator
template <class T, int N>
T& Tqueue<T,N>::operator[] (int x)
{
  //returns m_data at passed parameter 
  return m_data[x];
}

//IsEmpty()
template <class T, int N>
int Tqueue<T, N>::IsEmpty()
{
  //checks if Tqueue is empty or not, returns 1 if empty, 0 if not
  return (m_back == m_front);
}

//ClearData()
template <class T, int N>
void Tqueue<T, N>::ClearData()
{
  //deallocates dynamically allocated m_data array
  delete [] m_data;
  m_data = nullptr;
  m_front = 0;
  m_back = 0;
    
}


//Sort()
template <class T, int N>
void Tqueue<T, N>::Sort()
{
  //for loop that sorts through rows of Tqueue
  for (int i = 0; i < Size()-1; i++)
    { //for loop that sorts through columns of Tqueue 
      for (int j = 0; j < Size()-1-i; j++)
	{
	  //if statement that used to sort through Tqueue alphabetically
	  if (*m_data[j+1] < *m_data[j])
	    {
	      T temp = m_data[j];
	      m_data[j] = m_data[j+1];
	      m_data[j+1] = temp;
	    }
	}
    }
}

//IsFull()
template <class T, int N>
int Tqueue<T, N>::IsFull()
{
  //returns if Tqueue is full, if size of queue is same as max capactiy
  return m_back-m_front == N;
}
	      


/*
***Tests left in for testing purposes***
// To test just Lqueue follow these instructions:
//   1.  Uncomment out int main below
//   2.  make Tqueue
//   3.  ./Tqueue (try valgrind too!)

int main () {
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Tqueue <int, 10> newTQ1;
  cout << "after default runs" << endl;
  //Push 4 nodes into Lqueue
  newTQ1.Enqueue(10);
  newTQ1.Enqueue(20);
  newTQ1.Enqueue(30);
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Tqueue <int, 10> newTQ2(newTQ1);
  
  //Test Overloaded Assignment Operator
  Tqueue <int, 10> newTQ3;
  newTQ3 = newTQ1;
  cout << endl;
 

  //Test 3 - Test Dequeue
  cout << "Test 3 - Dequeue" << endl;
  newTQ1.Dequeue();
  cout << endl;

  //Test 4 - Test Overloaded []
  cout << "Test 4 - Test Overloaded []" << endl;
  for(int i = 0; i < newTQ1.Size(); i++){
    cout << newTQ1[i] << endl;
  }

  //Test 5 - Test Size and ClearData
  cout << "Test 5 - Size and ClearData" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newTQ1.ClearData();
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  cout << endl;
  
  return 0;
}
*/
#endif
