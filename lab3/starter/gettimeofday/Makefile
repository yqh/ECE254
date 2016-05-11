# ECE254 Lab Linux Port
# Makefile: build time.out to show how to use gettimeofday

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g

PROGRAM=time.out


all: $(PROGRAM)

time.out: time.o 
	$(LD) -o $@ $<  $(LDFLAGS)

time.o: time.c 
	$(CC) $(CFLAGS) -c $< 

.PHONY: clean
clean:
	rm -f *.o *.out 
