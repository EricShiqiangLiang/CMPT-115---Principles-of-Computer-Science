// CMPT 115
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 9

// File: TreeNode.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the implementation for the TreeNode ADT


#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

// CONSTRUCTOR
// pre: d is a reference to a TreeElement
// post: allocates memory for the TreeNode
// return: reference to the TreeNode record
TreeNode *createTreeNode(TreeElement d){
    TreeNode* treenode = new TreeNode;
    treenode->data = d;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}

//ACCESSORS

// getData(n)
// pre: n is a reference to a TreeNode
// return: the data element in the TreeNode
TreeElement getData(TreeNode *n){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in getData(TreeNode): given NULL TreeNode.  "
	 << "Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // non-error behaviour starts here
  return n->data;
}

// getLeft(n)
//retrieve the left child TreeNode
// pre: n is a reference to a TreeNode
// return: reference to the left TreeNode
TreeNode *getLeft(TreeNode *n){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in getLeft(TreeNode): given NULL TreeNode."
	 << "  Returning NULL, but anything could happen."
	 << endl;
    return NULL;
  }

  // non-error behaviour starts here
  return n->left;
}

// getRight(n)
//retrieve the right child TreeNode
// pre: n is a reference to a TreeNode
// return: reference to the right TreeNode
TreeNode *getRight(TreeNode *n){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in getRight(TreeNode): given NULL TreeNode."
	 << "  Returning NULL, but anything could happen."
	 << endl;
    return NULL;
  }

  // non-error behaviour starts here
  return n->right;
}

// isLeaf(n)
// pre: n is a reference to a TreeNode
// return: true if n has no children
bool isLeaf(TreeNode *n){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in isLeaf(TreeNode): given NULL TreeNode."
	 << "  Returning true, but anything could happen."
	 << endl;
    return true;
  }

  // non-error behaviour starts here
  return ((n->left == NULL) && (n->right == NULL));
}

// height(n)
// pre: n is a reference to a TreeNode
// return: the height of the tree
int height(TreeNode *n){
  if (n == NULL){
    return 0;
  }
  if (n->left == NULL && n->right == NULL){
    return 1;
  }
  else{
    int leftheight = 0, rightheight = 0;
    if(n->left != NULL){
      leftheight = 1 + leftheight + height(n->left);
    }
    if(n->right != NULL){
      rightheight = 1 + rightheight + height(n->right);
    }
    return max(leftheight, rightheight);
  }
}

//MUTATORS


// setData(n,d)
// pre: n is a reference to a TreeNode
// pre: d is a TreeElement
// post: overwites any data in n
void setData(TreeNode *n, TreeElement d){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in setData(TreeNode): given NULL TreeNode."
	 << "Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // non-error behaviour starts here
  n->data = d;
}

// setLeft(n,rlr)
// pre: n is a reference to a TreeNode
// pre: l is a reference to a TreeNode
// post: left subtree is overwritten
void setLeft(TreeNode *n, TreeNode *l){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in setLeft(TreeNode): given NULL TreeNode."
	 << "Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // non-error behaviour starts here
  n->left = l;
}

// setRight(n,r)
// pre: n is a reference to a TreeNode
// pre: r is a reference to a TreeNode
// post: right subtree is overwritten
void setRight(TreeNode *n, TreeNode *r){
  // check error condition first
  if (n == NULL) {
    cerr << "Error in setRight(TreeNode): given NULL TreeNode."
	 << "Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // non-error behaviour starts here
  n->right = r;
}


// destroyTreeNode(n)
// pre: n is a reference to a TreeNode
// post: memory for n is deallocated
void destroyTreeNode(TreeNode *n) {
  // check error condition first
  if (n == NULL) {
    cerr << "Error in destroyTreeNode(): given NULL TreeNode."
	 << endl;
    return;
  }

  // non-error behaviour starts here
  delete n;
}

// eof

