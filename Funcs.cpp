#include <iostream>
#include <string>
#include <fstream>
#include "struct.h"
using namespace std;


void wordMatch(History* Saved, string input){//Search the input in the Iliad and makes a linked list
  string line;
  int lineNum=0;
  Word* temp = Saved->head;
  ifstream myfile( "Illiad.txt" ); //read Iliad
  if (myfile) 
    {
    while (getline( myfile, line )) 
      {
      lineNum++;			//increase the line number with each getline()
      if (line.find(input) != string::npos)//check if the input is in a line
        {
        temp->value=input;		//If matches, record the linenumber
	temp->lineNum=lineNum;
	temp = temp->next;
	if (temp == NULL)		//if find the match, the loop will break
		break;
        }
      }
    myfile.close();
    }
}


string mainForTesting(string input){   //since my function is an interactive function, and I have no experience of testing such programs, I create this function for testing. This function is basically main function, but instead of using cin to grab input from user, the input is included in the function.
        for(int i=0;i<3;i++){			//most of the code is identical to main.cpp
                if (input=="exit") break;
                Word *Temp = new Word;
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

                History* history = new History;
                history->head = Temp;
                history->tail = Temp3;

                wordMatch(history,input);
                Word* temp = history->head;


                string testResult="";           //return the actual result
                for(temp;temp!=NULL;temp=temp->next) {
                        testResult+=temp->value;
                        testResult+=" ";
                        testResult+=to_string(temp->lineNum);
                        testResult+="\n";
                }
                return testResult;
        }
}


