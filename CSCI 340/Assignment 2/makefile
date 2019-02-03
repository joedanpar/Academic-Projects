CC = g++ 
CCFLAGS = -Wall 

assignment2 : assignment2.o
	$(CC) $(CCFLAGS) -o assignment2 assignment2.o

assignment2.o : assignment2.cpp person.h student.h courseinfo.h list.h
	$(CC) $(CCFLAGS) -c assignment2.cpp

clean:
	- rm *.o
	- rm assignment2
