CC = g++
CCFLAGS = -Wall

assign3 : assign3.o screen.o brush.o
	$(CC) $(CCFLAGS) -o assign3 assign3.o screen.o brush.o

assign3.o : assign3.cc
	$(CC) $(CCFLAGS) -c assign3.cc

screen.o : screen.cc screen.h
	$(CC) $(CCFLAGS) -c screen.cc

brush.o : brush.cc brush.h
	$(CC) $(CCFLAGS) -c brush.cc

clean:
	- rm *.o
	- rm assign3
