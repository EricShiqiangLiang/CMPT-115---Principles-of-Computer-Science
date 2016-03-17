/*
 * List.h
 *
 *  Created on: 2016年3月3日
 *      Author: 世强
 */

struct Node{
	int data;
	Node* next;
};
struct List{
	Node* head;
	Node* tail;
	int numElements;
};


Node* createNode();
List* createList();
void reverse(List*);
List* split(List*);
