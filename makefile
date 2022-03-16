CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver tester

myvector.o: myvector.cpp myvector.h
	$(CC) $(CFLAGS) -c myvector.cpp

driver: myvector.o driver.cpp
	$(CC) $(CFLAGS) -o driver driver.cpp myvector.o

tester: myvector.o tester.cpp
	$(CC) $(CFLAGS) -o tester tester.cpp myvector.o

clean:
	rm *.o driver tester