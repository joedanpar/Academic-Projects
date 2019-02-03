CC = g++ 
CCFLAGS = -Wall 

assignment4 : assignment4.o
	$(CC) $(CCFLAGS) -o assignment4 assignment4.o

assignment4.o : assignment4.cpp person.h student.h courseinfo.h registrationsystem.h bstree.h bstnode.h
	$(CC) $(CCFLAGS) -c assignment4.cpp

clean:
	- rm *.o
	- rm assignment4
