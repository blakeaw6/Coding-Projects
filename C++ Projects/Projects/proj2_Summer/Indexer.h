///CMSC 341 - Summer 2020 - Project 2
///File: Indexer.h
///Author: Blake Wishard

#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include "BinarySearchTree.h"
#include "Word.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>
using namespace std;

///defines Indexer Class
class Indexer {
    ///public functions
public:
    ///default constructor for Indexer
    Indexer();

    ///overloaded constructor for Indexer
    Indexer(string filterFile, string dataFile);

    ///destructor
   ~Indexer();

    ///clears data 
    void  ClearIndex(); 

    ///calls functions to open the input files and builds the BSTs,
    /// and output the results to .txt files
    void DoIndex();

    ///opens the filtered text file and builds the filtered BST
    void FileFilterReader(string filename);

    ///opens the data input file file and builds the indexed BST
    void FileWordReader(string filename);

    ///outputs the results of the BSTs
    void PrintBST();

    ///attempts to insert a Word into the indexed BST
    bool InsertWord(Word *temp);

    ///checks/converts a Word with punctuation to lower case
    static string HasPunc(string text);

    ///ouputs the results of the BSTs to .txt files
    void OutputResults(); 

    ///private member variables
private:
    string _filterFile; ///holds the filtered .txt file
    string _dataFile; ///holds the input file to be indexed

    BinarySearchTree<Word> *_filteredBST; ///BST of Word pointer to the filtered BST
    BinarySearchTree<Word> *_indexedBST; ///BST of Word pointer to the indexed BST

    bool _puncConverted; ///checks to see if a Word with punctuation has been checked/converted to lower case
    bool _isLower; ///checks to see is a Word has been checked/converted to lower case
    bool _wasAdded; ///checks to see if a Word has been added to the indexed BST, or if it's _count has been updated
};
#endif