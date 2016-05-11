/**
  * ECE254 Linux Dynamic Memory Management Lab
  * @file: main_test.c
  * @brief: The main file to write tests of memory allocation algorithms
  */ 

/* includes */
/* system provided header files. You may add more */
#include <stdio.h>

/* non-system provided header files. 
   Do not include more user-defined header files here
 */
#include "mem.h"



int main(int argc, char *argv[])
{

	int num = 0;
	void *p, *q;

	best_fit_memory_init(1024);	// initizae 1KB, best fit

	p = best_fit_alloc(8);		// allocate 8B
	printf("p=%p\n", p);
	if ( p != NULL ) {
		best_fit_dealloc(p);	
	}
	num = best_fit_count_extfrag(4);

	worst_fit_memory_init(1024);	// initizae 1KB, worst fit

	q = worst_fit_alloc(8);		// allocate 8B
	printf("q=%p\n", q);
	if ( q != NULL ) {
		worst_fit_dealloc(q);	
	}
	num = worst_fit_count_extfrag(4);

	return 0;
}
