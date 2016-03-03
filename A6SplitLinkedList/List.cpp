/*
 * List.cpp
 *
 *  Created on: 2016年3月3日
 *      Author: 世强
 */
#include <iostream>
#include "List.h"
using namespace std;

Node *createNode(){
    Node *s;
    s = new Node;     //allocate dynamic memory for s
    return s;
}
List *createList(){
    List *s;
    s = new List;     //allocate dynamic memory for s
    return s;
}
void reverse(List* rList){
	if (rList->numElements == 0 || rList->numElements == 1){
		return;
	}
	Node* rWalker = rList->head;
	Node* rPre = NULL;
	Node* rNext = NULL;
	while(rWalker != NULL){
		rNext = rWalker->next;
		rWalker->next = rPre;
		rPre = rWalker;
		rWalker = rNext;
		if (rPre->next == NULL){
			rList->tail = rPre;
		}
	}
	rList->head = rPre;

}
List* split(List* l){
	List* rNew = createList();
	Node* rWalker = l->head;
	if (l->numElements > 1){
		for (int i = 1; i < l->numElements / 2; i++){
			rWalker =rWalker->next;
		}
		cout << rWalker->data << endl;
		rNew->head = rWalker->next;
		rNew->tail = l->tail;
		rNew->numElements =l->numElements - l->numElements / 2;
		rWalker->next = NULL;
		l->tail = rWalker;
		l->numElements = l->numElements / 2;
	}
	return rNew;
}
