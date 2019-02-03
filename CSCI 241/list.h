#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::ostream;

struct Link
{
char data;
Link *next;
};

class List
{
friend ostream & operator<< (ostream &, const List &);

public:
List();
List(const char &);
List(const List &);
~List();

int Length() const;
void Insert(const char &);
bool IsPresent(const char &) const;
bool Delete(const char &);
void DeleteAll(const char &);
void PrintReverse() const;

bool operator==(const List &) const;
List & operator=(const List &);

private:

Link *headptr;

void Copy(const Link *, Link *&);
void Demolish(Link *&);
int ListLength(const Link *) const;
Link * Search(const char &) const;
void ReversePrint(const Link *) const;
};
#endif
