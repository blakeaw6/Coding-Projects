/*
File: stack.h - a templated, linked list-based stack implementation
Author: Blake Wishard
Class: CMSC 341
Purpose: Project 0
Professor: Shawn Lupoli
Due Date: 5/29/20
*/


// Assignment:
//   (1) Complete the copy constructor
//   (2) Complete the assignment operator
//   (3) Complete the destructor
//   (4) Write a test program (mytest.cpp) to test copy and assignment
//   (5) Verify destructor by running the test program in Valgrind

#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <exception>

using std::ostream;
using std::cout;
using std::endl;
using std::range_error;

// Forward declarations
template <class T> class Stack;
template <class T> class Node;
template <class T> ostream& operator<<(ostream&, const Node<T>&);

// Node class for linked list
template <class T>
class Node {

  friend Stack<T>;
  
public:
  Node(T data = T(), Node<T> *next = nullptr) {
    _data = data;
    _next = next;
  }

  friend ostream& operator<< <T>(ostream &sout, const Node<T> &x);
  
private:
  T _data;
  Node *_next;
};

// Overloaded insertion operator.  Must be overloaded for the template
// class T, or this won't work!
template <class T>
ostream& operator<<(ostream &sout, const Node<T> &x) {
  sout << "Data: " << x._data;
  return sout;
}


// Stack class.  Linked-list implementation of a stack. Uses the Node
// class.
template <class T>
class Stack {
public:
  // Constructor
  Stack();

  // Copy constructor, assignment operator, and destructor
  // DO NOT IMPLEMENT HERE.  SEE BELOW.
  Stack(const Stack &rhs);
  const Stack& operator=(const Stack& rhs);
  ~Stack();

  // Stack operations: push(), top(), and pop()
  void push(const T& data);
  const T& top() const;
  void pop();

  // Helpful functions
  bool empty() const;  // Returns 'true' if stack is empty
  void dump() const;   // Dump contents of the linked list

private:
  Node<T> *_head;

  void ClearData(); 
  
};

//constructor
template <class T>
Stack<T>::Stack() {
  _head = nullptr;
}

//copy constructor 
template <class T>
Stack<T>::Stack(const Stack<T>& rhs) {

    _head = nullptr;

    //checks if the rhs stack to copy from is empty 
    if (!(rhs.empty())) { 
        ClearData();   //de-allocates memory in stack
        _head = new Node<T>(rhs._head->_data); //inserts data from rhs stack into the head node 
        Node<T> *temp = _head->_next; //creates a new Node temp to store the data after the head node

        //iterates thorugh stack and copies the data from the rhs stack into the new stack
        for (Node<T> *curr = rhs._head; curr != nullptr; curr = curr->_next) {
            temp = new Node<T>(curr->_data); //sets temp equal to the data in the curr pointer  
            temp = temp->_next; //moves temp pointer 
        }
    }
}

//assignement operator 
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {

    //checks to make sure it is not copying into the same rhs stack
    if (this != &rhs) { 
        ClearData();    //de-allocates data in new stack

        //checks to see if the rhs head pointer is equal to nullptr and returns reference to object if true 
        if (rhs._head == nullptr) {
            return *this; //returns reference to object
        }
        _head = new Node<T>(rhs._head->_data); //inserts data from rhs stack into head 
        Node<T> *temp = _head; //creates new node temp and sets it equal to head pointer    

        //iteratres through stack and copies the data from the rhs stack into the new stack
        for (Node<T> *curr = rhs._head->_next; curr != nullptr; curr = curr->_next) {
            temp->_next = new Node<T>(curr->_data); //sets temp pointer equal to the  data in the curr pointer
            temp = temp->_next; //moves temp pointer 
        }
        temp->_next = nullptr;
    }
    return *this; //returns reference to object 

}

//destructor 
template <class T>
Stack<T>::~Stack() {
    ClearData(); //Calls ClearData() function to deallocate all memory in the stack
}

template <class T>
void Stack<T>::push(const T& data) {
  Node<T> *tmpPtr = new Node<T>(data);
  tmpPtr->_next = _head;
  _head = tmpPtr;
}

template <class T>
const T& Stack<T>::top() const {
  if ( empty() ) {
    throw range_error("Stack<T>::top(): attempt to read empty stack.");
  }

  return _head->_data;
}

template <class T>
void Stack<T>::pop() {
  if ( empty() ) {
    throw range_error("Stack<T>::pop(): attempt to pop from an empty stack.");
  }

  Node<T> *tmpPtr = _head->_next;
  delete _head;
  _head = tmpPtr;
}

template <class T>
bool Stack<T>::empty() const {
  return _head == nullptr;
}

template <class T>
void Stack<T>::dump() const {
  Node<T> *nodePtr = _head;
  while ( nodePtr != nullptr ) {
    cout << nodePtr->_data << endl;
    nodePtr = nodePtr->_next;
  }
}

template<class T> 
void Stack<T>::ClearData() {

    if(_head == nullptr) {
        return;
    }

    Node<T> *temp = _head->_next;

    while(temp != nullptr) {
        delete _head;
        _head = temp;
        temp = _head->_next;
    }
    delete _head;
    _head = nullptr;
}   

#endif