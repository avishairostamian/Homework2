//
//  main.cpp
//  Hw2.3
//
//  Created by Avishai Rostamian on 4/27/21.
//



#include <iostream>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct Node{            //Construct our node for linked list
    int data;
    struct Node* next;
};

struct Node* topnode;       //declare topnode

void nodepush(int n){
    
    Node* node = new Node();    //create new node to be top
    
    node->data = n;         //set value of node
    
    node->next = topnode;      //set new link of new top node
    
    topnode = node;     //set new node to be the top node
}

void nodepop(){
    
    Node* node = new Node();      //create new node
    
    node = topnode;     //set new nodes value of current topnodes
    
    topnode = topnode->next;        //set current topnodes to prevoius nodes link
    
    node->next = NULL;      //set nodes pointer equal to null
}


int top = -1;
int arr[100];


void push(int n){     //Push function (add to top of stack)
    if (top >= 100) cout << "\nOverflow error\n";    //If stack is full, value is not pushed
    
    top++;
    arr[top] = n;   //Else value is stored to the previous top of stack + 1 (new stack top)
}

void pop(){     //Pop function (remove from top of stack)
    
    if (top <= -1) cout << "\nUnderflow error\n"; //If stack is empty, value is not popped
    
    top--;  //Removes top value by decreasing its size by 1
}

void list(){
    
    if(top == -1) cout << "\nEmpty stack";      //If top of stack is less than 0 (empty) prints empty stack
    
    else{
        cout << "\nAll elements in stack: ";
    
    for (int i = 0; i <= top; i++){         //If stack is not empty array is iterated and prints elements
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
}


int main() {

    cout<<"\nTesting array based for loop with 2,000,000 operations\n";
    
    auto start = high_resolution_clock::now();  //Start timer
    
    //Perform millions of operations
    for (int i = 0; i < 500000; i++){       //4 operations 500,000 times = 2,000,000 operations

        push(26);

        pop();

        push(26);

        pop();

    }
    
    auto stop = high_resolution_clock::now();   //Stop timer
    
    auto duration = duration_cast<microseconds>(stop - start); //Get the difference from start to end
    
    cout << "\nThat took only " << duration.count() << " microseconds\n";
    
    
    cout<<"\nTesting linked list based for loop with 2,000,000 operations\n";
    
    auto nodestart = high_resolution_clock::now();  //Start timer
    
    //Perform millions of operations
    for (int i = 0; i < 500000; i++){       //4 operations 500,000 times = 2,000,000 operations

        nodepush(26);

        nodepop();

       nodepush(26);

        nodepop();

    }
    
    auto nodestop = high_resolution_clock::now();   //Stop timer
    
    auto nodeduration = duration_cast<microseconds>(nodestop - nodestart); //Get the difference from start to end
    
    cout << "\nThat took only " << nodeduration.count() << " microseconds\n\n";
    
    cout << "\After performing the same operations the same amount of times to both stacks, it is clear that the ";
    
    
    //===------------ Which ever method is faster by comparison is outputted to the user alongside the time difference -----------===
    
    
    if(nodeduration.count() > duration.count()) cout << "linked list based stack is quicker by " << (nodeduration.count() - duration.count()) << " microsends\n";
    
    else cout << "array based stack is quicker by " << (duration.count() - nodeduration.count()) << " microseconds" << endl;
    
    
    return 0;
}
