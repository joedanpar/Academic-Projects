CC = g++ 
CCFLAGS = -Wall 

assignment2 : assignment3.o
	$(CC) $(CCFLAGS) -o assignment3 assignment3.o

assignment2.o : assignment3.cpp person.h student.h courseinfo.h list.h stack.h
	$(CC) $(CCFLAGS) -c assignment3.cpp

clean:
	- rm *.o
	- rm assignment3
