#ifndef BINTNODE_H
#define BINTNODE_H

template <class T>
class BinTree;

template <class T>
class BinTNode
	{
	private:
	T data;
	BinTNode<T> * leftchild,
                * rightchild;
	
	public:
	BinTNode(T = T(), BinTNode<T>* = 0, BinTNode<T>* = 0);
	friend class BinTree<T>;
	};
	
template <class T>
BinTNode<T>::BinTNode(T dat, BinTNode<T> * left, BinTNode<T> * right)
	{
	data = dat;
	leftchild = left;
	rightchild = right;
	}
	
#endif
