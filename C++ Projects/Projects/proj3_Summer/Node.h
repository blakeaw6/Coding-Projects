///CMSC 341 - Summer 2020 - Project 3
///File: Node.h
///Author: Blake Wishard

#ifndef NODE_H
#define NODE_H

#include "Util.h" // For some string functions
#include <sstream>

using namespace std;

class Node {
public:
    ///default constructor
    Node();

    ///overloaded constructor
    ///PreCondition: Word (string) and frequency for bulding a node
    ///PostCondition:  Node with word and frequency
    Node(string inWord, int frequency);

    ///Destructor
    ~Node();

    ///GetWord - string value of the Node
    string GetWord() const;

    ///Gets the word frequency
    int GetFrequency() const;

    ///increments the word's frequency by 1
    void IncrementFrequency();

    ///Overload operator <
    ///PreCondition: Valid node objects to compare
    ///PostCondition:  Bool.  True if the word value is less.
    bool operator<(const Node &RHS) const;

    ///Overload operator ==
    ///PreCondition: Valid node objects to compare
    ///PostCondition:  Bool.  True if the word values are equal.
    bool operator==(const Node &RHS);

    ///Overload operator =
    ///PreCondition: Valid node objects to compare
    ///PostCondition:  New node via a deep copy.
    Node operator=(const Node &RHS);

    ///Overload operator %
    ///PreCondition: Valid node objects to compare
    ///PostCondition:  Bool.  True if the word in this object is a
    ///leading SUBSTRING of the compared node.
    bool operator%(const Node &RHS) const;

    ///Overload operator << (Friend)
    ///PreCondition: Valid node to output
    ///PostCondition: Formated output of the word and frequency.
    friend std::ostream &operator<<(std::ostream &out, const Node &inNode);

private:
    string m_word;      ///the word
    int m_frequency;    ///how often the word has appeared.
};

#endif