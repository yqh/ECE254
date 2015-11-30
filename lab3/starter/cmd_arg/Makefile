# ECE254 Makefile
# 2015/11/30

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g


OBJS=cmd_arg.o

all: cmd_arg.out

cmd_arg.out: $(OBJS) 
	$(LD) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.out 
