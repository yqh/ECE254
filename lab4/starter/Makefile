# Makefile, ECE254 lab4 Linux variable size memory management lab 
# Yiqing Huang, 2017/07/10

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
	$(LD) -o $@ $^ $(LDLIBS) $(LDFLAGS) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< 

%.d: %.c
	gcc -MM -MF $@ $<

-include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -f *.d *.o $(TARGETS) 
