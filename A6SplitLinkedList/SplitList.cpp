//============================================================================
// Name        : ReverseList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.h"
using namespace std;
int main() {
    Node *one = createNode();
    Node *two = createNode();
    Node *three = createNode();
    Node *four = createNode();
    Node *five = createNode();
    one-> data = 1;
    two-> data = 2;
    three -> data = 3;
    four -> data = 4;
    one-> next = two;
    two-> next =three;
    three-> next = four;
    four-> next = five;
    five->data = 5;
    five->next = NULL;

    List *l = createList();
    l->head = one;
    l->tail = five;
    l->numElements=5;
    List *nl = createList();
    nl = split(l);
	cout << l->head->data << l->head->next->data << l->tail->data << l->tail->next << endl;
	cout <<l->numElements<<endl;
	cout << nl->head->data << nl->head->next->data << nl->head->next->next->data<<nl->tail->data << nl->tail->next << endl;
	cout << nl->numElements<<endl;
	return 0;
}
