#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
struct List{
    Node* head;
    int count;
};

void reverseNodes(Node** rNode){
    if (rNode == NULL){
        return;
    }
    Node* first  = *rNode;
    Node* rest = first->next;
    if (rest == NULL){
        return;
    }
    reverseNodes(&rest);
    first->next->next = first;
    first->next = NULL;
    *rNode = rest;
    return;
}
void reverse(List *rList){
    if(rList != NULL){
        reverseNodes(&(rList->head));
    }
    return;
}
List *createList() {
  List *l;
  l = new List;
  l->head = NULL;
  l->count = 0;

  return l;
}
bool insertHead(List *l, int e) {

  Node* n = new Node;
  if (NULL == n) {
    return false;
  }

  n->data = e;
  n->next = l->head;
  l->head = n;
  l->count += 1;

  return true;
}
bool insertTail(List *l, int e) {
  if (NULL == l->head) {
    return insertHead(l, e);
  }

  Node* n = new Node;
  if (NULL == n) {
    return false;
  }

  n->data = e;
  n->next = NULL;
  l->count += 1;

  Node* p = l->head;
  if (NULL == p) return false;

  while (NULL != p->next) {
    p = p->next;
  }
  p->next = n;

  return true;
}


int main(){
    List *list = createList();
    insertTail(list, 1);
    insertTail(list, 2);
    insertTail(list, 3);
    insertTail(list, 4);
    insertTail(list, 5);
    reverse(list);  
    cout << list->head->data << list->head->next->data << list->head->next->next->data<<list->head->next->next->next->data<<list->head->next->next->next->next->data<<list->head->next->next->next->next->next;
    return 0;
}