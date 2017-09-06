/**
  * ECE254 Linux Dynamic Memory Management Lab
  * @file: main_test.c
  * @brief: The main file to write tests of memory allocation algorithms
  */ 

/* includes */
/* system provided header files. You may add more */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* non-system provided header files. 
   Do not include more user-defined header files here
 */
#include "mem.h"



int main(int argc, char *argv[])
{
	int num = 0;
	int algo = 0; // default algorithm to test is best fit  
	void *p, *q;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <0/1>. 0 for best fit and 1 for worst fit \n", argv[0]);
		exit (1);
	} else if (!strcmp(argv[1], "1") || !strcmp(argv[1], "0")) {
		algo = atoi(argv[1]);
	} else {
		fprintf(stderr, "Invalid argument, please specify 0 or 1\n");
		exit(1);
	}
	
	if ( algo == 0 ) {
		best_fit_memory_init(1024);	// initizae 1KB, best fit

		p = best_fit_alloc(8);		// allocate 8B
		printf("best fit: p=%p\n", p);
		if ( p != NULL ) {
			best_fit_dealloc(p);	
		}
		num = best_fit_count_extfrag(4);
	} else if ( algo == 1 ) {

		worst_fit_memory_init(1024);	// initizae 1KB, worst fit

		q = worst_fit_alloc(8);		// allocate 8B
		printf("worst fit: q=%p\n", q);
		if ( q != NULL ) {
			worst_fit_dealloc(q);	
		}
		num = worst_fit_count_extfrag(4);
	} else {
		fprintf(stderr, "Should not reach here!\n");
		exit(1);
	}

	printf("num = %d\n", num);

	return 0;
}
