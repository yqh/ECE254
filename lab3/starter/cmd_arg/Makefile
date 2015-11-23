# ECE254 Makefile
# 2015/10/20

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g


OBJS=cmd_arg.o

all: cmd_arg.out

cmd_arg.out: $(OBJS) 
	$(LD) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.out 
