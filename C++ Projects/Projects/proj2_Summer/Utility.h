//Utility.h
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "Word.h"
#include "BinarySearchTree.h"
#include "Indexer.h"

using namespace std;

class Utility {
public:

    Utility() {

    }
    Utility(string inString);

    static string Upper(string inString);

    static string Lower(string inString);

    static string hasPunc(string inString);

private:
    string _text;
};



#endif