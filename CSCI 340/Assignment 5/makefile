CC = g++ 
CCFLAGS = -Wall 

assignment5 : assignment5.o
	$(CC) $(CCFLAGS) -o assignment5 assignment5.o

assignment5.o : assignment5.cpp person.h student.h courseinfo.h registrationsystem.h Avl.h Comparable.h studentgrade.h
	$(CC) $(CCFLAGS) -c assignment5.cpp

clean:
	- rm *.o
	- rm assignment5
