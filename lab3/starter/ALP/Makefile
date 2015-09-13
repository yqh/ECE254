########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################
# Makefile is modfied by ECE254 Lab Staff on June. 25th 2014           #
########################################################################

OBJECTS		= 
LIBRARIES	=
PROGRAMS	= fork-exec 


.PHONY:         all clean

# Default target: build everything.
all: $(PROGRAMS)

fork-exec: fork-exec.c 
	gcc -o $@ $<

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)
