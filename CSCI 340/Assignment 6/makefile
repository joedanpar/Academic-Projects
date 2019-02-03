CC = g++ 
CCFLAGS = -Wall 

assignment6 : assignment6.o
	$(CC) $(CCFLAGS) -o assignment6 assignment6.o

assignment6.o : assignment6.cpp person.h student.h courseinfo.h registrationsystem.h Avl.h Comparable.h studentgrade.h
	$(CC) $(CCFLAGS) -c assignment6.cpp

clean:
	- rm *.o
	- rm assignment6
