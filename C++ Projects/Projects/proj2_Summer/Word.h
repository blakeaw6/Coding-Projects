///CMSC 341 - Summer 2020 - Project 2
//File: Word.h
//Author: Blake Wishard

#ifndef WORD_H
#define WORD_H

#include <queue>
#include <iostream>
#include "BinarySearchTree.h"
#include <iomanip>

using namespace std;

class Word
{
public:
    //default constructor 
    Word();

    //overloaded constructor
    Word(string inWord, int lineNumber);
    
    //destructor
    ~Word(); 

    //increments the Word's occurence, and 
    //and this unique value to the queue. 
    //adds only once if 
    void CountWord(int lineNumber);

    ///retuns _wordText as a string
    string GetWord();
     
    ///returns the Word Count
    int GetCount(); 

    ///returns the line number 
    int GetLineNum();

    //overloaded == operator, for comparing two strings
    bool operator==(const Word &rhs);

    //overloaded < operator for comparing two strings
    bool operator<(const Word &rhs) const;

    //ostream pverloaded << operator for printing results
    friend ostream& operator<<(ostream &out, Word &inWord);

private:
    int _count; //the amount of times the Word appears in the file
    int _lineNum; //the line number the Word is found on
    string _wordText; //the text for the Word
    queue<int> _lineNumbers; //a queue of ints that stores each line number the Word occured on
};

#endif