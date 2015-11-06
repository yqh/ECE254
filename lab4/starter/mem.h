/**
 * @file memory.h
 * @brief: ECE254 Lab: memory allocators
 * @author: 
 * @date: 2015-11-06
 */

#include <stddef.h>

#define BEST_FIT  1	// best fit strategy
#define WORST_FIT 2	// worst fit strategy


/* memory initializer */
/**
 * @brief: initialize a chunck of memory which has a size of size
 * @ size_t size: the size of the memory to be initialized
 * @ int algorithm: the allocation algorithm macro
 */

int memory_init(size_t size, int algorithm);

/* memory allocators */
void *best_fit_alloc(size_t size);
void *worst_fit_alloc(size_t size);

/* memory de-allocator, immediate coalesce */
void dealloc(void *ptr);

/* memory algorithm metric utility function(s) */

/* count how many contiguous bytes are less than 32B */ 
int count_extfrag(void);

