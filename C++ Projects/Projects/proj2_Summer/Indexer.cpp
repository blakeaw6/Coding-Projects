///CMSC 341 - Summer 2020 - Project 2
///File: Indexer.cpp
///Author: Blake Wishard

#include <iostream>
#include "Indexer.h"
#include <fstream>

//default constructor
Indexer::Indexer() {
    _filterFile = " ";
    _dataFile = " ";
    _filteredBST = nullptr;
    _indexedBST = nullptr;
    _puncConverted = false;
    _isLower = false;
    _wasAdded = false;
}

//overloaded constructor
Indexer::Indexer(string filterFile, string dataFile) {
    _filterFile = filterFile;
    _dataFile = dataFile;
    _filteredBST = nullptr;
    _indexedBST = nullptr;
    _puncConverted = false;
    _isLower = false;
    _wasAdded = false;
}

//destructor 
Indexer::~Indexer() { 
    ClearIndex();  //deallocates data 
}

//deallocates data
void Indexer::ClearIndex() {

    ///check if empty
    if (_filteredBST->isEmpty()) {
        return; 
    }   

    delete _filteredBST; 
    
    //check if empty
    if (_indexedBST->isEmpty()) {
        return; 
    }
    delete _indexedBST;
}

//BinarySearchTree<Word> *temp = _indexedBST->root;

///builds the BSTs, and outputs the results to .txt files
void Indexer::DoIndex() {
    FileFilterReader(_filterFile); ///build filtered BST
    FileWordReader(_dataFile); ///build indexed BST
    OutputResults(); ///output BSTs to .txt files
}

///opens the filtered file and places those words into the filtered BST
void Indexer::FileFilterReader(string filename) {
    ifstream file1; ///declares file io stream
    file1.open(filename); ///open the command line inputted filename
    int lineCount = 0; ///sets the line count
    ///checks to make sure file exists and is open
    if (file1.is_open()) {
        _filteredBST = new BinarySearchTree<Word>; //creates new filtered BST
        string text; ///stores string data for the Word

        ///while there are still lines in the .txt file to be read...
        ///reads file from line until new line character and stores the data in the text string
        while (getline(file1, text)) {
            lineCount++; ///increases the line count
            Word *temp = new Word(text, lineCount); ///creates a new Word passing it the text and line number
            _filteredBST->insert(*temp); ///inserts the Word into the filtered BST
            delete temp;
        }
        file1.close(); ///closes the file
        return;
    } else {
        cout << "error opening file" << endl;
        return;
    }
}

///opens the input file of words to be indexed
///places each word into the indexed BST, and lists them alphabetically
void Indexer::FileWordReader(string filename) {
    ifstream file2; ///declares the filterd file
    file2.open(filename); ///opens filtered file
    int lineCount = 0; /// sets the line count
    ///checks to make sure the file exists and is open
    if (file2.is_open()) {
        _indexedBST = new BinarySearchTree<Word>; ///creates a new indexed BST
        string textHolder = " "; ///holds the text for a given line in the file

        ///while there are still lines in the .txt file to be read...
        ///reads file from line until new line character and stores the data in the text string
        while (getline(file2, textHolder, '\n')) {
            lineCount++; ///increases line count
            char delim1 = '-'; ///used to see if it is intra-word hyphen or regular punctuation

            ///iterates through each character in a given line
            for (int i = 0, len = textHolder.size(); i < len; i++) {
                ///checks to see if the current character is a punctuation symbol, but not a hyphen or apostrophe
                ///if the above criteria is met, erases that character and decreases
                if ((ispunct(textHolder[i])) && (textHolder[i] != delim1)) { // && textHolder[i] != delim2)) {
                    textHolder[i] = ' ';
                    len = textHolder.size(); ///resets the length
                }
                    ///if the character is a hyphen, check to see if it is a intra-word hyphen or not
                else if ((textHolder[i] == delim1)) { //|| (textHolder[i] == delim2)) {
                    ///check if it there is a char directly on either side of it
                    ///if not, then erase that hyphen
                    if (isalpha(textHolder[i - 1]) && (isalpha(textHolder[i + 1]))) {
                    } else {
                        textHolder.erase(i--, 1); ///deletes the character
                        len = textHolder.size(); ///resets the length
                    }
                } else {
                    ///empty
                }
            }

            //cout << "new line =" << textHolder << endl;
            istringstream ss(textHolder); ///checks each word in the given line, and attempts to insert that word into the indexed BST
            string word = ""; ///stores data in line

            ///while there is still words in the given line to be read...
            ///uses extraction operator to read in data from given line into the string word
            while (ss >> word) {
                _wasAdded = false; ///resets the _wasAdded bool
                Word *temp = new Word(word, lineCount);///creates new Word passing it word and the line count
                InsertWord(temp); ///attempts to insert the word into the indexed BST
                delete temp;
            }
        }
    }
}

//attempts to insert a word into the indexed BST
bool Indexer::InsertWord(Word *temp) {
    ///checks to see if the Word has been added to the indexed BST
    if (_wasAdded) {
        return true;
    }

    string text = temp->GetWord(); ///stores the Word text
    int lineNumber = temp->GetLineNum(); ///stores the Word line nubmer
    char delim1 = '-'; ///escape sequence for the - delimeter

    ///check to see if Word has hyphen or apostrophe, or has already been checked/converted to lower case
    if (!(_puncConverted)) { // && (!(_isLower))) {
        ///iterates through each character in the Word
        for (long unsigned int i = 0; i < text.size(); i++) {
            if (text[i] == delim1) { //|| text[i] == delim2) {
                text = HasPunc(text); ///calls the HasPunc function passing it the word that has the punctuation
                _puncConverted = true; ///indicates that the word with puncuation has been converted to lower case
                Word *temp = new Word(text, lineNumber); ///creates a new Word with the newly lower-case word
                return InsertWord(temp); ///recursively calls the InsertWord() function, attempting to insert the new Word
                delete temp;
            }
        }
    }
    
    ///checks the Word for lower case
    if (!(_puncConverted) && (!(_isLower))) {
        ///iterates through each character in the Word and checks to see if they are all lower case
        if (all_of(text.begin(), text.end(), &::islower)) {
            _isLower = true; ///indicates that the Word is completely lower case
            return InsertWord(temp); //recursively calls InsertWord()
        }
            ///else, converts the Word to lower case
        else {
            ///iterates through each character in the Word and sets each character to lower case
            for_each(text.begin(), text.end(), [](char &c) {
                c = ::tolower(c); ///sets given charcter to lower case
            });
            _isLower = true; ///indicates the Word is now lower case
            Word *temp = new Word(text, lineNumber); ///creates a new Word passing it the lower case word
            return InsertWord(temp); ///recursively calls the InsertWord() function, attempting to insert the new Word
            delete temp;
        }
    }
    ///if the word has been checked/converted to lower case, attempt to insert it
    if (_puncConverted || _isLower) {
        ///check to see if the Word is not in the filtered words list
        if (!(_filteredBST->contains(*temp))) {
            ///check to see if the Word is a duplicate word. If not, insert Word
            if (!(_indexedBST->contains(*temp))) {
                temp->CountWord(lineNumber);  ///calls CountWord() to increase the count and store the line number
                _indexedBST->insert(*temp); ///inserts word into BST
                _puncConverted = false; ///resets _puncConverted bool
                _isLower = false; ///resets _isLower bool
                _wasAdded = true; ///resets _wasAddedBool;
            }
                ///if the Word is a duplicate, update _count and insert line number, but don't re-add word
            else {
                temp = _indexedBST->containsNode(*temp); ///grabs original node for the Word
                temp->CountWord(lineNumber); ///increases the _count and inserts the line number
                _puncConverted = false;  ///resets _puncConverted bool
                _isLower = false; ///resets _isLower bool
                _wasAdded = true; ///resets _wasAddedBool;
                return InsertWord(temp); ///recursively calls InsertWord()
                delete temp;
            }
        }
            ///else, filtered word, reset bools
        else {
            _isLower = false; ///resets _isLower bool
            _puncConverted = false; ///resets _puncConverted boo
            _wasAdded = true; ///resets _wasAddedBool;
            return true;
        }
    }
}

///if Word has a punctuation in it that must be kept, check each non punctuation character
///to see if it must be converted to lower case
string Indexer::HasPunc(string text) {
    char c; ///used to store each character

    ///iterates through each character in the Word, and check to see if it is an alpha,
    ///and if so, if it is lower case. If alpha and not lower case, converts it to lower case
    for (long unsigned int i = 0; i < text.size(); i++) {
        ///checks to see if char is apha
        if (isalpha(text[i])) {
            ///checks to see if alpha is lower case.
            ///if not, convert it to lower case
            if (!(islower(text[i]))) {
                c = text[i]; ///stores the upper case char
                text[i] = tolower(c); ///converts the char to lower case
            }
        }
    }
    return text; ///returns newly lower case Word
}

///prints the BSTs
void Indexer::OutputResults() {
    ofstream out ("indexedResults.txt"); //declares ofstream textfile to print output to
    _indexedBST->printTree(cout); //prints output to txt file

}


