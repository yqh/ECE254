/*----------------------------------------------------------------------------
 *      ECE254 Lab Task Management
 *----------------------------------------------------------------------------
 *      Name:    RT_MEMBOX_ext.C
 *      Purpose: Interface functions for blocking 
 *               fixed memory block management system
 *      Rev.:    V4.60
 *----------------------------------------------------------------------------
 *      This code is extends the RealView Run-Time Library.
 *      Created by University of Waterloo ECE254 Lab Staff.
 *---------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------
 *      Includes
 *---------------------------------------------------------------------------*/
 
#include "rt_TypeDef.h"
#include "RTX_Config.h"
#include "rt_System.h"
#include "rt_MemBox.h"
#include "rt_HAL_CM.h"
#include "rt_Task.h"       /* added in ECE254 lab keil_proc */ 
#include "rt_MemBox_ext.h" /* added in ECE254 lab keil_proc */   

/* ECE254 Lab Comment: You may need to include more header files */

/*----------------------------------------------------------------------------
 *      Global Variables
 *---------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 *      Global Functions
 *---------------------------------------------------------------------------*/

/*==========================================================================*/
/*  The following are added for ECE254 Lab Task Management Assignmet       */
/*==========================================================================*/

/*---------------- rt_alloc_box_s, task blocks when out of memory-----------*/

/**  
   @brief: Blocking memory allocation routine.
 */
void *rt_alloc_box_s (void *p_mpool) {
	
	/* Add your own code here. Change the following line accordingly */
	return NULL;
}


/*----------- rt_free_box_s, pair with _s memory allocators ----------------*/
/**
 * @brief: free memory pointed by ptr, it will unblock a task that is waiting
 *         for memory.
 * @return: OS_R_OK on success and OS_R_NOK if ptr does not belong to gp_mpool 
 */
OS_RESULT rt_free_box_s (void *p_mpool, void *box) {
	/* Add your own code here. Change the following line accordingly */
	return (OS_R_OK);
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
