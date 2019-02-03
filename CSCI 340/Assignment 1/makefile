CC = g++ 
CCFLAGS = -Wall 

assignment1 : assignment1.o
	$(CC) $(CCFLAGS) -o assignment1 assignment1.o

assignment1.o : assignment1.cpp person.h student.h courseinfo.h
	$(CC) $(CCFLAGS) -c assignment1.cpp

clean:
	- rm *.o
	- rm assignment1
