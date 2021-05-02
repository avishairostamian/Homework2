//Header File: linkedStack.h

#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>
 
#include "stackADT.h"

using namespace std;


template <class Type>           //setup to create template
struct nodeType         //setup to create a node for linked list
{
    Type info;          //data of node
    nodeType<Type> *link;   //pointer for link of node
};

template <class Type>       //within our template
class linkedStackType: public stackADT<Type>    //initalize our linked list stack functions
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);       //initalize '=' operator


    bool isEmptyStack() const;  //initalize boolean to check for empty stack


    bool isFullStack() const;  //initalize boolean to check for full stack


    void initializeStack(); //initalize function to initalize stack


    void push(const Type& newItem); //initalize push function


    Type top() const;   //initalize top template


    void pop(); //initalize pop function


    linkedStackType();  //initalize linked list stack type function


    linkedStackType(const linkedStackType<Type>& otherStack);   //initalize copy stack constructor
  

    ~linkedStackType();     //linked list stack destructor

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack);    //initalize copy stack function

};


    
template <class Type>
linkedStackType<Type>::linkedStackType()    //initalize empty linked list with top stack as empty or null
{
    stackTop = nullptr;     //sets top stack to be empty or null
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const    //function to test whether stack is empty and returns true if empty
{
    return(stackTop == nullptr);    //checks if top of stack is empty or null
}

template <class Type>
bool linkedStackType<Type>:: isFullStack() const    //function to test whether stack is full
{
    return false;       //returns false if not full
}

template <class Type>
void linkedStackType<Type>:: initializeStack()    //function to fill in or initialize stack
{
    nodeType<Type> *temp;       //creates a pointer to a temporary node used for filling in stack elements

    while (stackTop != nullptr)     //while the stacktop is not empty
    {
        temp = stackTop;        //set new value of stack top element
                           
        stackTop = stackTop->link;      //creates link for next element in the stack
                                   
        delete temp;        //deletes value of temp
    }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)    //function to push new element to stack
{
    nodeType<Type> *newNode;        //new node pointer

    newNode = new nodeType<Type>;      //initalize new node pointer

    newNode->info = newElement;     //store new element in the new node
    newNode->link = stackTop;       //create link between new node and others in the stack
    stackTop = newNode;     //set new node as stacks top element
                             
} //end push


template <class Type>
Type linkedStackType<Type>::top() const     //function to get stack top
{
    assert(stackTop != nullptr);        //asserts stack top is not empty
                              
    return stackTop->info;      //returns element of stack top
}//end top

template <class Type>
void linkedStackType<Type>::pop()   //pop function to remove element in stack
{
    nodeType<Type> *temp;       //initalize new node

    if (stackTop != nullptr)        //if the stack is not already empty
    {
        temp = stackTop;    //holder for top nodes element

        stackTop = stackTop->link;      //sets top element as node link removing its values
                                    
        delete temp;        //deletes temp holder
    }
    else
        cout << "Cannot remove from an empty stack." << endl;       //if stack is empty this is displayed
}//end pop

template <class Type>
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)      //function to copy stack
{
    nodeType<Type> *newNode, *current, *last;       //set pointer for new nodes (new, current, previous)

    if (stackTop != nullptr)        //if stack top is empty, new stack is initalized
        initializeStack();

    if (otherStack.stackTop == nullptr)     //if stack is empty new stack is declared empty
        stackTop = nullptr;
    else                                    //if stack top is not empty...
    {
        current = otherStack.stackTop;      //new node is equal to value of top of stacks element to be copied

          
        stackTop = new nodeType<Type>;      //initalize new stack tops node

        stackTop->info = current->info;     //set new stack tops node with value previous stacks top node (stack that is being copied)
        stackTop->link = nullptr;           //sets top elements pointer of new stack to be null (top element in stack)
                               
        last = stackTop;        //sets last node equal to stack tops value
        current = current->link;    //creates link between new nodes

           
        while (current != nullptr)      //while current node is not null (this does the copying of stacks)
        {
            newNode = new nodeType<Type>;   //initalize new node

            newNode->info = current->info;          //new node gets value of stack to be copied node
            newNode->link = nullptr;            //new node link points to null
            last->link = newNode;               //creates link between last node and new node
            last = newNode;                     //sets value of last node
            current = current->link;            //sets link between nodes
        }
    }
}

 
template <class Type>
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)  //sets function to copy the new stack
{
    stackTop = nullptr;         //sets top of top to null or empty
    copyStack(otherStack);      //call to function to copy stack
}

  
template <class Type>
linkedStackType<Type>::~linkedStackType()      //sets function to initalize stack
{
    initializeStack();      //call to function to initalize stack
}
    
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=
                  (const linkedStackType<Type>& otherStack)     //sets function to see if stacks are equal
{
    if (this != &otherStack)        //if stacks are not equal then stack is copied
        copyStack(otherStack);

    return *this;       //returns new stack
}

#endif
