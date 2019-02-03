CC = g++ 
CCFLAGS = -Wall 

assignment7 : assignment7.o
	$(CC) $(CCFLAGS) -o assignment7 assignment7.o

assignment7.o : assignment7.cpp person.h student.h courseinfo.h registrationsystem.h studentgrade.h
	$(CC) $(CCFLAGS) -c assignment7.cpp

clean:
	- rm *.o
	- rm assignment7
