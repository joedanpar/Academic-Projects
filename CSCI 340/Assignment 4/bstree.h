#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <iomanip>
#include "bstnode.h"
#include "student.h"
#include "courseinfo.h"

using namespace std;

class BSTree
	{
	private:
	BSTNode * root;
	void Insert2(BSTNode *&, Student &, CourseInfo &);
	bool Search(BSTNode *, const Student &);
	void InOrder(BSTNode *) const;
	void PreOrder(BSTNode *) const;
	void PostOrder(BSTNode *) const;
	int Leaves(BSTNode *) const;
	int Size(BSTNode *) const;
	int Height(BSTNode *) const;
	void Clear(BSTNode *);

	public:
	BSTree();
	//BSTree(const BSTree &);
	~BSTree();
	/*void Create(BSTNode *, BSTNode *&);
	bool IsEmpty () const;
	void Insert1(const Student &);*/
	void Insert(Student &, CourseInfo &);
	/*bool Search(const Student &);*/
	void InOrder() const;
	/*void PreOrder() const;
	void PostOrder() const;
	int Leaves() const;
	int Size() const;
	int Height() const;*/
	void Clear();
	void PrintValue(BSTNode *) const;
	friend class BSTNode;
	};

BSTree::BSTree()
	{
	root = 0;
	}
	
/*BSTree::BSTree(const BSTree & InTree)
	{
	Create(InTree.root, root);
	}*/

BSTree::~BSTree()
	{
	Clear();
	}

/*void BSTree::Create(BSTNode * source, BSTNode *& dest)
	{
	if ( source != 0)
		{
		dest = new BSTNode(source->data);
		Create(source->leftchild, dest->leftchild);
		Create(source->rightchild, dest->rightchild);
		}
	}

bool BSTree::IsEmpty () const
	{
	if (root == 0)
		return true;
	else
		return false;
	}

void BSTree::Insert1(const Student & input)
	{
    BSTNode * ptr = root;
    BSTNode * parentptr = 0;
        
    int LeftHeight,
        RightHeight;
        
    BSTNode * newnode;
    newnode = new BSTNode;
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
	}*/

void BSTree::Insert(Student & input, CourseInfo & input2)
	{
	Insert2(root, input, input2);
	}

void BSTree::Insert2(BSTNode *& innode, Student & indata, CourseInfo & incourse)
	{
	if (innode == NULL)
		{
		BSTNode * newnode = new BSTNode();
		newnode->name = indata.get_name();
		newnode->Zid = indata.get_Zid();
		newnode->grade = incourse.get_grade();
		newnode->ID = incourse.get_ID();
		newnode->year = incourse.get_year();
		newnode->semester = incourse.get_semester();
        innode = newnode;
		}
	else if (incourse.get_grade() > innode->grade)
		Insert2(innode->rightchild, indata, incourse);
	else if (incourse.get_grade() < innode->grade)
		Insert2(innode->leftchild, indata, incourse);
	else
	    {
        if (indata.get_Zid() > innode->Zid)
           Insert2(innode->rightchild, indata, incourse);
        else if (indata.get_Zid() < innode->Zid)
           Insert2(innode->leftchild, indata, incourse);
        else
		   cout << "ERROR: The inserted data is already in the tree." << endl;
        }
	}
	
/*bool BSTree::Search(const Student & SearchValue)
	{
	return Search(root, SearchValue);
	}
	
bool BSTree::Search(BSTNode * innode, const Student & indata)
	{
	if (innode == 0)
		return false;
	if (indata >= innode->data)
		return Search(innode->rightchild, indata);
	else if (indata <= innode->data)
		return Search(innode->leftchild, indata);
	else
		return true;
	}*/

void BSTree::InOrder() const
	{
	InOrder(root);
	}

void BSTree::InOrder(BSTNode * innode) const
	{
	if (innode != 0)
		{
		InOrder(innode->leftchild);
		PrintValue(innode);
		InOrder(innode->rightchild);
		}
	}

/*void BSTree::PreOrder() const
	{
	PreOrder(root);
	}

void BSTree::PreOrder(BSTNode * innode) const
	{
	if (innode != 0)
		{
		PrintValue(innode);
		InOrder(innode->leftchild);
		InOrder(innode->rightchild);
		}
	}

void BSTree::PostOrder() const
	{
	PostOrder(root);
	}

void BSTree::PostOrder(BSTNode * innode) const
	{
	if (innode != 0)
		{
		InOrder(innode->leftchild);
		InOrder(innode->rightchild);
		PrintValue(innode);
		}
	}

int BSTree::Leaves() const
	{
	return Leaves(root);
	}

int BSTree::Leaves(BSTNode * innode) const
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

int BSTree::Size() const
	{
	return Size(root);
	}

int BSTree::Size(BSTNode * innode) const
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

int BSTree::Height() const
	{
	return Height(root);
	}

int BSTree::Height(BSTNode * innode) const
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
	}*/

void BSTree::Clear()
	{
	Clear(root);
	root = 0;
	}

void BSTree::Clear(BSTNode * innode)
	{
	if (innode != 0)
		{
		Clear(innode->leftchild);
		Clear(innode->rightchild);
		delete innode;
		}
	
	}

void BSTree::PrintValue(BSTNode * innode) const
	{
	cout << innode->name << "	" << innode->Zid << "	" << innode->grade << endl;
	}

#endif
