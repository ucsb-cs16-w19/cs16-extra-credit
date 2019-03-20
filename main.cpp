#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Tom Nguyen
 |   To Compile:  g++ -o Calculator main.cpp
 |
 |        Class:  CS 16
 |                      
 |    Concepts:   While loops, switch statements, function prototypes,
 |                if statements, break 
 +-----------------------------------------------------------------------------
 |
 |  Description:  Basic calculator that can perform the 4 basic operations
 |     
 |
 |        Input:  Takes two floating point values
 |
 |       Output:  Either adds, subtracts, multiplies, or divides them
 |
 |    Algorithm:  While loop keeps the program going so that the user can keep
 |                using it until he/she tells the program to exit
 |
 |   Known Bugs:  There is a limit to how large or small the numbers can be 
 |      
 |
 *===========================================================================*/
double num1, num2;
int op, status;
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);

int main () {
        status = 1;
        while (status == 2)
        {
                cout << "Basic Calculator Project. Press enter to continue." << endl;
                cin.get();
                cout << "1 - Add\n2 - Subtract\n3 - Multiply\n4 - Divide\n0 - Exit" << endl;
                cout << "Choose a number to select your desired operation: " << endl;
                cin >> op;
                if (op == 0){
                        break;
                }
                cout << "Type in the first number you want to use: " << endl;
                cin >> num1;
                cout << "Type in the second number you want to use: " << endl;
                cin >> num2;
         
                switch(op)
                {
                        case 1:
                                cout << "The answer is " << add(num1, num2) << endl;
                                break;
                        case 2:
                                cout << "The answer is " << sub(num1, num2) << endl;
                                break;
                        case 3:
                                cout << "The answer is " << mul(num1, num2) << endl;
                                break;
                        case 4:
                                cout << "The answer is " << div(num1, num2) << endl;
                                break;
                }
                cout << "Would you like to continue?" << endl;
                cout << "1 - Yes\n2 - No" << endl;
                cin >> status;
        }
        cout << "Goodbye" << endl;

    return 0;
}

double add(double a, double b){
        return a + b;
}

double sub(double a, double b){
        return a - b;
}

double mul(double a, double b){
        return a * b;
}

double div(double a, double b){
        return a / b;
}
                                                                 67,1-8        Bot

                                                                                   92,0-1        Bot
