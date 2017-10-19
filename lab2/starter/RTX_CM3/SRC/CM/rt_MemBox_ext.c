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
#include "rt_List.h"
#include "rt_Task.h"       /* added in ECE254 lab keil_proc */ 
#include "rt_MemBox_ext.h" /* added in ECE254 lab keil_proc */   

/* ECE254 Lab Comment: You may need to include more header files */

/*----------------------------------------------------------------------------
 *      Global Variables
 *---------------------------------------------------------------------------*/

struct OS_XCB rt_blocked;

/*----------------------------------------------------------------------------
 *      Global Functions
 *---------------------------------------------------------------------------*/


/*==========================================================================*/
/*  The following are added for ECE254 Lab Task Management Assignmet       */
/*==========================================================================*/

/*---------------- rt_alloc_box_s, task blocks when out of memory-----------*/

/*  
   @brief: Blocking memory allocation routine.
 */
void *rt_alloc_box_s (void *p_mpool) {
	
	void * ptr;
	P_TCB ptask;
	int task_id;
	
	ptr = rt_alloc_box(p_mpool);
	
	if(ptr == NULL){
		task_id = rt_tsk_self();
		ptask = os_active_TCB[task_id-1];
		rt_put_prio(&rt_blocked, ptask);
		rt_block(0xffff, 10);
		return NULL;
	}
	else return ptr;
}


/*----------- rt_free_box_s, pair with _s memory allocators ----------------*/
/**
 * @brief: free memory pointed by ptr, it will unblock a task that is waiting
 *         for memory.
 * @return: OS_R_OK on success and OS_R_NOK if ptr does not belong to gp_mpool 
 */
OS_RESULT rt_free_box_s (void *p_mpool, void *box) {
	U8 mem = rt_free_box(p_mpool,box);
	P_TCB head_task;
	
	if (!mem){
		if(rt_blocked.p_lnk != NULL){
			head_task = rt_get_first(&rt_blocked);
			head_task->ret_val = (U32)box;
			rt_dispatch(head_task);
		}
		else return (OS_R_NOK);
	}
	
	return (OS_R_OK);
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
