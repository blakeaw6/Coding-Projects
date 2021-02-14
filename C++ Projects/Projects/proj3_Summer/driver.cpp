///CMSC 341 - Summer 2020 - Project 3
///File: driver.cpp
///Author: Blake Wishard

#include "HashedSplays.h"  // Includes constants
#include "Exceptions.h"

using namespace std;

int main(int argc, char *argv[]) {

    //check for right number of arguments
    if (argc != 2) {
        cout << endl;
        cout << "Usage:  ./Proj3.out data.file\n";
        cout << "data.file - The file that contains the text to be indexed.\n";
    }
    else {
        string inFilterFile = argv[1];
        cout << "inFilterFile = " << inFilterFile << endl;
    }
    try {
        // Instatiate the main object
        HashedSplays wordFrequecy(ALPHABET_SIZE);
        // Build the trees
        wordFrequecy.FileReader(argv[1]);


        // Test methods to show hashed splay trees work
        wordFrequecy.PrintHashCountResults();

        wordFrequecy.PrintTree(19); // Prints the "T" tree

        wordFrequecy.PrintTree("F");

        wordFrequecy.PrintTree("K"); // should be empty running input1

        wordFrequecy.FindAll("The"); // should find all the's (ignoring case)
        cout << endl;

    }

        // Error catching
    catch (Exceptions &cException) {
        cout << "EXCEPTION: " << cException.GetMessage() << endl;
        return 1;
    }
    
    //Uncomment for number of seconds running.
    cout << clock() / (float)(CLOCKS_PER_SEC) << endl;
    return 0;
}  