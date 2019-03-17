#include <iostream>
#include <string>
#include "checklistfuncs.h"

using namespace std;

/*=============================================================================
 |     Author: Isaac Lam
 |   To Compile:make main  
 |
 |        Class:CS16  
 |               
 |    Concepts:if else statements, linked list, pointers, loops  
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program creates a structure that is a checklist
 it allows the user to create a to do list, add things to the list,
 check things off, and delete them completely.
 |
 |        Input: the main function just shows how these structures and 
 functions can be used in order to create an effective todo list
 |
 |       Output:displays how the functions works. 
 |
 |    Algorithm:  created a linked list struct with a Node called thingtodo.
 these thingstodo can be added or deleted to the linked list struct through functions this is done through many if else conditions, and iterating through the linked lists.
 |
 |   Known Bugs: none that are known 
 |
 *===========================================================================*/

int main () {
	
	//create empty check list
	checklist* checklist = createchecklist();
	cout<<"created empty check list"<<endl;
	printchecklist(checklist);
	cout<<endl;

	//add 3 items to checklist
	addtochecklist(checklist,"do laundry","3/20/19");
	addtochecklist(checklist,"finish CS Extra Credit", "3/20/19");
	addtochecklist(checklist,"CS16 Final", "3/21/19");
	cout<<"added 3 items to checklist"<<endl;
	printchecklist(checklist);

	//checked off event "do laundry"
	checkoff(checklist,"do laundry");
	cout<<"checked of event 'do laundry'"<<endl;
	printchecklist(checklist);

	//deleted checked of items
	deletecheckedoffitems(checklist);
	cout<<"deleted checked off items"<<endl;
	printchecklist(checklist);

	//deleted item "CS16 Final" without checking off first 
	deleteitem(checklist,"CS16 Final");
	cout<<"deleted CS16 Final without checking off first"<<endl;
	printchecklist(checklist);

	//deleted list
	cout<<"deleted list"<<endl;
	deletechecklist(checklist);
	printchecklist(checklist);
	

	return 0;
	
}
