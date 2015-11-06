# Makefile, ECE254 lab4 Linux variable size memory management lab 
# Yiqing Huang, 2015/10/26

CC = gcc
CFLAGS = -Wall -g
LD = gcc
LDFLAGS = -g 
LDLIBS = 

SRCS   = mem.c main_test.c 
OBJS   = mem.o main_test.o
TARGETS= main_test.out 

all: ${TARGETS}


main_test.out: $(OBJS) 
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< 

%.d: %.c
	gcc -MM -MF $@ $<

-include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -f *.d *.o $(TARGETS) 
