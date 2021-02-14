// CMSC 341 - Summer 2020 - Project 1
//File: Llama.h
//Author: Blake Wishard

#ifndef _LLAMA_H_
#define _LLAMA_H_

#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std;


class LlamaUnderflow : public std::out_of_range {

public:

    LlamaUnderflow(const string& what) : std::out_of_range(what) { }

} ;


template <class T, int LN_SIZE>
class Llama {

public:

    Llama() ;
    Llama(const Llama<T,LN_SIZE>& other) ;   // copy constructor
    ~Llama() ;


    int size() ;
    void dump() ;
    void push(const T& data) ;
    T pop() ;


    void dup() ;    //  (top) A B C D -> A A B C D
    void swap() ;   //  (top) A B C D -> B A C D
    void rot() ;    //  (top) A B C D -> C A B D


    T peek(int offset) const ;


    // overloaded assignment operator
   // const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs) ;


    LlamaNode<T,LN_SIZE> *dumpStack();

    void clearData(); //de-allocates memory in stack
    bool empty() const;  // Returns true if stack is empty


private:

    LlamaNode<T, LN_SIZE> *_head; //head pointer for LlamaNode
    LlamaNode<T, LN_SIZE> *_extraNode;

    int _stackSize; //# of items in stack
    int _nodeSize; //# of item in node
    bool _hasExtraNode;
    int _index;

};

#include "Llama.cpp"

#endif