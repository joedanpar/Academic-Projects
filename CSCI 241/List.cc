#include "List.h"
#include <iostream>

using std::ostream;
using std::cout;

//This is the basic constructor, it set's the link to NULL
List::List()
  {
  headptr = 0;
  }

//This constructor creates a new link and adds a value to its data
//section
List::List(const char & c)
  {
  Link *a = new Link;
  a->data = c;
  a->next = NULL;
  headptr = a;
  }

//this is the copy constructor.  It does what it says it does,
//copy an existing list into a new one.
List::List(const List & l)
  {
  Copy(l.headptr, headptr);
  }

//this is the deconstructor, which frees up an entire linked list
//in memory
List::~List()
  {
  Demolish(headptr);
  }

//this is the output operator overloader.  it displays each link's data
//one by one.
ostream & operator << (ostream & cout, const List & l)
  {
  Link *temp = l.headptr;
  while (temp != NULL)
    {
    cout << temp->data << " ";
    temp = temp->next;
    }
  return cout;
  }

//This function calls the private function to grab
//the link's length
int List::Length() const
  {
  return ListLength(headptr);
  }

//this inserts the passed character into the beginning
//of the list
void List::Insert(const char & c)
  {
  Link *temp = new Link;
  temp->data = c;
  temp->next = headptr;
  headptr = temp;
  }

//This checks to see if the passed character is shown
//in the list at least once.
bool List::IsPresent(const char &c) const
  {
  if (Search(c) != 0 || headptr->data == c)
    return true;
  return false;
  }

//This deletes the first instance of the passed character, and returns
//true, if it is not found, it returns false.
bool List::Delete(const char & c)
  {
  Link *temp1,
       *temp2;
  temp1 = Search(c);
  temp2 = temp1->next;
  if (temp1 == NULL)
    {
    if (temp1->data == c)
      {
      temp2 = headptr;
      temp1->next = temp2->next;
      delete temp2;
      return true;
      }
    return false;
    }
  temp1->next = temp2->next;
  delete temp2;
  return true;
  }

//This deletes all instances of the passed character in the list
void List::DeleteAll(const char & c)
  {
  while (IsPresent(c))
    Delete(c);
  }

//This calles the private function to print the list in reverse order
void List::PrintReverse() const
  {
  ReversePrint(headptr);
  }

//This is the equality operator overloader.  It checks to see if
//both lists have the same elements in the exact same order.
//If so, return true, if not, return false.
bool List::operator==(const List & l) const
  {
  Link *temp1 = headptr,
       *temp2 = headptr;
  if (Length() == l.Length())
    {
    while (temp1 != NULL && temp2 != NULL)
      {
      if (temp1->data == temp2->data)
        {
        temp1 = temp1->next;
        temp2 = temp2->next;
        }
      else return false;
      }
    return true;
    }
  return false;
  }

//This is the assignment operator overloader.  It deletes the current
//list, allocates new memory for a list as big as the one passed in,
//and sets each link in the new list to the respective character in
//the passed list.
List & List::operator=(const List & l)
  {
  Demolish(headptr);
  Copy(l.headptr, headptr);
  return *this;
  }

//This copies each link from the second list into the first recursively
void List::Copy(const Link * l1, Link *& l2)
  {
  if (l1 != NULL)
    {
    l2 = new Link;
    l2->data = l1->data;
    Copy(l1->next, l2->next);
    }
  else
    l2 = NULL;
  }

//This recursively goes through the list first, then deletes each link
//from the end to the front.
void List::Demolish(Link *& l)
  {
  if (l != NULL)
    {
    Demolish(l->next);
    delete l;
    }
  }

//This counts each list, as long as it exists, and returns the number of
//links in the list.
int List::ListLength(const Link * l) const
  {
  int count = 0;
  Link *temp = headptr;
  while (temp != NULL)
    {
    count++;
    temp = temp->next;
    }
  return count;
  }

//This searches the list for the passed character, and returns the
//pointer to the link before it occured.
Link * List::Search(const char & c) const
  {
  Link *temp1 = headptr,
       *temp2 = headptr;

  if (temp1->data == c)
    return NULL;
  while (temp1 != NULL)
    {
    if (temp1->data != c)
      {
      temp2 = temp1;
      temp1 = temp1->next;
      }
    else
      return temp2;
    }
  return NULL;
  }

//this recursively travels to the end of teh list, then prints each link
//back to the front.
void List::ReversePrint(const Link * l) const
  {
  if (l != NULL)
    {
    ReversePrint(l->next);
    cout << l->data << " ";
    }
  }

