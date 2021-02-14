///CMSC 341 - Summer 2020 - Project 2
//File: Word.cpp
//Author: Blake Wishard

//very basic class that holds an instance of a word and it's frequency
//the Word's frequency and word is given IMMEDIATELY in the file
#include <iostream>
#include "Word.h"

///default constructor
Word::Word() {
    _wordText = " "; //initializes _wordText
    _count = 0; //initializes _count
    _lineNum = 0; //initializes _linNum
}

///overloaded constructor
Word::Word(string inWord, int lineNumber) {
    _wordText = inWord; //initializes _wordText
    _lineNum = lineNumber; //initializes _lineNum
    _count = 0; //initializes _count
}

//destructor 
Word::~Word() {
}

///increments the word's occurence
///adds this unique value to the queue, adds only once if in the same line
void Word::CountWord(int lineNumber) {
    ///if the Word has been added to the BST for the first time,
    ///increase count number
    if (_count == 0) {
        _count++; ///increases Word count
        _lineNumbers.push(lineNumber); ///adds unique line number to Word queue
        _lineNum = lineNumber; ///sets passed line number
      return;
    }
    ///if the Word occurs multiple times on the same line, don't re-add line number to Word queue,
    ///simply increase count and set line number
    if (lineNumber == _lineNumbers.back()) {
        _count++; ///increase Word count
        _lineNum = lineNumber; ///sets passed line number
        return;
    }
    ///else, if that line number has not been already inserted to the queue
    else {
        _count++; ///increases Word count
        _lineNumbers.push(lineNumber); ///adds unique line number to the queue
        _lineNum = lineNumber; ///sets passed line number
        return;
    }
}

//returns the text for the Word
string Word::GetWord() {//
    return _wordText;
}

//returns Word count
int Word::GetCount() {
    return _count; 
}

//returns the current line number for the Word
int Word::GetLineNum() {
    return _lineNum;
}

//overloaded == operator
bool Word::operator==(const Word &rhs) {
    return (rhs._wordText == _wordText);
}

//overloaded < operator
bool Word::operator<(const Word &rhs) const {
    return (_wordText < rhs._wordText);
}

//overloaded << operator 
ostream &operator<<(ostream &out, Word &inWord) {
    string word = inWord.GetWord();  //string to store the _wordText
    int digits = inWord.GetCount();  //int to store the _count

    int count = 0; //stores the number of digits in _count
    ///find the number of digits in _count
    while (digits != 0) {
        digits = digits / 10; //divides the _count by 10 
        count++; //increases count for number of digits
    }

    int periodCount = 24 - word.size() - count; //used to format output in .txt file

    //prints the formatted output to the output
    out << inWord._wordText << setfill('.') << setw(periodCount) << right << "" << inWord._count << ": ";

    int size = inWord._lineNumbers.size(); //gets the size of the queue 

    //loops through and prints the line number in the queue to the output.txt file
    for (int i = 0; i < size; i++) {
        out << " " << inWord._lineNumbers.front(); //prints front of queue 
        inWord._lineNumbers.pop(); //pops front of queue 

    }
    return out;
}


