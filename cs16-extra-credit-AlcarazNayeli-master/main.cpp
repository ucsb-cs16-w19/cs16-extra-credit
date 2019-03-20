#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Nayeli Giselle Alcaraz, perm =9745191
 |   To Compile:  EXPLAIN HOW TO COMPILE THIS PROGRAM 
 |
 |        Class:  Written for Computer Science CS16
 |      
 |    Concepts:   this program will use pointers, structs, and linked lists.
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program creates a new node with inputted number, then put it into a descending ordered
 |      list
 |
 |        Input:  requires the input of an integer
 |
 |       Output:  the output will be the the order of numbers
 |
 |    Algorithm:  create one struct linked list. then create a prog which will 
 |      find the place for the number
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/
struct Node {
	int data;
	Node * next;
};
struct LinkedList {
	Node *head; //the first node in the list
	Node *tail; //points to the last node in the list.
};
void insertToList(LinkedList * a, int value){
//create a new node.
	Node *b = new Node;
	b->data=value;
//we set a temp variable equal to the head of a list if list not empty.
	if(a->head==NULL){
		a->head=b;
		a->tail=b;
		a->head->next=NULL;

	}
	else{
	Node *iter=a->head;
	Node *prev=a->head;
		while(iter!=NULL){
			if(b->data < a->head->data){
				b->next=a->head;
				a->head=b;
				}

			else{
				iter=iter->next;
				if(b->data > iter->data){
					iter=iter->next;
					prev=prev->next;
				}
			else{
				b->next=iter;
				prev->next=b;
				break;
			}
			}
		}
	}
}
int main(){
	Node*p = new Node;
	p->data=6;
	Node *q= new Node;
	q->data=8;
	p->next=q;
	q->next=NULL;
	LinkedList* listB= new LinkedList;
	listB->head =p;
	listB->tail=q;
	insertToList(listB,7);
	Node *iter =listB->head;
	while(iter!=NULL){
		cout <<iter->data<<endl;
	        iter=iter->next;
	}
return 0;
}
