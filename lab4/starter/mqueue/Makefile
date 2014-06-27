# ECE254 lab4 Linux Port
# Makefile: build mqueue sender and receiver example code

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g -lrt


OBJS1=sender.o point.o
OBJS2=receiver.o point.o

all: sender.out receiver.out

sender.out: $(OBJS1) 
	$(LD) $(LDFLAGS) -o $@ $(OBJS1) 

sender.o: sender.c common.h point.h 
	$(CC) $(CFLAGS) -c sender.c 

receiver.out: $(OBJS2) 
	$(LD) $(LDFLAGS) -o $@ $(OBJS2) 

receiver.o: receiver.c common.h point.h 
	$(CC) $(CFLAGS) -c receiver.c 

point.o: point.c point.h 
	$(CC) $(CFLAGS) -c point.c 


.PHONY: clean
clean:
	rm -f *.o *.out 
