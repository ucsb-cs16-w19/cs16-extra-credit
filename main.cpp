#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Weixuan Zhang
 |   To Compile:  Flashs card to remember important concept we learned in CS16
 |
 |        Class:  NAME AND TITLE OF THE CLASS FOR WHICH THIS PROGRAM WAS
 |                      WRITTEN
 |    Concepts:   (dynamic) Linkedlist, getline, loops...
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  DESCRIBE THE PROBLEM THAT THIS PROGRAM WAS WRITTEN TO
 |      SOLVE.
 |
 |        Input:  cards.txt
 |
 |       Output:  DESCRIBE THE OUTPUT THAT THE PROGRAM PRODUCES.
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
//#include <unistd.h>
using namespace std; 
struct ListNode
{
	string item;
	string itembk;
	int count;
	//ListNode *link; 
	ListNode* next;


};

typedef ListNode* ListNodePtr;

void insertend(ListNodePtr& t,string itemnow,string itembk, int countnow) ;


int main(){
char temp;
cout<<"********************************************************"<<endl;
cout<<"*                                                      *"<<endl;
cout<<"*                                                      *"<<endl;
cout<<"*       Welcome to the flash cards application         *"<<endl;
cout<<"*                                                      *"<<endl;
cout<<"*                                                      *"<<endl;
cout<<"*                                                      *"<<endl;
cout<<"********************************************************"<<endl;
cout<<"\n"<<endl;
cout<<"\n"<<endl;
string answer;

ListNode* n;
ListNode* t;
ListNode* h;
int i=2;
ifstream readline;
char filename[30];
char words[100];
char wordsb[100];
cout<<"which file do you want as your card set?"<<endl;


cout<<"\n"<<endl;
cin.getline(filename,30);
readline.open(filename);
if (!readline.is_open()){
	exit(EXIT_FAILURE);
}
readline>>words;
readline>>wordsb;

n= new ListNode;
n-> item =words;
n-> itembk=wordsb;
n-> count= 0;
t=n;
h=n;

while(readline.good()){
	if(i%2==1){
		readline>>wordsb;
		n= new ListNode;
		n-> item= words;
		n-> itembk=wordsb;
		n-> count= 0;
		t-> next= n;
		t=t->next;
		//cout<<"f"<<endl;
		//cout<<t->itembk<<endl;
	}
	else if(i%2==0){
		readline>>words;
		//cout<<"z"<<endl;
	//	cout>>t->item>>endl;
	}
	i++;
}




cout<<"Let's start remember them!"<<endl;

cout<<"\n"<<endl;
cout<<"\n"<<endl;


while(1)
{
if(h->next == NULL){
	cout<<"You finished the cards!"<<endl;
	break;
}

cout<<"Here is the front of the card (Press Enter to continue read the back)"<<endl;
cout<<"________________________________________________________"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                   "<<h->item<<"                      "<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|______________________________________________________|"<<endl;


cout<<"\n"<<endl;
cin.ignore();
cout<<"Press enter to check the back of the card"<<"";
cout<<"\n"<<endl;
cin.ignore();
cout<<"\n"<<endl;
cout<<"________________________________________________________"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                   "<<h->itembk<<"                      "<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|                                                      |"<<endl;
cout<<"|______________________________________________________|"<<endl;


cout<<"\n"<<endl;
//sleep(1);
cout<<"Do You Understand this Concept? Please answer Y or N for Yes and No"<<endl;
cin>>answer;
if (h->next == NULL){
	break;
}
else if (answer=="Y") {
	h->count++;

	}
else if (answer=="N"){
	h->count--;

}
else{
	cout<<"I don't know what you mean"<<endl;
	break;
}
if (h->count<3){
//	n = new ListNode;

//	n->item=h->item; 
//	n->count=h->count;

//	t->next=n;
//	t=t->next;
insertend(t,h->item,h->itembk,h->count);


}


h=h->next;
cout<<"\n"<<endl;
}



return 0; 

}



void insertend(ListNodePtr& t,string itemnow,string itemnowbk, int countnow) {
	if(t==0){
		exit(EXIT_FAILURE);
	}


	ListNode* nb;
	nb = new ListNode;
//
	nb->item=itemnow; 
	nb->itembk=itemnowbk;
	nb->count=countnow;

	t->next=nb;
	t=t->next;
	nb->next=NULL;

	
}

