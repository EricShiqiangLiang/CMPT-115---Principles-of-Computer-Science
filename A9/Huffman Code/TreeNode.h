// CMPT 115
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 9
//
// File: TreeNode.h
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the interface for the TreeNode ADT

#include "TreeElement.h"

#ifndef _TREENODE_H_
#define _TREENODE_H_

struct TreeNode {
  TreeElement data; //stores a pointer to the data in this tree node
  TreeNode *left; //reference to the left child tree
  TreeNode *right; //reference to the right child tree
};


// CONSTRUCTOR
// pre: d is a reference to a TreeElement
// post: allocates memory for the TreeNode
//       copies reference!
// return:
TreeNode *createTreeNode(TreeElement d);

//ACCESSORS

// getData(n)
// pre: n is a reference to a TreeNode
// return: the data element in the TreeNOde
TreeElement getData(TreeNode *n);

// getLeft(n)
//retrieve the left child TreeNode
// pre: n is a reference to a TreeNode
// return: reference to the left TreeNode
TreeNode *getLeft(TreeNode *n);

// getRight(n)
//retrieve the right child TreeNode
// pre: n is a reference to a TreeNode
// return: reference to the right TreeNode
TreeNode *getRight(TreeNode *n);

// isLeaf(n)
// pre: n is a reference to a TreeNode
// return: true if n has no children
bool isLeaf(TreeNode *n);

// height(n)
// pre: n is a reference to a TreeNode
// return: the height of the tree
int height(TreeNode *n);

//MUTATORS


// setData(n,d)
// pre: n is a reference to a TreeNode
// pre: d is a TreeElement
// post: overwites any data in n
void setData(TreeNode *n, TreeElement d);

// setLft(n,rlr)
// pre: n is a reference to a TreeNode
// pre: l is a reference to a TreeNode
// post: left subtree is overwritten
void setLeft(TreeNode *n, TreeNode *l);

// setRight(n,r)
// pre: n is a reference to a TreeNode
// pre: r is a reference to a TreeNode
// post: right subtree is overwritten
void setRight(TreeNode *n, TreeNode *r);


// destroyTreeNode(n)
// pre: n is a reference to a TreeNode
// post: memory for n is deallocated
void destroyTreeNode(TreeNode *n) ;

#endif
