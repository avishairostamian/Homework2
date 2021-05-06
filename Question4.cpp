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


stack<int> changel(stack<int> &x, int position, int value){        //function to iterate through stack and change a value based on position
    stack<int> temp1;     //New stack to hold values of stack to be edited

    x = temp1;      //Set new stack elements equal to current stack

    cout << "\nChanging element in position " << position << " to value " << value << endl;

    int counter = 0;
    
    while( counter != position){            //loop removes top of stack until desired position by incrementing the counter until it is equal in value to the desired position
        
        x.pop();
        counter++;
    }
    
    x.push(value);                  //when loop is finished the requested value is inputted at the requested position

    for(int i = 0; i < position; i++){    //Puts back elements that were popped when changing position x
      x.push(temp1.top());    //Adds element back to stack
      temp1.pop();          //Pops top element to reveal next element to be pushed

    }
    
    return x;
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
    
    listall(myStack);               //call to list all elements in stack function
    
    cout << endl;
    return 0;
}
