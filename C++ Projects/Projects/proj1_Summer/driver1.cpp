// CMSC 341 - Summer 2020 - Project 1
//File: driver.cpp
//Author: Blake Wishard



#include <iostream>
#include <string>
using namespace std ;


#include "Llama.h"

int main() {

    Llama<string,4>S ;


    // Push a bunch of strings

    S.push("cdef") ;
    S.push("yzab") ;
    S.push("vwx") ;
    S.push("stu") ;

    S.push("pqr") ;
    S.push("mno") ;

    S.push("jkl") ;
    S.push("ghi") ;


    S.push("def") ;
   S.push("abc") ;

    S.dump();


    cout << "testing swap function... " << endl;
   // S.swap();
   // S.dump();
    /*

    cout << endl << "testing rotate function..." << endl;
    S.rot();
    S.dump();

    S.push("test1");
    S.push("test2");
    S.push("test3");

    S.dump();

    Llama<float,6> SFloat ;
    float test;

    SFloat.push(3.659) ;
    SFloat.push(4.490) ;
    SFloat.push(8.201) ;
    SFloat.push(9.062) ;
    SFloat.push(12.056) ;
    SFloat.push(14.995 );


    // Pop some strings off
    cout << endl;

    string s1;
    cerr << "\n***** Pop Test *****\n\n";
    s1 =S.pop() ;
    cerr  << "popped in main: " << s1 << endl << endl;
    s1 =S.pop() ;
    cerr << "popped in main: " << s1 << endl << endl;
    s1 =S.pop() ;
    cerr << "popped in main: " << s1 << endl << endl;
    s1 =S.pop() ;
    cerr << endl << "popped in main: " << s1 << endl ;

    //pop some floats

    test = SFloat.pop() ;
    test= SFloat.pop() ;
    test= SFloat.pop() ;


    S.dump() ;




    cerr << "***** Dump using peek *****" ;
    int size =S.size() ;
    cerr << "\nsize = " << size << endl ;

    for (int i=0 ; i <S.size() ; i++) {
        cerr << i << ": " <<S.peek(i) << endl ;
    }
    cout << endl;


    cout << endl << "dupping... " << endl;
    S.dup();
    S.dumpStack();



    cerr << "\n***** Dump using peek 2 *****" ;
    size =S.size() ;
    cerr << "\nsize = " << size << endl ;

    for (int i=0 ; i <S.size() ; i++) {
        cerr << i << ": " <<S.peek(i) << endl ;
    }
    cout << endl;



    // Pop some strings off
    cout << endl;

    //  string s1 ;

    cerr << "\n***** Pop Test *****\n" ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;
    S.dump();


    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;

    S.dump() ;  // should have "extra" node



    cerr << "\n***** Push Test *****\n" ;
    S.push("x789") ;
    S.push("x456") ;
    S.push("x123") ;

    S.dump() ;  // should use extra node



    cerr << "\n***** Pop Test *****\n" ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;

    S.dump() ;  // should have extra node again


    cerr << "\n***** LAST Pop Test *****\n" ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 =S.pop() ;
    cerr << "popped " << s1 << endl ;

    S.dump() ;  // extra node should be gone

*/
    return 0 ;
}