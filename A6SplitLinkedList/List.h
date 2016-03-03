/*
 * List.h
 *
 *  Created on: 2016��3��3��
 *      Author: ��ǿ
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
