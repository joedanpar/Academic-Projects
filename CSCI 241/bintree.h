#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <iomanip>
#include "bintnode.h"

using std::cout;
using std::endl;

template <class T>
class BinTree
	{
	private:
	BinTNode<T> * root;
	void Insert2(BinTNode<T> *&, const T &);
	bool Search(BinTNode<T> *, const T &);
	void InOrder(BinTNode<T> *) const;
	void PreOrder(BinTNode<T> *) const;
	void PostOrder(BinTNode<T> *) const;
	int Leaves(BinTNode<T> *) const;
	int Size(BinTNode<T> *) const;
	int Height(BinTNode<T> *) const;
	void Clear(BinTNode<T> *);

	public:
	BinTree();
	BinTree(const BinTree<T> &);
	~BinTree();
	void Create(BinTNode<T> *, BinTNode<T> *&);
	bool IsEmpty () const;
	void Insert1(const T &);
	void Insert2(const T &);
	bool Search(const T &);
	void InOrder() const;
	void PreOrder() const;
	void PostOrder() const;
	int Leaves() const;
	int Size() const;
	int Height() const;
	void Clear();
	void PrintValue(BinTNode<T> *) const;
	};

template <class T>
BinTree<T>::BinTree()
	{
	root = 0;
	}
	
template <class T>
BinTree<T>::BinTree(const BinTree<T> & InTree)
	{
	Create(InTree.root, root);
	}

template <class T>
BinTree<T>::~BinTree()
	{
	Clear();
	}

template <class T>
void BinTree<T>::Create(BinTNode<T> * source, BinTNode<T> *& dest)
	{
	if ( source != 0)
		{
		dest = new BinTNode<T>(source->data);
		Create(source->leftchild, dest->leftchild);
		Create(source->rightchild, dest->rightchild);
		}
	}

template <class T>
bool BinTree<T>::IsEmpty () const
	{
	if (root == 0)
		return true;
	else
		return false;
	}

template <class T>
void BinTree<T>::Insert1(const T & input)
	{
    BinTNode<T> * ptr = root;
    BinTNode<T> * parentptr = 0;
        
    int LeftHeight,
        RightHeight;
        
    BinTNode<T> * newnode;
    newnode = new BinTNode<T>;
    newnode->data = input;
    newnode->leftchild = 0;
    newnode->rightchild = 0;
    	    
	if (IsEmpty())
		root = newnode;
	else
		{  
		while (ptr != 0)
			{
			parentptr = ptr;
			
			LeftHeight = Height(ptr->leftchild);
	        RightHeight = Height(ptr->rightchild);
    
			if (LeftHeight <= RightHeight)
				ptr = ptr->leftchild;
			else
				ptr = ptr->rightchild;
			}

			if (LeftHeight <= RightHeight)
				parentptr->leftchild = newnode;
			else
				parentptr->rightchild = newnode;
		}
	}

template <class T>
void BinTree<T>::Insert2(const T & input)
	{
	Insert2(root, input);
	}

template <class T>	
void BinTree<T>::Insert2(BinTNode<T> *& innode, const T & indata)
	{
	if (innode == 0)
		{
		BinTNode<T> * newnode = new BinTNode<T>(indata);
		innode = newnode;
		}
	else if (indata > innode->data)
		Insert2(innode->rightchild, indata);
	else if (indata < innode->data)
		Insert2(innode->leftchild, indata);
	else
		cout << "ERROR: The inserted data is already in the tree." << endl;
	}
	
template <class T>
bool BinTree<T>::Search(const T & SearchValue)
	{
	return Search(root, SearchValue);
	}
	
template <class T>
bool BinTree<T>::Search(BinTNode<T> * innode, const T & indata)
	{
	if (innode == 0)
		return false;
	if (indata >= innode->data)
		return Search(innode->rightchild, indata);
	else if (indata <= innode->data)
		return Search(innode->leftchild, indata);
	else
		return true;
	}

template <class T>
void BinTree<T>::InOrder() const
	{
	InOrder(root);
	}

template <class T>
void BinTree<T>::InOrder(BinTNode<T> * innode) const
	{
	if (innode != 0)
		{
		InOrder(innode->leftchild);
		PrintValue(innode);
		InOrder(innode->rightchild);
		}
	}

template <class T>
void BinTree<T>::PreOrder() const
	{
	PreOrder(root);
	}

template <class T>
void BinTree<T>::PreOrder(BinTNode<T> * innode) const
	{
	if (innode != 0)
		{
		PrintValue(innode);
		InOrder(innode->leftchild);
		InOrder(innode->rightchild);
		}
	}

template <class T>
void BinTree<T>::PostOrder() const
	{
	PostOrder(root);
	}

template <class T>
void BinTree<T>::PostOrder(BinTNode<T> * innode) const
	{
	if (innode != 0)
		{
		InOrder(innode->leftchild);
		InOrder(innode->rightchild);
		PrintValue(innode);
		}
	}

template <class T>
int BinTree<T>::Leaves() const
	{
	return Leaves(root);
	}

template <class T>
int BinTree<T>::Leaves(BinTNode<T> * innode) const
	{
	int leafcount = 0;
	if (innode != 0)
		{
		if (innode->leftchild == 0 && innode->rightchild == 0)
			leafcount ++;

		if (innode->leftchild != 0)
			leafcount += Leaves(innode->leftchild);
		if (innode->rightchild != 0)
			leafcount += Leaves(innode->rightchild);
		}
	return leafcount;
	}

template <class T>
int BinTree<T>::Size() const
	{
	return Size(root);
	}

template <class T>
int BinTree<T>::Size(BinTNode<T> * innode) const
	{
	int count = 0;
	if (innode != 0)
		{
		count ++;

		if (innode->leftchild != 0)
			count += Size(innode->leftchild);
		if (innode->rightchild != 0)
			count += Size(innode->rightchild);
		}
	return count;
	}

template <class T>
int BinTree<T>::Height() const
	{
	return Height(root);
	}

template <class T>
int BinTree<T>::Height(BinTNode<T> * innode) const
	{
	int leftheight = 0,
		rightheight = 0;

	//height = maximum{leftHeight, rightHeight} + 1
	
	if(innode == 0)
		return 0;

	leftheight = Height(innode->leftchild);
	rightheight = Height(innode->rightchild);

	if (leftheight > rightheight)
		return leftheight + 1;
	else
		return rightheight + 1;
	}

template <class T>
void BinTree<T>::Clear()
	{
	Clear(root);
	root = 0;
	}

template <class T>
void BinTree<T>::Clear(BinTNode<T> * innode)
	{
	if (innode != 0)
		{
		Clear(innode->leftchild);
		Clear(innode->rightchild);
		delete innode;
		}
	
	}

template <class T>
void BinTree<T>::PrintValue(BinTNode<T> * innode) const
	{
	int static linecount = 0;
	
	if (linecount % 10 == 0)
		cout << endl;
	cout << innode->data << " ";
	linecount ++;
	if (linecount >= Size(root))
		linecount = 0;
	}

#endif
