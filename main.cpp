#include <iostream>
#include <string>
#include <fstream>
#include "struct.h"
#include "Funcs.h"
using namespace std;

/*=============================================================================
 |     Author:    Kevin Wang
 |   To Compile:  Type "make tests" to compile test, type "make Iliad" to compile
 |       	  main function. Type "./FuncsTest" and "./main" to run the code
 |
 |        Class:  CS16
 |    Concepts:   Pointer, linked list, I/O stream, string, readfile
 +-----------------------------------------------------------------------------
 |
 |  Description:  This allow user to search words in the whole Iliad. It will output
 |		  the first three occurance of the word in Iliad and its line Number   
 |
 |        Input:  There is no input argument for the main function. There is, however
 |		  a standard input stream in the function provide a interaction with
 | 		  the users. Users can type the word they want to search in Iliad, for
 |		  example "countless", "Ulysses". If the users want to exit, he need to
 |		  type "exit"
 |
 |       Output:  It will print the first three ocurances of the word and its line number
 |		  If the function cannot find enough occurances, it will just print "NA" 
 |		  as word, and 0 as line number.
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Known Bugs:  There is no known bugs in my code, but when compiling, there's many warnings
 |
 *===========================================================================*/

int main(){
        string answer = "";
        while(answer!="exit"){   //collect users input with cin. if the input is exit, the loop breaks
                cout<< "Please enter a word (Type 'exit' to exit):"<< endl;
                string input="";
                cin >> input;
                answer=input;
                if (answer=="exit") break;

                Word *Temp = new Word;  //Declares temporary pointers
                Word *Temp2 = new Word;
                Word *Temp3 = new Word;
                Temp->value="NA";
                Temp->lineNum=0;
                Temp2->value="NA";
                Temp2->lineNum=0;
                Temp3->value="NA";
                Temp3->lineNum=0;

                Temp->next = Temp2;
                Temp2->next = Temp3;
                Temp3->next = NULL;

                History* history = new History; //Create a linked list of three Occurances
                history->head = Temp;
                history->tail = Temp3;

                wordMatch(history,input);       //Search the word in Iliad
                Word* temp = history->head;
                for(temp;temp!=NULL;temp=temp->next) { //print the result
                        cout<<temp->value<<" " << temp->lineNum<< endl;
                }

        }
        return 0;
}


