//***********************************************************
// Author: D.S. Malik
//
// Program: Postfix Calculator
// This program evaluates postfix expressions.
//***********************************************************
  
#include <iostream>
#include <iomanip>
#include <fstream>
#include "mystack.h"
 
using namespace std;

void evaluateExpression(ifstream& inpF, ofstream& outF,
                        stackType<double>& stack,
                        char& ch, bool& isExpOk);               //initalize function to evaluate postfix expression
void evaluateOpr(ofstream& out, stackType<double>& stack,
                 char& ch, bool& isExpOk);                      //initalize function to evaluate operator
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk);                                 //initalize function to print result of postfix

int main()
{
    bool expressionOk;          //initalize boolean
    char ch;                       //initalize char
    stackType<double> stack(100);  //creates stack of type double size 100
    ifstream infile;            //input filestream
    ofstream outfile;           //output filestream
 
    infile.open("RpnData.txt");         //opens file "RpnData.txt"

    if (!infile)        //if file cannot open or non accessable...
    {
        cout << "Cannot open the input file. "          //This text gets displayed
             << "Program terminates!" << endl;
        return 1;       //program ends
    }
     
    outfile.open("RpnOutput.txt");  //opens file to output text

    outfile << fixed << showpoint;      //used for floating point values in output text
    outfile << setprecision(2);         //sets floating point values
        
    infile >> ch;           //reads file characters
    while (infile)  //while file is open or accessable
    {
        stack.initializeStack();        //initalizes stack to contain characters of files
        expressionOk = true;            //sets expression boolean to true
        outfile << ch;          //outputs characters to file

        evaluateExpression(infile, outfile, stack, ch,
                           expressionOk);               //calls function to evaluate postfix expression
        printResult(outfile, stack, expressionOk);      //prints results of postfix expression via stack to file if expression is acceptable
        infile >> ch; //begin processing the next expression
    } //end while

    infile.close();     //closes input file
    outfile.close();        //closes output file

    return 0;   //ends program

} //end main


void evaluateExpression(ifstream& inpF, ofstream& outF, stackType<double>& stack,char& ch, bool& isExpOk)       //initialize function to evaluate postfix expression
{
    double num;

    while (ch != '=')   //while current character is not '='
    {
        switch (ch) //used to select which case to choose
        {
        case '#':       //in the case of '#'
            inpF >> num;        //inputs numbers from file
            outF << num << " ";     //outputs number to file
            if (!stack.isFullStack())   //if stack is not full then current number is pushed to stack
                stack.push(num);
            else                    //if stack is full...
            {
                cout << "Stack overflow. "                  //this text is displayed
                     << "Program terminates!" << endl;
                exit(0);  //terminate the program           //program ends
            }

            break;      //breaks from while loop
        default:
            evaluateOpr(outF, stack, ch, isExpOk);      //evalutes current postfix expression
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch;     //input expression from file
            outF << ch;     //output expression to file

            if (ch != '#')      //if character is not '#'
                outF << " ";       //a space is outputted to the file
        }
        else
            discardExp(inpF, outF, ch);     //if expression has error then the expression is discarded
    } //end while (!= '=')
} //end evaluateExpression


void evaluateOpr(ofstream& out, stackType<double>& stack,
              char& ch, bool& isExpOk)                      //initalize function to evaluate operand
{
    double op1, op2;        //initalize holders for operands

    if (stack.isEmptyStack())       //if the stack is empty...
    {
        out << " (Not enough operands)";        //This text is displayed
        isExpOk = false;                //postfix expression is marked with error as boolean is now false
    }
    else        //if stack is not empty
    {
        op2 = stack.top();      //set operand2 equal to value of stack top element
        stack.pop();            //pop stack top element

        if (stack.isEmptyStack()) //if the stack is empty...
        {
            out << " (Not enough operands)";       //This text is displayed
            isExpOk = false;              //postfix expression is marked with error as boolean is now false
        }
        else
        {
            op1 = stack.top();      //set operand2 equal to value of stack top element
            stack.pop();             //pop stack top element

            switch (ch) //checks for case of which operand is present via character value
            {
            case '+':                       //if operand is '+'...
                stack.push(op1 + op2);      //pushes value of op1 plus op2
                break;
            case '-':                       //if operand is '-'...
                stack.push(op1 - op2);      //pushes value of op1 minnus op2
                break;
            case '*':                       //if operand is '*'...
                stack.push(op1 * op2);      //pushes value of op1 times op2
                break;
            case '/':                       //if operand is '/'...
                if (op2 != 0)
                    stack.push(op1 / op2);  //pushes value of op1 divided by op2 so long as the denominator is not 0
                else
                {
                    out << " (Division by 0)";      //if denominator is 0 then this text is displayed
                    isExpOk = false;                //postfix expression is marked with error
                }
                break;      //breaks from switch
            default:
                out << " (Illegal operator)";       //any other opetator is used will result in error with this text displayed
                isExpOk = false;        //postfix expression marked with error
            }//end switch
        } //end else
    } //end else
} //end evaluateOpr


void discardExp(ifstream& in, ofstream& out, char& ch)      //function to discared postfix expression with error
{
    while (ch != '=')       //while character is not '='
    {
        in.get(ch);         //gets character from input file
        out << ch;          //outputs same character
    }
} //end discardExp

void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk)                                  //function to print postfix expression
{
    double result;

    if (isExpOk) //if no error, print the result
    {
        if (!stack.isEmptyStack())  //if stack is not empty...
        {
            result = stack.top();       //store value of top element in stack
            stack.pop();                //remove top element in stack

            if (stack.isEmptyStack())           //if stack is empty...
                outF << result << endl;         //postfix expression result is outputted to file
            else
                outF << " (Error: Too many operands)" << endl;      //else this is diplayed as error
        } //end if
        else
            outF << " (Error in the expression)" << endl;        //else this is diplayed as error
    }
    else
        outF << " (Error in the expression)" << endl;            //else this is diplayed as error

    outF << "_________________________________"             //this text is displayed to signify end of outputted expression or text to file
         << endl << endl;
} //end printResult
