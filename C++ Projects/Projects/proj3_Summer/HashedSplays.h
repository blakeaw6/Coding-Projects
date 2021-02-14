///CMSC 341 - Summer 2020 - Project 3
///File: HasedSplay.h
///Author: Blake Wishard

#ifndef HASHED_SPLAY_H
#define HASHED_SPLAY_H

#include "SplayTree.h"
#include "Node.h"
#include <vector>

using namespace std;


const int ALPHABET_SIZE = 26; //const for size of array

class HashedSplays {
public:
    ///default constructor
    HashedSplays();

    ///overloaded constructor
    HashedSplays(int size);

    ///reads the file input from the .txt file
    void FileReader(string inFileName);

    ///displays the Splay tree to the terminal, at the passed index
    void PrintTree(int index);

    ///displays the Splay tree to the terminal, at the index of the passed letter
    void PrintTree(string letter);

    ///prints the root value at each index of the array, along with the number
    //of nodes that the Splay Tree at that index contains
    void PrintHashCountResults();

    ///used to find words within a certain tree index, displays them infix order.
    ///similar to predictive texting
    void FindAll(string inPart);

    ///converts the passed letter to it's equivalent numerical value
    int GetIndex(string inLetter);

    

private:

    SplayTree<Node> _table[ALPHABET_SIZE]; //an array of size 26 that holds a Splay Tree of nodes at each index.
    //each index hold all of the nodes containing its equivalent letter of the alphabet

    const char _alphaArray[ALPHABET_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //an array that holds the alphabetical values equivalent to each of the 26 indexes in the _table array

    int _nodeCount; //used to hold the number of nodes in each splay tree
    
    int m_trees;
};

#endif