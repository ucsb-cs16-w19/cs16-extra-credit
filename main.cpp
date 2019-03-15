#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

/*=============================================================================
 |     Author:   Stella Zhao 
 |   To Compile: g++ main.cpp -o 24points 
 |
 |        Class:  this is written for fun
 |    Concepts:  if/else;for loop;command line arguements... 
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  a program that take four intger command line arguements, and print out the expression if a 24 can be produced by adding some operations between them
 |
 |        Input: four integer command line arguments that are between 1-13 
 |
 |       Output: print out the expression that evaluates to 24 
 |
 |    Algorithm:  bit operations
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/


string numToOp(int num);
double doop(string op,double x0,double x1);
bool cansolve(double vals[],string op1,string op2,string op3);
bool check(double val);

int main(int argc, char* argv[]) {
    double val[4] = {0};
    string op1 = "";
    string op2 = "";
    string op3 = "";
    double ordered[4] = {0};
    const int table[] = {
        0x0123,0x0132,0x0213,0x0231,0x0312,0x0321,
        0x1023,0x1032,0x1203,0x1230,0x1320,0x1302,
        0x2013,0x2031,0x2103,0x2130,0x2310,0x2301,
        0x3012,0x3021,0x3102,0x3120,0x3210,0x3201};
    if (argc == 5){
        for (int n = 1; n < argc; n++){
            cout << atoi(argv[n]) << endl;
            val[n-1] = atoi(argv[n]);
        }
    } else {
        cout << "input 4 numbers!\n";
        exit(1);
    }
    for (int order = 0;order < 24;order++){
        for(int i = 0;i<4;i++){
            ordered[i] = val[(table[order]>>(i*4))&(0xF)];
        }
        for(int opchoice = 0;opchoice < 64;opchoice++){
            op1 = numToOp(opchoice&3);
            op2 = numToOp((opchoice >> 2)&3);
            op3 = numToOp((opchoice >> 4)&3);
            if (cansolve(ordered,op1,op2,op3) ){
                exit(0);
            }
        }
    }
    return 0;
}
string numToOp(int num){
    if (num == 0){
        return "+";
    } else if(num == 1){
        return "-";
    }else if(num == 2){
        return "*";
    } else{
        return "/";
    }
}

double doop(string op,double x0,double x1){
    if (op == "+"){
        return x0+x1;
    } else if(op == "-"){
        return x0-x1;
    } else if(op == "*"){
        return x0*x1;
    } else { 
        return x0/x1;
    }
}

bool cansolve(double vals[],string op1,string op2,string op3){
    if (check(doop(op3,doop(op2,doop(op1,vals[0],vals[1]),vals[2]),vals[3]))){
        cout <<"("<<"("<<vals[0]<<op1<<vals[1]<<")"<<op2<<vals[2]<<")"<<op3<<vals[3]<<endl;
        return true;
    } else if (check(doop(op3,doop(op1,vals[0],doop(op2,vals[1],vals[2])),vals[3]))){
        cout << "("<<vals[0]<<op1<<"("<<vals[1]<<op2<<vals[2]<<"))"<<op3<<vals[3]<<endl;
        return true;
    }else if(check(doop(op2,doop(op1,vals[0],vals[1]),doop(op3,vals[2],vals[3])))){
        cout << "("<<vals[0]<<op1<<vals[1]<<")"<<op2<<"("<<vals[2]<<op3<<vals[3]<<")"<<endl;
        return true;
    }else if (check(doop(op1,vals[1],doop(op3,doop(op2,vals[1],vals[2]),vals[3])))){
        cout << vals[0]<<op1<<"(("<<vals[1]<<op2<<vals[2]<<")"<<op3<<vals[3]<<endl;
        return true;
    }else if (check(doop(op1,vals[0],doop(op2,vals[1],doop(op3,vals[2],vals[3]))))){
        cout << vals[0]<<op1<<"("<<vals[1]<<op2<<"("<<vals[2]<<op3<<vals[3]<<"))\n";
        return true;
    }
    return false; 
}

bool check(double val){
    if (fabs(val-24)<1e-7){
        return true;
    }
    return false;
}




