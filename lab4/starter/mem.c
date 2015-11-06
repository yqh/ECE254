/**
 * @file memory.c
 * @brief: ECE254 Lab: memory allocation algorithm comparison template file
 * @author: 
 * @date: 2015-11-06
 */

/* includes */
#include <stdio.h> 
#include <stdlib.h> 
#include "mem.h"

/* defines */

/* Global varaiables */


/* Functions */

/* memory initializer */
int memory_init(size_t size, int algorithm)
{

	// To be completed by students
	// You call malloc once here to obtain the memory to be managed.
	return 0;

}


void *best_fit_alloc(size_t size)
{
	// To be completed by students
	return NULL;
}


void *worst_fit_alloc(size_t size)
{
	// To be completed by students
	return NULL;
}

/* memory de-allocator */
void dealloc(void *bp) 
{

	// To be completed by students
	return;
}

/* memory algorithm metric utility function(s) */

/* count how many contiguous bytes are less than 32B */ 
int count_extfrag(void)
{
	// To be completed by students
	return 0;
}

