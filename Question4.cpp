//
//  main.cpp
//  Hw2.4
//
//  Created by Avishai Rostamian on 4/27/21.
//



#include <iostream>
#include <stack>
using namespace std;


void listall(stack<int> y){                 //function to list all the elements in a stack

    stack<int> x;     //new stack to hold value of current stack so elements do not get lost
    x = y;        //set new stack = to current stack

    if(x.empty()) cout << "\nStack is empty";

    cout << "\nAll elements in stack: ";
    
    while(!x.empty()){                      //loop outputs the top value of the stack then pops the top value giving the next value, looping until the stack is empty
        cout << x.top() << " ";
        x.pop();
    }
    
    cout << endl;
}


int changel(stack<int> &x, int position, int value){        //function to iterate through stack and change a value based on position
    
    cout << "\nChanging element in position " << position << " to value " << value << endl;

    int counter = 0;
    
    while( counter != position){            //loop removes top of stack until desired position by incrementing the counter until it is equal in value to the desired position
        
        x.pop();
        counter++;
    }
    
    x.push(value);                  //when loop is finished the requested value is inputted at the requested position
    
    return 1;
}

int main() {
    
    stack<int> myStack;     //initialize stack and give values
    
    myStack.push(5);
    
    myStack.push(3);
    
    myStack.push(2);
    
//    cout << "# of Stack: " << myStack.size() << endl;
//
//
//    cout << "Popping " << myStack.top() << endl;
//
//    myStack.pop();
//
//    cout << "# of Stack: " << myStack.size() << endl;
    
    
//


    listall(myStack);           //call to list all elements in stack function
    

    
    changel(myStack, 1, 10);        //call to function changing first position to value 10
    
    listall(myStack);               //call to list alll elements in stack function
    
    cout << endl;
    return 0;
}
