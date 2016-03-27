//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 9
//Lab: 9

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "BSTree.h"

using namespace std;


// helper function for inner use
// Pre: given an original element
// Post: a new tree node is created with that element
// Return: the new tree node
//
TreeNode *CreateNode(const Element dataIn)
{
	TreeNode *rNode = new TreeNode;
	rNode->data  = dataIn;
	rNode->left = NULL;
	rNode->right = NULL;
	return rNode;
}

// Create a binary search tree
// Post: a new empty tree is created
// Return: the new tree
//
Tree *CreateBST()
{
    Tree* BST = new Tree;
    BST->root = NULL;
	return BST;
}

// helper function for inner use
// Pre: given a tree node
// Post: the tree node and all nodes in its left and right subtrees are destroyed, and all memory returned to the heap
//
void DestroyTreeNode(TreeNode *rNode){
	if(rNode != NULL){
		DestroyTreeNode(rNode->left);
		DestroyTreeNode(rNode->right);
		delete(rNode);
	}
}


void DestroyBST(Tree* rTree){
	
	if (rTree != NULL){
		DestroyTreeNode(rTree->root);
		delete rTree;
		rTree = NULL;
	}
}


// helper function of InsertBST for inner use
// Pre: given a tree node and an element
// Post: the tree contains the element in ascending binary search position
// Return: the updated tree
//
TreeNode *InsertNodeBST(TreeNode * rNode, const Element dataIn){
	if (rNode == NULL){
		TreeNode* rNew = new TreeNode;
		rNew->data = dataIn;
		rNew->left = NULL;
		rNew->right = NULL;
		return rNew;
	}
	else if (dataIn == rNode->data){
		return rNode;
	}
	else if (dataIn < rNode->data){
		rNode->left = InsertNodeBST(rNode->left, dataIn);
		return rNode;		
	}
	else if (dataIn > rNode->data){
		rNode->right = InsertNodeBST(rNode->right, dataIn);
		return rNode;
	}
	return EXIT_SUCCESS;
}


void InsertBST(Tree *rTree, const Element dataIn){

	rTree->root = InsertNodeBST (rTree->root, dataIn);
}



// helper function of SearchBST for inner use
// Pre: rNode :: refToTreeNode
// 	  target :: Integer
// Post: tree is unchanged
// Return: true if target is found in the tree; false otherwise.
bool SearchNode(TreeNode *rNode, const Element target, Element *rDataOut){
	if (rNode == NULL){
		return false;
	}
	else if (target < rNode->data){
		return SearchNode(rNode->left, target, rDataOut);
	}
	else if (target > rNode->data){
		return SearchNode(rNode->right, target, rDataOut);
	}
	else{
		*rDataOut = rNode->data;
		return true;
	}
}

bool SearchBST(const Tree *rTree, const Element target, Element *rDataOut){
	return SearchNode(rTree->root, target, rDataOut);
}

bool DeleteBST(Tree * rTree, const Element nData, Element *rDataOut){
	
	TreeNode *rNode = rTree -> root;
	TreeNode *rParent = NULL;
	TreeNode *rNew, *rBiggest;
	
	// search for nData in the tree
	while(rNode != NULL && rNode -> data != nData){
		rParent = rNode;
		if(nData < rNode->data) {
			rNode = rNode -> left;
		}
		else {
			rNode = rNode -> right;
		}
	}
	
	// can't find nData in the tree
	if(rNode == NULL) {
		return false;
	}
	else {// data was found in the tree 
		if (rNode -> left == NULL) { // case 1 or case 2
			rNew = rNode -> right;
		}
		else if (rNode -> right == NULL) // case 3
		{
			rNew = rNode -> left;
		}
		else { // case 4
			rBiggest = rNode -> left;
			while (rBiggest -> right != NULL){
				rBiggest = rBiggest -> right;
			}
			rBiggest -> right = rNode -> right;
			rNew = rNode -> left;
		}		
		
		// tidy up
		if (rNode == rTree -> root){
			rTree -> root = rNew;
		}
		else if ( rParent -> left == rNode){
			rParent -> left = rNew;
		}
		else {
			rParent -> right = rNew;
		}
		
		*rDataOut = rNode -> data;
		delete rNode;
		return true;
	}
	
}


// helper function for inner use
void PrintElement(const Element e) {
   cout << e  << "   ";
}

// helper function for inner use
void InorderTNodes(TreeNode * rNode) {
  if (NULL != rNode) {
	  InorderTNodes(rNode->left);
	  PrintElement(rNode->data);
	  InorderTNodes(rNode->right);
	}
}

void PrintInOrder(Tree * rTree) {
	InorderTNodes(rTree->root);
	cout << endl;
}

// helper function for inner use
void PreorderTNodes(TreeNode * rNode) {
  if (NULL != rNode) {
 	  PrintElement(rNode->data);
	  PreorderTNodes(rNode->left);
	  PreorderTNodes(rNode->right);
	}
}

void PrintPreOrder(Tree * rTree) {
	PreorderTNodes(rTree->root);
	cout << endl;
}

// helper function for inner use
void PostorderTNodes(TreeNode * rNode) {
  if (NULL != rNode) {
	  PostorderTNodes(rNode->left);
	  PostorderTNodes(rNode->right);
	  PrintElement(rNode->data);
	}
}

void PrintPostOrder(Tree * rTree) {
	PostorderTNodes(rTree->root);
	cout << endl;
}
