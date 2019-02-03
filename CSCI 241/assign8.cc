//***************************************************************
//* CSCI 241 - Autumn, 2008 - Assignment 8
//*
//* This is the driver program to test the Binary Tree class
//***************************************************************

#include <iostream>
#include <iomanip>

#include "bintnode.h"
#include "bintree.h"

const int SIZE = 75;
const int N = 1000;

using std::cout;
using std::endl;
using std::setw;

int main()
{
BinTree<int> intSearchTree;
BinTree<int> intTree;
int A[SIZE];

//Test 1: Default constructor, Size, Leaves, and Height for BOTH trees

cout << "Test 1: Default constructor, Size, Leaves, and Height" << endl
     << endl << "Binary Tree:" << endl
     << "    no of nodes    = " << setw(4) << intTree.Size() << endl
     << "    no of Leaves   = " << setw(4) << intTree.Leaves() << endl
     << "    Height of tree = " << setw(4) << intTree.Height() << endl;

if ( intTree.IsEmpty() )
  cout << "    the tree is empty";
else
  cout << "    the tree is NOT empty";
cout << endl;

cout << endl << endl << "Binary Search Tree:" << endl
     << "    no of nodes    = " << setw(4) << intSearchTree.Size() << endl
     << "    no of Leaves   = " << setw(4) << intSearchTree.Leaves() << endl
     << "    Height of tree = " << setw(4) << intSearchTree.Height() << endl;

if ( intSearchTree.IsEmpty() )
  cout << "    the tree is empty";
else
  cout << "    the tree is NOT empty";
cout << endl;

//Get 75 "random" numbers
srand(1);
for(int i = 0; i < SIZE; i++)
  A[i] = rand() % N;

//Test 2: Insert1 - building a binary tree

for(int i = 0; i < SIZE; i++)
  intTree.Insert1(A[i]);

cout << endl << endl << "Test 2: After Insert1" << endl << endl
     << "Binary Tree:" << endl
     << "    no of nodes    = " << setw(4) << intTree.Size() << endl
     << "    no of Leaves   = " << setw(4) << intTree.Leaves() << endl
     << "    Height of tree = " << setw(4) << intTree.Height() << endl;

if ( intTree.IsEmpty() )
  cout << "    the tree is empty";
else
  cout << "    the tree is NOT empty";
cout << endl;

//Test 3: Insert2 - building a binary Search tree

cout << endl << endl << "Test 3: After Insert2" << endl << endl;

for(int i = 0; i < SIZE; i++)
  intSearchTree.Insert2(A[i]);

cout << endl << "Binary Search Tree:" << endl
     << "    no of nodes    = " << setw(4) << intSearchTree.Size() << endl
     << "    no of Leaves   = " << setw(4) << intSearchTree.Leaves() << endl
     << "    Height of tree = " << setw(4) << intSearchTree.Height() << endl;

if ( intSearchTree.IsEmpty() )
  cout << "    the tree is empty";
else
  cout << "    the tree is NOT empty";
cout << endl;

//Test 4: pre, post, and inorder traversals

cout << endl << endl << "Test 4: Pre, In, and Postorder Traversals" << endl << endl
     << "Binary Tree - preorder:" << endl;
intTree.PreOrder();

cout << endl << endl << "Binary Tree - inorder:" << endl;
intTree.InOrder();

cout << endl << endl << "Binary Tree - postorder:" << endl;
intTree.PostOrder();

cout << endl << endl << endl << "Binary Search Tree - preorder:" << endl;
intSearchTree.PreOrder();

cout << endl << endl << "Binary Search Tree - inorder:" << endl;
intSearchTree.InOrder();

cout << endl << endl << "Binary Search Tree - postorder:" << endl;
intSearchTree.PostOrder();

cout << endl;

//Test 5: Searching the Binary Search Tree

cout << endl << endl << "Test 5: Searching the Binary Search Tree"
     << endl << endl;

for ( int i = 0; i < 12; i++ )
  {
  int SearchNum = ( rand() * A[i] ) % N;

  cout << "  The value " << setw(3) << SearchNum;

  if ( intSearchTree.Search( SearchNum ) )
    cout << " is found" << endl;
  else
    cout << " is not found" << endl;
  }

//Test 6: Clearing a tree

intTree.Clear();

cout << endl << endl << "Test 6: Clearing a Binary Tree" << endl << endl
     << "Binary Tree:" << endl
     << "    no of nodes    = " << setw(4) << intTree.Size() << endl
     << "    no of Leaves   = " << setw(4) << intTree.Leaves() << endl
     << "    Height of tree = " << setw(4) << intTree.Height() << endl;

//Test 7: Copy Constructor

BinTree<int> intTree2 ( intSearchTree );

cout << endl << endl << "Test 7: Copy Constructor" << endl << endl
     << "Binary Tree 2:" << endl
     << "    no of nodes    = " << setw(4) << intTree2.Size() << endl
     << "    no of Leaves   = " << setw(4) << intTree2.Leaves() << endl
     << "    Height of tree = " << setw(4) << intTree2.Height() << endl;

//Test 8: pre, post, and inorder traversals with new tree

cout << endl << endl << "Test 8: Pre, In, and Postorder Traversals"
     << " with new tree" << endl << endl
     << "Binary Tree 2 - preorder:" << endl;
intTree2.PreOrder();

cout << endl << endl << "Binary Tree 2 - inorder:" << endl;
intTree2.InOrder();

cout << endl << endl << "Binary Tree 2 - postorder:" << endl;
intTree2.PostOrder();

cout << endl;

return 0;
}//end of main

