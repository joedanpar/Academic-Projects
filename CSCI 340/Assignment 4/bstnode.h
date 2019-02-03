#ifndef BSTNODE_H
#define BSTNODE_H

#include <string>

using namespace std;

class BSTree;

class BSTNode
	{
	private:
	string name,
           Zid,
           grade,
           ID,
           year,
           semester;

	BSTNode * leftchild,
            * rightchild;
	
	public:
	BSTNode();
	friend class BSTree;
	};
	
BSTNode::BSTNode()
	{
	name = "";
	Zid = "";
	grade = "";
	ID = "";
	year = "";
	semester = "";
	leftchild = NULL;
	rightchild = NULL;
	}
	
#endif
