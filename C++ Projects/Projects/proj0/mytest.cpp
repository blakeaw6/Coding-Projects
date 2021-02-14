/*
File: mytest.cpp - Test file for stack.h
Author: Blake Wishard
Class: CMSC 341
Purpose: Project 0
Professor: Shawn Lupoli
Due Date: 5/29/20
*/

#include "stack.h"
#include <iostream>

using namespace std;

//main method
int main() {
    Stack<int> intStack; //creates new stack

    //adds data to stack
    cout << "\nPush integers on stack and dump contents:\n";
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }

    intStack.dump(); //displays data in stack

    //displays data using top() and removes it using pop()
    cout << "\nRead contents using top() and pop():\n";
    while (not intStack.empty()) {
        cout << intStack.top() << endl;
        intStack.pop();
    }

    //attempts to pop an empty stack, catches exception if the stack is empty
    cout << "\nAttempt pop() of empty stack:\n";
    try {
        intStack.pop();
    } catch (exception &e) {
        cout << "Caught exception:\n" << e.what() << endl << endl;
    }

    //Copy Constructor
    cout << "Testing Copy Constructor..." << endl << endl;
    Stack<int> intStack2(intStack); //creates intStack2 and copies intStack to it
    intStack2.dump(); //prints intStack2

    //Assignment Operator
    cout << "Testing Assignment Operator..." << endl << endl;
    Stack<int> intStack3; //creates intStack3
    intStack3 = intStack; //copies intStack to intStack3
    intStack3.dump(); //prints intStack3

    //Push new data to all three stacks
    cout << "Pushing new data to all three stacks" << endl << endl;
    intStack.push(10);
    intStack2.push(100);
    intStack3.push(1000);

    //prints out all of the stack data
    cout << "-----Should print out 10, 100, 1000----" << endl << endl;
    intStack.dump();
    intStack2.dump();
    intStack3.dump();
    cout << endl;

    //Push more random data
    cout << "Pushing more data..." << endl << endl;
    intStack.push(300);
    intStack2.push(400);
    intStack3.push(500);

    cout << "----Should print out 300, 10----" << endl << endl;
    intStack.dump();
    cout << endl;

    cout << "----Should print out 400, 100----" << endl << endl;
    intStack2.dump();
    cout << endl;

    cout << "----Should print out 500, 1000----" << endl << endl;
    intStack3.dump();
    cout << endl;

    //Pop - removes data from top of each stack
    intStack.pop();
    intStack2.pop();
    intStack3.pop();

    //Prints out original stack
    cout << "Printing original stack data..." << endl << endl;
    cout << "----Should print out 10, 100, 1000" << endl << endl;
    intStack.dump();
    intStack2.dump();
    intStack3.dump();

    intStack.pop(); 
    intStack.dump();

    cout << endl << "Testing complete!" << endl << endl;

    return 0;
}





