/**
 * @file memory.h
 * @brief: ECE254 Lab: memory allocators
 * @author: 
 * @date: 2015-11-20
 */

#ifndef MEM_H_
#define MEM_H_

#include <stddef.h>

/* memory initializers */
int best_fit_memory_init(size_t size);
int worst_fit_memory_init(size_t size);

/* memory allocators */
void *best_fit_alloc(size_t size);
void *worst_fit_alloc(size_t size);

/* memory de-allocators, immediate coalesce */
void best_fit_dealloc(void *ptr);
void worst_fit_dealloc(void *ptr);

/* memory algorithm metric utility function(s) */

/* count how many contiguous bytes are less than 32B */ 
int best_fit_count_extfrag(size_t size);
int worst_fit_count_extfrag(size_t size);

#endif // !MEM_H_
