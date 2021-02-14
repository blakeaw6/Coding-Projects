// CMSC 341 - Summer 2020 - Project 1
//File: Llama.cpp
//Author: Blake Wishard

#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_


#include "Llama.h"

//constructor
template<class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama() {

    _head = nullptr;
    _extraNode = nullptr;
    _nodeSize = 0;
    _stackSize = 0;
    _index = 1;
    _hasExtraNode = false;
}

//copy constructor
template<class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama(const Llama<T, LN_SIZE> &other) {

    if (!(other.empty())) {
        clearData();
        LlamaNode<T, LN_SIZE> *temp = other._head;
        _head = new LlamaNode<T, LN_SIZE>;
        while (temp != nullptr) {
            for (int i = 0; i < LN_SIZE; i++) {
                _head->arr[i] = other._head->arr[i];
            }
            temp = temp->m_next;
        }
    }
/*

        _head = new LlamaNode<T, LN_SIZE>;
        LlamaNode<T, LN_SIZE> *temp = _head->m_next;

        //for loop that copies over each node in the linked list
        for (LlamaNode<T, LN_SIZE> *curr = other._head->m_next; curr != nullptr; curr = curr->m_next) {

            temp->m_next = new LlamaNode<T, LN_SIZE>;
            temp = temp->m_next;
        }
    }

*/
}


//destructor
template<class T, int LN_SIZE>
Llama<T, LN_SIZE>::~Llama() {

    clearData();
}

template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::clearData() {

    if (empty()) {
        return;
    }

    LlamaNode<T, LN_SIZE> *temp = _head->m_next;

    while (temp != nullptr) {
        delete _head;
        _head = temp;
        temp = _head->m_next;
    }
    delete _head;
    _head = nullptr;

    if (_hasExtraNode) {
        delete _extraNode;
    }
}

//checks if empty()
template<class T, int LN_SIZE>
bool Llama<T, LN_SIZE>::empty() const {
    return _head == nullptr;
}


//size - returns number of items in stack
template<class T, int LN_SIZE>
int Llama<T, LN_SIZE>::size() {
    //returns the number of objects in the stack (_stackSize member variable)
    return _stackSize;
}

//dump - print info to cerr
//Performs a LlamaStack dump with all of the details,
//calls other functions such as dumpStack() and report()
template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dump() {

    cerr << "\n***** Llama Stack Dump *****";
    cerr << "\nLN_SIZE = " << LN_SIZE;
    cerr << "\n# of items in the stack = " << size() << endl;
    _head->report();

    if (_hasExtraNode == true) {
        cerr << endl << "This stack has an extra node: " << _extraNode << "." << endl;
    } else {
        cerr << endl << "This stack does not have an extra node." << endl << endl;
    }

    cerr << endl << "Stack contents, top to bottom" << endl;
    dumpStack();
    cerr << "---- bottom of stack -----" << endl;
    cerr << endl << "****************************" << endl;
}

//push - adds data to stack
//inserts the data to the top of the stack
template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::push(const T &data) {

    //if _head == nullptr, create a new node
    if (_head == nullptr) {
        LlamaNode<T, LN_SIZE> *temp = new LlamaNode<T, LN_SIZE>;
        temp->arr[LN_SIZE - 1] = data;
        temp->m_next = nullptr;
        _head = temp;
        _stackSize++;
        _nodeSize++;
        _index++;
        return;
    }

    //if _head is not nullptr, but the node is not yet filled
    if (_nodeSize < LN_SIZE && _index <= LN_SIZE) {
        int i = LN_SIZE - _index;
        _head->arr[i] = data;
        _index++;
        _nodeSize++;
        _stackSize++;
        return;
    }

    //if the LN_SIZE limit has been reached, and a new Node must
    //be created. Case if there is not currently an extra node
    if ((_nodeSize == LN_SIZE) && (_hasExtraNode == false)) {
        _index = 1; //used to place object in LN_SIZE-1 position
        _nodeSize = 0; //resets node size
        LlamaNode<T, LN_SIZE> *temp = new LlamaNode<T, LN_SIZE>; //temp pointer to iterate
        temp->arr[LN_SIZE - _index] = data; //stores data in temp pointer
        temp->m_next = _head; //sets temp next to _head
        _head = temp; //sets _head to temp
        _index++;   //increases index count
        _nodeSize++; //increases node size
        _stackSize++; //increases stack size
        return;

    }

    //if the LN_SIZE limit has been reached, and a new Node must
    //be created. Case if there is currently an extra node
    if ((_nodeSize == LN_SIZE) && (_hasExtraNode == true)) {
        _index = 1; //used to place object in LN_SIZE-1 position
        _nodeSize = 0; //resets node size
        _extraNode->arr[LN_SIZE - _index] = data; //places data in last index of the extra node
        _extraNode->m_next = _head; //sets the next pointer of extra node to _head
        _head = _extraNode; //points _head to extra node
        _index++; //increases index count
        _nodeSize++; //increases node size
        _stackSize++; //increases stack size
        _hasExtraNode = false;
        return;
    }
}


//dumps the stack contents in the proper order
template<class T, int LN_SIZE>
LlamaNode<T, LN_SIZE> *Llama<T, LN_SIZE>::dumpStack() {

    if (_head == nullptr) {
        return 0;
    }
    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer used to iterate
    T tEmpty{}; //templated empty array used to find empty positions in node

    int nodeSizeHolder = 4;
    bool hit = false;
    if (_head = nullptr) {
        return 0;
    }

    if (_nodeSize == 1) {
        hit = true;
        for (int i = LN_SIZE - 1; i < LN_SIZE; i++) {
            cerr << "---- " << temp << " ---- " << endl;
            cerr << temp->arr[i] << endl;
        }
        if (temp->m_next != nullptr) {
            temp = temp->m_next;

        } else {
            return 0;
        }
    }

    if (_nodeSize < LN_SIZE && hit == false) {
        cerr << "---- " << temp << " ---- " << endl;
        for (int i = LN_SIZE - _nodeSize; i < LN_SIZE; i++) {
            cerr << temp->arr[i] << endl;
        }
        if (temp->m_next != nullptr) {
            temp = temp->m_next;
            // nodeSizeHolder = 4;
        } else {
            cout << "hit return";
            return 0;
        }
    }


    if (nodeSizeHolder == 4) {
        //iterates through nodes and prints them to the screen
        while (temp != nullptr) {
            cerr << "---- " << temp << " ---- " << endl;
            //iterates through node and displays all array spaces that are not empty
            for (int i = 0; i < LN_SIZE; i++) {
                //if array space is not empty, display it
                cerr << temp->arr[i] << endl; //displays data
            }
            temp = temp->m_next; //moves to next node
        }
    }
}

// - removes from stack
template<class T, int LN_SIZE>
T Llama<T, LN_SIZE>::pop() {

    //_head == nullptr, throw exception
    if (_head == nullptr) {
        throw LlamaUnderflow("\"LlamaStack<T, LN_SIZE>::pop(): attempt to pop from an empty stack");
    }

    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer used to iterate

    //if popping a node makes that node less than half capacity, and there is
    //an extra node: remove the extra node
    if ((_nodeSize - 1 <= LN_SIZE / 2) && (_hasExtraNode)) {
        T tEmpty{0}; //templated empty array
        //iterates through nodes to pop object and remove extra node
        while (temp != nullptr) {
            //iterates through node to find non empty array value to pop
            for (int i = 0; i < LN_SIZE; i++) {
                //if non empty array space
                if (temp->arr[i] != tEmpty) {
                    T tValue = temp->arr[i]; //stores the value being removed to return it
                    _head->arr[i] = tEmpty; //sets array space to empty array
                    _nodeSize--; //decreases node size
                    _stackSize--; //decreases stack size
                    delete _extraNode; //deletes extra node
                    _hasExtraNode = false; //sets extra node boolen to false
                    return tValue;
                }
            }
            temp = temp->m_next; //iterates to next node
        }
    }

    //case 2: pop object in node
    //if in case 2: if last object in node, move to next node,
    //must store/keep empty node somewhere
    //if _nodeSize-1 == 0: you are removing the last object in the node
    if (_nodeSize - 1 == 0) {
        T tValue = temp->arr[0];
        _nodeSize = LN_SIZE;
        _extraNode = temp;
        _hasExtraNode = true;
        _nodeSize--;
        _stackSize--;
        _index--;
        if (_head->m_next != nullptr) {
            _head = _head->m_next;
        } else {
            _head = nullptr;
        }
        return tValue;
    }

        //if _nodeSize-1 != 0: there will still be objects left in the node
        //after you remove this one
    else {
        T tEmpty{};
        for (
                int i = LN_SIZE - _index;
                i < LN_SIZE - _index + 1; i++) {
            T tValue = _head->arr[i];
            _head->arr[i] =
                    tEmpty;
            _nodeSize--;
            _stackSize--;
            _index--;
            return tValue;
        }
    }
}

//duplicate - duplicates top of stack (if empty throw exception)
template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dup() {
    //if stack is empty, throw underflow exception
    if (empty()) {
        throw LlamaUnderflow("\"LlamaStack<T, LN_SIZE>::dup(): attempt to dup from an empty stack");
    }

    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer to iterate
    T tEmpty{};

    //finds value at top of stack and pushes another copy of it to the top, effectively duplicating it.
    while (temp != nullptr) {
        for (int i = 0; i < LN_SIZE; i++) {
            if (temp->arr[i] != tEmpty) {
                T tValue = temp->arr[i]; //stores value to duplicate
                push(tValue); //calls push() function to add value to top of stack
                return;
            }
            temp = temp->m_next;
        }
    }
}


//swap - swap top two items on stack (if <2 throw exception)
template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::swap() {

    //if _stackSize <2 , throw underflow exception
    if (_stackSize < 2) {
        throw LlamaUnderflow("\"LlamaStack<T, LN_SIZE>::swap(): attempt to swap from an empty stack");
    }

    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer to iterate
    T tEmpty{};
    int tValIndex1 = 0; //index value for first object
    int tValIndex2 = 0; //index value for second object

    //counts the number of objects in the _head node
    //if there is only one object in the node, run case 2,
    //which checks for consecutive objects in the stack between two different nodes.
    // Else, run case 1, which will check for consecutive objects
    // in the stack in the same node.
    int objectCount = 0; //objectCount holder
    bool runCase2 = false; //sets the runCase2 bool to false
    //count the number of spaces in the node that are not empty

    cout << "_nodeSize = " << _nodeSize << endl;
    //if only 1 object in _head node, run case 2 to check for consecutive
    //objects in two different nodes


    //case 1: swapping two values in the same node
    //checks if there are two consecutive objects in the same node
    if (_nodeSize == LN_SIZE) {
        cout << "went in" << endl;;
        //check to see if there are two consecutive objects in the same node
        T tValue1 = temp->arr[0]; //stores first object value temp i position
        //   T tValue2 = temp->arr[1]; //stores second object value in i+1 position
        cout << "tV1 0= " << temp->arr[0];
        cout << "tV2 1 =" << temp->arr[1];
        tValIndex1 = 0; //sets index1 to i
        tValIndex2 = 1; //sets index2 to i+1
        _head->arr[tValIndex1] = _head->arr[tValIndex2]; //stores object2 in object 1 position
        _head->arr[tValIndex2] = tValue1; //stores object1 in object2 position
        return;
    }

        //case 2: swapping two values that are in 2 different nodes
        //checks if there are two consecutive objects that are in two consecutive nodes
    else {
        temp = _head;
        cout << "hit2" << endl;
        // T tValue1 = temp->arr[LN_SIZE-2];
        //cout << "tValue1 = " << endl;
        /*
        tValIndex1 = LN_SIZE - 1;
        T tValue2 = temp->m_next->arr[0];
        cout << "tValue2 = " << tValue2 << endl;
        tValIndex1 = 0;
        _head->arr[tValIndex1] = _head->m_next->arr[tValIndex2]; //places object2 in second node//in object1's position in first node
        _head->m_next->arr[tValIndex2] = tValue1; //places object1 in object 2's position in 2nd node
         */
        return;
    }
}

//rotate - rotates top three items (if <3 throw exception)
template<class T, int LN_SIZE>
void Llama<T, LN_SIZE>::rot() {

//if _stackSize <3 , throw underflow exception
    if (_stackSize < 3) {
        throw LlamaUnderflow("\"LlamaStack<T, LN_SIZE>::swap(): attempt to swap from an empty stack");
    }

    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer to iterate
    T tEmpty{};

    //three cases:
    //case 1: all 3 objects in same node
    //case 2: 2 objects in _head node, 1 object in next node
    //case 3: 1 object in _head node, 2 objects in next node

    //counts the number of objects in the _head node
    //if there are at least three objects in that node, run case 1
    //if there 2 objects in that node, run case 2
    //if there is only 1 object in that node, run case 3
    int objectCount = 0; //stores object count
    int tValIndex1 = 0; //stores first index value
    int tValIndex2 = 0; //stores second index value
    int tValIndex3 = 0; //stores third index value
    bool runCase1 = false; //sets bool for runCase1 to false
    bool runCase2 = false; //sets bool for runCase2 to false
    bool runCase3 = false; //sets bool for runCase3 to false

    //counts number of objects in node
    for (int i = 0; i < LN_SIZE; i++) {
        if (temp->arr[i] != tEmpty) {
            objectCount++;
        }
    }

    //if there are at least three objects in _head node, run case 1
    if (objectCount >= 3) {
        runCase1 = true;
    }
    //if there are only two objects in _head node, run case 2
    if (objectCount == 2) {
        runCase2 = true;
    }
    //if there is only one object in _head node, run case 3
    if (objectCount == 1) {
        runCase3 = true;
    }

    //case 1: all 3 objects are in the same node
    if (runCase1) {
        for (int i = 0; i < LN_SIZE; i++) {
            //finds the index positions and values for the three consecutive objects in the node
            if ((temp->arr[i] != tEmpty) && (temp->arr[i + 1] != tEmpty) && (temp->arr[i + 2] != tEmpty)) {
                T tValue1 = temp->arr[i]; //stores object1 value
                T tValue2 = temp->arr[i + 1]; //stores object2 value
                T tValue3 = temp->arr[i + 2]; //stores object3 value
                tValIndex1 = i; //stores object1 index
                tValIndex2 = i + 1; //stores object2 index
                tValIndex3 = i + 2; //stores object3 index
                _head->arr[tValIndex1] = _head->arr[tValIndex3]; //moves object3 to object1 position
                _head->arr[tValIndex2] = tValue1; //moves object1 to object2 position
                _head->arr[tValIndex3] = tValue2; //moves object2 to object3 position
                return;

            }
        }
    }

    //case 2: 2 objects are in the _head node, one object is in the next node
    if (runCase2) {
        for (int i = 0; i < LN_SIZE; i++) {
            //finds the index position and values for the 2 objects in the _head node
            if ((temp->arr[i] != tEmpty) && (temp->arr[i + 1] != tEmpty)) {
                T tValue1 = temp->arr[i]; //stores object1 value
                T tValue2 = temp->arr[i + 1]; //stores object2 value
                tValIndex1 = i; //stores index1 position
                tValIndex2 = i + 1; //stores index2 position

                //checks next node to find value and position
                for (int j = 0; j < LN_SIZE; j++) {
                    //finds the index position and value for the third object
                    if (temp->m_next->arr[j] != tEmpty) {
                        T tValue3 = temp->m_next->arr[j]; //stores object3 value
                        tValIndex3 = j; //stores object3 position
                        _head->arr[tValIndex1] = _head->m_next->arr[tValIndex3]; //moves object3 to object1 position in first node
                        _head->arr[tValIndex2] = tValue1; //moves object1 to object2 position
                        _head->m_next->arr[tValIndex3] = tValue2; //moves object2 to object3 position
                        return;
                    }
                }
            }
        }
    }

    //case 3: 1 object in _head node, 2 objects in next node
    if (runCase3) {
        for (int i = 0; i < LN_SIZE; i++) {
            //find and stores object1 position and value
            if ((temp->arr[i] != tEmpty)) {
                T tValue1 = temp->arr[i]; //stores object1 value
                tValIndex1 = i; //stores object1 position

                //finds object values and positions for the next two consecutive objects in the stack
                for (int j = 0; j < LN_SIZE; j++) {
                    //finds object2 and object3 in 2nd node positions and values
                    if ((temp->m_next->arr[j] != tEmpty) && (temp->m_next->arr[j + 1] != tEmpty)) {
                        T tValue2 = temp->m_next->arr[j]; //stores object2 value
                        T tValue3 = temp->m_next->arr[j + 1]; //stores object3 value
                        tValIndex2 = j; //stores object2 index
                        tValIndex3 = j + 1; //stores object3 index
                        _head->arr[tValIndex1] = _head->m_next->arr[tValIndex3]; //moves object3 to object1 position in the first node
                        _head->m_next->arr[tValIndex2] = tValue1; //moves object1 to object2 position in 2nd node
                        _head->m_next->arr[tValIndex3] = tValue2; //moves object2 to object3 position in 2nd node
                        return;
                    }
                }
            }
        }
    }
}


//peek - returns value of item (if offsett too large throw exception)
template<class T, int LN_SIZE>
T Llama<T, LN_SIZE>::peek(int offset) const {

    //if offset > _stackSize , throw underflow exception
    if (offset > _stackSize) {
        throw LlamaUnderflow("\"LlamaStack<T, LN_SIZE>::peek(): offset too large to peek");
    }

    LlamaNode<T, LN_SIZE> *temp = _head; //temp pointer to iterate
    T tEmpty{};

    T orderedArr[_stackSize]; //creates an array to hold all items of the stack in order
    int index = 0; //index holder

    //iterates through all the nodes
    while (temp != nullptr) {
        for (int i = 0; i < LN_SIZE; i++) {
            //find non empty spaces in node and stores them in the ordered array
            if (temp->arr[i] != tEmpty) {
                T tValue = temp->arr[i]; //stores object value
                orderedArr[index] = tValue; //stores object in ordered array
                index++; //increases index
            }
        }
        temp = temp->m_next; //moves to next array
    }
    return orderedArr[offset]; //returns the object value in the stack with the given index in the parameters
}


/*
//overloaded assignment operator
template<class T, int LN_SIZE>
const Llama<T, LN_SIZE>::Llama<T, LN_SIZE> &operator=(const Llama<T, LN_SIZE> &rhs) {

    _head = nullptr;
    if (!(other.empty())) {
        clearData();
        _head = new LlamaNode<T, LN_SIZE>;
        LlamaNode<T, LN_SIZE> *temp = _head->m_next;

        //for loop that copies over each node in the linked list
        for (LlamaNode<T, LN_SIZE> *curr = other._head->m_next; curr != nullptr; curr = curr->m_next) {
            temp->m_next = new LlamaNode<T, LN_SIZE>;
            temp = temp->m_next;
        }
    }


}

*/

#endif