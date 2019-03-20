#include <iostream>
#include <string>
#include <cstring>
#include <sstream> 
#include <cassert>

using namespace std;

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *head;
  Node *tail;
};

//Find out whether the linkedlist includes 
//nodes' datas with the same value or not
bool searchll(Node *head, int value){
    if (head->data == value){
        return 1;
    }
    else if (head->data!=value && head->next==NULL){
        return 0;
    }
    else{
        return searchll(head->next, value);
    }
}

//Delete all nodes in the linkedlist by using recursion
void deleteLinkedList(Node *head){
    if (head->next == NULL){
        delete head;
        return;
    }
    else{
        Node *temp = head->next;
        delete head;
        head = temp;
        return deleteLinkedList(head);
    }
}

//Delete nodes that theirs datas are the same as the given value
void deleteLinkedList(Node *head, int value){
    if (head->data == value){
        Node *temp = head->next;
        delete head;
        head = temp;
        if (head->next == NULL){
            delete head;
        }
    }
    else{
        cout << head->data<<endl;
        return deleteLinkedList(head->next, value);
    }
}

int main()
{
    Node *one = new Node;
    one->data = 1; // equivalent to (*one).data = 1;

    Node *two = new Node;
    two->data = 2; 

    Node *three = new Node;
    three->data = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    LinkedList *l = new LinkedList;
    l->head = one;
    l->tail = three;

    searchll(l->head,5);
    cout << searchll(l->head,5) << endl;

    return 0;
}