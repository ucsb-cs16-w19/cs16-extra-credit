#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:   Yulei Tan
 |   To Compile:  make main
 |
 |        Class:  CMPSC 16  - PROBLEM SOLVING I
 |    Concepts:   Recursion, Linked list
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  Reverse a linked list without extra space
 |
 |        Input:  poiner to head of linkedlist.
 |
 |       Output:  pointer to new head of linkedlist.
 |
 |    Algorithm:  Write a function using recursion. Each time, made 
 |                parameter->next point to recursion of its parent
 |      
 |
 |   Known Bugs:  None. Program works well.
 |
 *===========================================================================*/

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *head;
  Node *tail;
};


LinkedList * arrayToLinkedList(int *a, int size) { // copied from lab7
  LinkedList * list = new LinkedList;
  list->head=NULL; 
  list->tail=NULL;
  for (int i=0; i<size; i++) {
    // add array[i] to the list

    if ( list->head==NULL) {
      list->head = new Node;
      list->head->data = a[i]; // (*head).data = a[i];
      list->head->next = NULL;
      list->tail = list->head;
    } else {
      list->tail->next = new Node;
      list->tail = list->tail->next;
      list->tail->next = NULL;
      list->tail->data = a[i];
    }
  }

  return list; // return ptr to new list
}


Node* reverseLinkedList(Node *node){
    if (node ->next == NULL) return node;
    Node* next = reverseLinkedList(node->next);
    node->next->next = node;
    node->next = NULL;
    return next;
}

void printLinkedList(Node* head){
    for (Node* iter = head; iter != NULL; iter = iter->next)
        cout << iter->data << "->";
    cout << "NULL\n";
}

int main () {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	LinkedList *list = arrayToLinkedList(arr,10);
	cout << "LinkedList before: ";
    printLinkedList(list->head);
    Node* new_head = reverseLinkedList(list->head);
    cout << "LinkedList after: ";
    printLinkedList(new_head);
    return 0;
}
