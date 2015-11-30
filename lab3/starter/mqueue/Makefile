# ECE254 Lab Linux Port
# Makefile: build mqueue sender and receiver example code

CC=gcc
CFLAGS=-Wall -g
LD=gcc
LDFLAGS=-g -lrt


OBJS1=sender.o point.o
OBJS2=receiver.o point.o

all: sender.out receiver.out

sender.out: $(OBJS1) 
	$(LD) -o $@ $(OBJS1) $(LDFLAGS) 

receiver.out: $(OBJS2) 
	$(LD) -o $@ $(OBJS2) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

%.d: %.c
	$(CC) -MM -MF $@ $<

-include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -f *.d *.o *.out 
