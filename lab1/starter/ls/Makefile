
# ECE254/lab1/starter/ls/Makefile
# Y. Huang, 2015/05/01

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g


OBJS1=ls_ftype.o
OBJS2=ls_fname.o
OBJS3=ls_fperm.o

all: ls_ftype.out ls_fname.out ls_fperm.out

ls_ftype.out: $(OBJS1) 
	$(LD) $(LDFLAGS) -o $@ $^

ls_fname.out: $(OBJS2) 
	$(LD) $(LDFLAGS) -o $@ $^ 

ls_fperm.out: $(OBJS3) 
	$(LD) $(LDFLAGS) -o $@ $^ 

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.out 
