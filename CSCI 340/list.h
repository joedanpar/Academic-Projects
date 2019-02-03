/************************************************************
* CSCI 340 section 2                           Spring, 2009	*
* Name: Joe Daniel Parker                           z158012	*
* Assignment 3												*
* Due Date: 02/20/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

//class prototypes
template <class T>
class List;

class CourseInfo;

/****************************************************************************
* Class:		Node (Template Class)										*
* Data Members:	Data Field (data type <T>)									*
*				Link to next node in list									*
* Methods:		Constructor													*
*				Destructor													*
*				Accessor methods for data members							*
*				infoPrint (prints out the Student's information				*
*				add_class (inserts a new node into the class list)			*
*				update_class (updates the Class node from within the class)	*
****************************************************************************/
template <class T>
class Node
	{
    private:
	T data;
	Node<T> * next;
	
	public:
    T get_data() const;
    Node<T> * get_next() const;
    void set_data(const T &);
    void set_next(const Node<T> * &);
    
    friend class List<T>;
	};
	
template <class T>
T Node<T>::get_data() const
  {
  return data;
  }

/****************************************************************************
* Class:		List (Template Class)										*
* Data Members:	headptr (links to first Node in list)						*
* Methods:		Constructor													*
*				Destructor													*
*				Accessor methods for data members							*
*				infoPrint (prints out the Student's information				*
*				add_class (inserts a new node into the class list)			*
*				update_class (updates the Class node from within the class)	*
****************************************************************************/
template <class T>
class List
	{
    //ostream & operator<< (ostream &, const List<T> &);

	public:
	List();
	List(const List<T> &);
	~List();

	int Length() const;
	void Insert(const T &);
	void deleteNode(const T &);
	Node<T> * clone(Node<T> *);
	void clear(Node<T> * &);
	Node<T> * isInList(const T &) const;
	void print(Node<T> *) const;
	Node<T> * get_headptr();

	//List<T> & operator= (const List<T> &);

	private:

	Node<T> * headptr;

	void Copy(const Node<T> *, Node<T> * &);
	int r_Length(const Node<T> *) const;
	Node<T> * r_deleteNode(const T &, Node<T> *);
	Node<T> * r_isInList(const T &, Node<T> *) const;
	bool isEmpty();
	
	friend class CourseInfo;
	};

/****************************************************************
* Function:		Constructor										*
* Useage:		List()											*
* Logic:		Initialize the data member in the class to NULL	*
****************************************************************/
template <class T>
List<T>::List()
	{
	headptr = NULL;
	}

/************************************************************
* Function:		Copy Constructor							*
* Useage:		List(otherList)								*
* Logic:		calls the copy method, which transfers data	*
*				from one List to the other					*
************************************************************/
template <class T>
List<T>::List(const List<T> & l)
	{
	Copy(l.headptr, headptr);
	}

/************************************************************************************
* Function:		Destructor															*
* Useage:		delete List															*
* Logic:		Calls the clear method, which deletes every node in the list first,	*
*				then removes the list class itself.									*
************************************************************************************/
template <class T>
List<T>::~List()
	{
	clear(headptr);
	}

/************************************************************************************
* Function:		Length																*
* Useage:		length()															*
* Logic:		calls the recursive form of this function, below.					*
************************************************************************************/
template <class T>
int List<T>::Length() const
	{
	return r_Length(headptr);
	}

/************************************************************************************
* Function:		Insert																*
* Useage:		Insert(objectName)													*
* Logic:		inserts a new Node into the linked list.							*
************************************************************************************/
template <class T>
void List<T>::Insert(const T & c)
	{
	Node<T> *temp = new Node<T>;
	temp->data.set_ID(c.get_ID());
	temp->data.set_year(c.get_year());
	temp->data.set_semester(c.get_semester());
	temp->data.set_grade(c.get_grade());
	temp->next = headptr;
	headptr = temp;
	}

/********************************************************************************
* This was the assignment operator overload, but since I didn't need it for this*
* Assignment, I left it commented out for now.									*
*********************************************************************************
//This is the assignment operator overloader.  It deletes the current
//list, allocates new memory for a list as big as the one passed in,
//and sets each Node<T> in the new list to the respective character in
//the passed list.
template <class T>
List<T> & List<T>::operator=(const List<T> & l)
	{
	clear(headptr);
	Copy(l.headptr, headptr);
	return *this;
	}*/

/************************************************************************************
* Function:		copy																*
* Useage:		copy(Node1, Node2)													*
* Logic:		copies data from one node to the other.								*
************************************************************************************/
template <class T>
void List<T>::Copy(const Node<T> * l1, Node<T> *& l2)
	{
	if (l1 != NULL)
		{
		l2 = new Node<T>;
		l2->data = l1->data;
		Copy(l1->next, l2->next);
		}
	else
		l2 = NULL;
	}

/************************************************************************************
* Function:		clear																*
* Useage:		clear(Node)															*
* Logic:		traverses through list until it reaches the end, then deletes each	*
*				Node on its way back to the front.									*
************************************************************************************/
template <class T>
void List<T>::clear(Node<T> *& l)
	{
	if (l != NULL)
		{
		clear(l->next);
		delete l;
		}
	}

/************************************************************************************
* Function:		length (recursive)													*
* Useage:		r_recursive(Node)													*
* Logic:		traverses through list, counting the number of times it passes from	*
*				one node to the next.  It then returns this value.					*
************************************************************************************/
template <class T>
int List<T>::r_Length(const Node<T> * l) const
	{
	int count = 0;
	Node<T> *temp = headptr;
	while (temp != NULL)
		{
		count++;
		temp = temp->next;
		}
	return count;
	}

/************************************************************************************
* Function:		delete node															*
* Useage:		deleteNode(objectname)												*
* Logic:		calls the recursive function, below.								*
************************************************************************************/
template <class T>
void List<T>::deleteNode(const T & delItem)
	{
	headptr = r_deleteNode(delItem, headptr);
	}
	
/************************************************************************************
* Function:		delete node (recursive)												*
* Useage:		dleteNode(objectName, headptr)										*
* Logic:		traverses through list until it finds a matching node, then deletes	*
*				it.																	*
************************************************************************************/
template <class T>
Node<T> * List<T>::r_deleteNode(const T & delItem, Node<T> * ptr)
	{
	if (ptr == NULL)
		return NULL;
	else if (delItem == ptr->data)
		{
		Node<T> * nextNode = ptr->next;
		delete ptr;
		return nextNode;
		}
	else
		{
		ptr->next = r_deleteNode(delItem, ptr->next);
		return ptr;
		}
	}

/************************************************************************************
* Function:		is in list															*
* Useage:		isInList(objectName)												*
* Logic:		calls the recursive function, below.								*
************************************************************************************/
template <class T>
Node<T> * List<T>::isInList(const T & input) const
	{
	return r_isInList(input, headptr);
	}

/************************************************************************************
* Function:		is in list (recurseive)												*
* Useage:		r_isInList(objectName, headptr)										*
* Logic:		traverses through list until it finds a matching node, then returns	*
*				it.																	*
************************************************************************************/
template <class T>
Node<T> * List<T>::r_isInList(const T & input, Node<T> * ptr) const
	{
	if (ptr == NULL)
		return NULL;
	else if (ptr->data == input)
		return ptr;
	else
		return r_isInList(input, ptr->next);
	}

/********************************************************************************
* This was the output operator overload, but I couldn't get it to work at this	*
* point in time, so I just commented it out for later use.						*
*********************************************************************************
template <class T>
ostream & operator<< (ostream & cout, const List<T> & l)
  {
  Node<T> * temp = l.headptr;
  while (temp != NULL)
    {
    cout << temp->data.get_ID() << " " << temp->data.get_year() << " "
         << temp->data.get_semester() << " " << temp->data.get_grade() << endl;
    temp = temp->next;
    }
  return cout;
  }*/

/************************************************************************************
* Function:		print																*
* Useage:		print(objectName)													*
* Logic:		prints out the data from the node to the user.						*
************************************************************************************/
template <class T>
void List<T>::print(Node<T> * l) const
    {
    Node<T> * temp = l;
    while (temp != NULL)
        {
        cout << temp->data.get_ID() << " " << temp->data.get_year() << " "
             << temp->data.get_semester() << " " << temp->data.get_grade() << endl;
        temp = temp->next;
        }
    }

/************************************************************************************
* Function:		get head pointer													*
* Useage:		get_headptr()														*
* Logic:		returns the private data member "headptr".							*
************************************************************************************/
template <class T>
Node<T> * List<T>::get_headptr()
    {
    return headptr;    
    }

template <class T>
bool List<T>::isEmpty()
	{
	if (headptr == NULL)
		return true;
	return false;
	}

#endif
