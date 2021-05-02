//
//  main.cpp
//  hw2q6
//
//  Created by Avishai Rostamian on 4/21/21.
//

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

stack<char> Stack;

void reverse(char word[]){        //function to reverse each word taking in a char array
    int length = strlen(word);     //calculate size of the word (char array)
    

    for(int i = 0; i < length; i++){
        
        Stack.push(word[i]);          //loop coverting each char to a stack
        
    }
    cout << " ";
    for(int i = 0; i < length; i++){
        
        cout << Stack.top();        //loop to read each element in stack by reading top then removing element continously 
        Stack.pop();
    }
    
}


int main() {


    //string word;
    int x;

    char arr[x];


    //cout << "Enter string: ";

    std::string word;
    //std::getline(std::cin, word);           //input string from console, this notation ensures entire string even with spaces is read in
    int counter = 0;

    cout << endl;

    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
      while ( getline (myfile,word) )
      {
       
            //cout << endl;

        for (int i = 0; i < word.length(); i++){

            
            if(word.at(i) == ' ' || word.at(i) == '.'){         //checks if there is a space or period 

                
                reverse(arr);     //if space or period then char array (word) is thrown into reverse function to reverse the word

                int length = strlen(arr);         //gets length of the array
                memset(arr, 0, length);             //clears array based on length for the next word


                //arr[0] = '\0';
                //char arr[100] = {0};              //trial and error (took many hours to figure out)
                //memset(arr, 0, sizeof arr);


                counter = 0;
                //i++;
            }
                //cout << "\nfor loop\n";   //used when debugging

            arr[counter] = word[i];
            
            

            counter++;


            }
        //cout << "\nwhile loop\n";
        //if(feof) break;

        cout << endl;   //space in between each sentence
        }
    }

    cout << ".";

    myfile.close();
    return 0;

}



//===---------- Showing old code and thought process alongside how I worked off it and learned from its mistakes -------=====

// take in a sentence
    //break sentence up by word
    //reverse word
    //throw word into function
    //function adds word into stack
    //function then returns the word



//#include <iostream>
//#include <stack>
//#include <string>
//#include <cstring>
//#include <algorithm>
//#include <string.h>
//
//using namespace std;
//
//string toString(char word[]){
//    string str(word);
//
//    return str;
//}
//
//
//void toStack(string str){
//
//    cout << str << endl;
//}
//
//int main() {
//
//    stack<string> Stack;
//    string word;
//    int x;
//
//    char arr[x];
//
//
//    cout << "Enter string: ";
//
//    cin >> word;
//
//    int counter = 0;
//
//    while (true){
//
//
//        for (int i = 0; i < word.length(); i++){
//
//
//            if(word.at(i) == '_' || word.at(i) == '.'){                      //if there is a space the current char array in turned into a string then reversed and passsed into function FOR NOW IT CHECKS FOR (_) SO PLEASE INPUT "When_Chuck_Norris..."
//
//                cout <<"\n in if statement\n";
//
//               //string str(arr);
//
//               string now = toString(arr);
//
//                cout << "\n Testing string: " << now << endl;
//               //reverse(now.begin(), now.end());
//                toStack(now);
//                //memset(arr, 0, sizeof arr);
//
//                memset(arr, 0, ((sizeof now)));             //clear array holding our word
//                //arr[0] = '\0';
//                //char arr[100] = {0};
//                //memset(arr, 0, sizeof arr);
//                counter = 0;
//                i++;
//            }
//                cout << "\nfor loop\n";
//
//            arr[counter] = word.at(i);
//
//            counter++;
//
//
//            }
//        cout << "\nwhile loop\n";
//        break;
//        }
//
//    cout << "\nend\n";
//
//    return 0;
//
//}
