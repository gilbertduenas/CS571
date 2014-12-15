CC = g++
CFLAGS = -c -Wall

all: a.out

a.out: cs571HW8.1.o llist.o
	$(CC) -o a.out cs571HW8.1.o llist.o

cs571DuenasHW8.1.o: cs571HW8.1.cpp llist.h
	$(CC) $(CFLAGS) cs571HW8.1.cpp

llist.o: llist.h llist.cpp
	$(CC) $(CFLAGS) llist.cpp
	