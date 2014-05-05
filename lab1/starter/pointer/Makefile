
# Makefile, OS lab0-A
# Irene Huang, 2013/05/05

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g


OBJS=pointer.o

all: pointer.out

pointer.out: $(OBJS) 
	$(LD) $(CFLAGS) $(LDFLAGS) -o main.out $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.out 
