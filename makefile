CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

NodeSim : main.o Node.o
	$(CC) $(LFLAGS) main.o Node.o -o NodeSim

main.o : main.cpp Node.h
	$(CC) $(CFLAGS) main.cpp

Node.o : Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp

clean:
	\rm *.o NodeSim

