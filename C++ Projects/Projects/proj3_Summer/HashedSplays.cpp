///CMSC 341 - Summer 2020 - Project 3
///File: HasedSplay.cpp
///Author: Blake Wishard

#include "HashedSplays.h"

#include <iostream>
#include <cctype>
#include <string>
#include <array>

using namespace std;

///default constructor
HashedSplays::HashedSplays() {

    _nodeCount = 0;
    m_trees = 0;
}

///overloaded constructor
HashedSplays::HashedSplays(int size) {

    _nodeCount = 0;
    m_trees = size;

}

///FileReader()
///reads in the file input from the .txt file, cleans it for insertion into Splay Tree
void HashedSplays::FileReader(string inFileName) {

    ifstream file1;        //creates file io stream
    file1.open(inFileName); //opens command line inputted file name
    int lineCount = 0; //sets the line count

    //checks to make sure that the file is open
    if (file1.is_open()) {

        string textHolder = " "; //stores string data for the word

        ///while there are still lines in the .txt file to be read...
        ///reads file from line until new line character and stores the data in the text string
        while (getline(file1, textHolder, '\n')) {
            lineCount++; ///increases the line count
            char delim1 = '-'; ///used to see if it is intra-word hyphen or regular punctuation
            char delim2 = '\''; ///used to see if it is intra-word apostrophe or regular punctuation

            ///iterates through each character in a given line
            for (int i = 0, len = textHolder.size(); i < len; i++) {
                ///checks to see if the current character is a punctuation symbol, but not a hyphen or apostrophe
                ///if the above criteria is met, erases that character and decreases size
                if ((ispunct(textHolder[i])) && (textHolder[i] != delim1) && (textHolder[i] != delim2)) {
                    //checks to see if puncutation should be made an empty space, or removed entirely.
                    //if there is an alpha, digit, or another punctuation after it, erases and resets size
                    if ((isalpha(textHolder[i + 1])) || (isdigit(textHolder[i + 1])) || (ispunct(textHolder[i+1]))) {
                        textHolder.erase(i--, 1); //erases punctuation character
                        len = textHolder.size();  //resets size

                    } //else, make empty space
                    else {

                        textHolder[i] = ' '; //make character empty space
                        len = textHolder.size(); //resets size
                    }

                } //if char is digit, erase it
                else if ((isdigit(textHolder[i]))) {
                    textHolder.erase(i--, 1);
                    len = textHolder.size();

                } //char is hyphen, check to see if it should be deleted or not.
                    //keeps intra word hyphens, and intra word double hyphens
                else if (textHolder[i] == delim1) {
                    //checks to see if hyphen is intra word hyphen or intra word double hyphen. If not, erases it
                    if ((isalpha(textHolder[i - 1]) || (textHolder[i - 1] == delim1)) && ((isalpha(textHolder[i + 1]) || textHolder[i+1] == delim1))) {
                        //checks to see if there is a second hyphen directly after it
                        if (textHolder[i+1] == delim1) {
                            //checks to see if there is an alpha after the second hyphen. If so, keeps hyphen. If not, erases.
                            if (isalpha(textHolder[i+2])) {
                            }
                                //erases hypehn and resets size
                            else {
                                textHolder.erase(i--, 1);
                                len = textHolder.size();
                            }
                        }
                    }
                        //else, erases hypen and resets size
                    else {
                        textHolder.erase(i--, 1);
                        len = textHolder.size();
                    }


                } //if char is apostrophe, checks to see if it's an intra word apostrophe
                else if (textHolder[i] == delim2) {
                    if (i == 0) {
                        cout << "hit 0" << endl;
                         //textHolder[i] = ' ; //make character empty space
                         textHolder.erase(i--, 1); ///deletes the character
                          len = textHolder.size(); ///resets the length
                    }
                    //if alpha's on either side of apostrophe, keep it. Else, delete it
                    else if ((isalpha(textHolder[i - 1])) && (isalpha(textHolder[i + 1]))) {
                    }
                        //else, deletes apostrophe
                    else {

                        textHolder.erase(i--, 1); ///deletes the character
                        len = textHolder.size(); ///resets the length
                    }
                } else {
                   
                }
            }

            istringstream ss(textHolder); //string stream to check each word in line
            string word = "";  //creates word holder
            string wordCopy = ""; //creates word copy holder
            char c; //creates word copy holder

            ///while there is still words in the given line to be read...
            ///uses extraction operator to read in data from given line into the string word
            while (ss >> word) {

                wordCopy = word; //sets the wordCopy for checking and converting to lower case for finding the first letter's numerical index

                //is char is not lowercase, convert it to lowercase to find equivalent numerical index
                if (!(islower(wordCopy[0]))) {

                    c = wordCopy[0]; //holds char
                    wordCopy[0] = tolower(c); //converts char to lowercase

                }
                    ///is lowercase, no conversion needed
                else {

                }

                //for loop to find correct index in _table for the node to be inserted into
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    //find numerical index for insertion into Splay Tree
                    if (wordCopy[0] == _alphaArray[i]) {
                        //checks if that index is empty. If so, creates a new node, and inserts node into index
                        if (_table[i].isEmpty()) {
                            Node *temp = new Node(word, 0); //creates new node passing it word and count of 0
                            temp->IncrementFrequency(); //increments node frequency
                            _table[i].insert(*temp); //inserts Node into Splay Tree and correct index
                            _table[i].updateCount(); //updates node count for that index of the _table array
                            break; //stops for-loop



                        }//if index is not empty, check to see if it already contains that node
                        else {
                            Node *temp = new Node(word, 0); //creates a new node
                            //check to see if the Splay tree at that index already contains a node with the same word
                            if (_table[i].contains(*temp)) {
                                temp = _table[i].printRoot(*temp); //sets temp equal to the original node to update frequency
                                temp->IncrementFrequency(); //updates frequency for original node
                                break; //ends for-loop


                            } //if the Splay tree at that index doesn't already contain that node, creates a new node and inserts it
                            else {

                                Node *temp = new Node(word, 0); //creates new node
                                temp->IncrementFrequency(); //updates frequency of node
                                _table[i].insert(*temp); //inserts node into Splay tree at correct index
                                _table[i].updateCount(); //updates the node count for that index of the _table array
                                break; //ends for-loop

                            }
                        }
                    }
                }
            }
        }
    }
}

///PrintTree(int)
///prints the tree at the passed index value
void HashedSplays::PrintTree(int index) {

    _table[index].printTree(); //prints tree at passed index value
    cout << "This tree has had " << _table[index].getSplayCount() << " splays." << endl; //outputs splay count

}

///PrintTree(string)
///prints tree at numberical equivalent of passed string (char) value
void HashedSplays::PrintTree(string letter) {

    int index = 0; //holds index
    index = GetIndex(letter); //used to get numerical equivalent of index

    //checks to see if the array is empty at that index
    if (_table[index].isEmpty()) {
        cout << "Empty Tree" << endl;
        cout << "This tree has had 0 splays." << endl;
    }
        //if not empty, prints tree
    else {
        
        _table[index].printTree(); //prints tree at that index
        cout << "This tree has had " << _table[index].getSplayCount() << " splays." << endl; //outputs splay count
    }
}

///PrintHashCounts()
///prints the root value at each index of the array, along with the number
//of nodes that the Splay Tree at that index contains
void HashedSplays::PrintHashCountResults() {
    cout << endl;

    //iterates through each index to print the root
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        cout << "This tree starts ";
        //checks if index of array is not empty
        if (!(_table[i].isEmpty())) {
            cout << "with Node";
            _table[i].printHashCountResults(); //prtins the hash count results at that index
            cout << "and has ";
            int counter = 0; //stores node count
            counter = _table[i].getCount(); //gets node count
            cout << counter << " nodes" << endl;
        }
            //else, empty index
        else {
            cout << "has no nodes" << endl;
        }
    }
}



///FindAll()
///used to find words within a certain tree index, displays them infix order.
///similar to predictive texting
void HashedSplays::FindAll(string inPart) {
    
    int index = 0; //stores index
    index = GetIndex(inPart); //gets numerical equivalent of index

    cout << "Printing the results of all nodes that start with " << "'" << inPart << "'" << endl;

    Node *temp = new Node(inPart, 0); //creates new node with passed word
    _table[index].findAll(*temp); //prints the list of all nodes that start with the passed word

}
///GetIndex()
//converts the passed letter to it's equivalent numerical value
    int HashedSplays::GetIndex(string inLetter) {

        char c; //stores char
        //if first letter of string is not lower case, converts to lower case to find numerical value
        if (!(islower(inLetter[0]))) {
            c = inLetter[0]; //stores char
            inLetter[0] = tolower(c); //converts char to lower case
        }

        //finds numerical value for index
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            //returns correct index value
            if (inLetter[0] == _alphaArray[i]) {
                return i;

            }
        }
        return 0;
    }