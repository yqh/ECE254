/*----------------------------------------------------------------------------
 *      ECE254 Lab Task Management
 *----------------------------------------------------------------------------
 *      Name:    RT_TASK_ext.C
 *      Purpose: Interface functions for extended task management  
 *      Rev.:    V4.60
 *----------------------------------------------------------------------------
 *      This code extends the RealView Run-Time Library.
 *      Created by University of Waterloo ECE254 Lab Staff.
 *---------------------------------------------------------------------------*/

#include "rt_TypeDef.h"
#include "RTX_Config.h"
#include "rt_System.h"
#include "rt_Task.h"
#include "rt_List.h"
#include "rt_MemBox.h"
#include "rt_Robin.h"
#include "rt_HAL_CM.h"
#include "rt_Task_ext.h"

/*----------------------------------------------------------------------------
 *      Global Variables
 *---------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 *      Local Functions
 *---------------------------------------------------------------------------*/
/*--------------------------- rt_tsk_count_get ------------------------------*/
/* added in ECE254 lab keil_rtx */
int rt_tsk_count_get (void) {
	U8 i=1;
	int count=0;
	if(os_idle_TCB.state != INACTIVE){
		count++;
	}
	for(i = 0; i < os_maxtaskrun; i++) {
		if (os_active_TCB[i] != NULL) {
			count++;
		} 
	}
	return count;
}

/*--------------------------- rt_tsk_get ------------------------------------*/
/* added in ECE254 lab keil_proc */
OS_RESULT rt_tsk_get (OS_TID task_id, RL_TASK_INFO *p_task_info) {
	P_TCB current_task;
	U32 stack_size;
	U32 stack_unused;
	U32 stack_base;
	U32 tsk_top;
	U32 stack_percent;
	
	if(task_id == os_idle_TCB.task_id){
		//If the task is the idle task, set current_task to idle TCB
		current_task = &os_idle_TCB;
	}else if(task_id > os_maxtaskrun || os_active_TCB[task_id-1] == NULL){
		//Error, return not OK
		return OS_R_NOK;
	}else{
		current_task = (P_TCB) (os_active_TCB[task_id-1]);
	}
	
	p_task_info->task_id     = task_id;
	p_task_info->state       = current_task->state;
	p_task_info->prio        = current_task->prio;
	p_task_info->ptask       = current_task->ptask;
	
	
	
	stack_size = (U16) (os_stackinfo); /* 128*4 */
	stack_base = (U32) (current_task->stack);
	
	if((p_task_info->state) == RUNNING){
		
		tsk_top = (U32) (rt_get_PSP());
	}else{
		tsk_top = (U32) (current_task->tsk_stack);
	}
	stack_unused = (tsk_top - stack_base);
	stack_percent = (100*( stack_size - stack_unused)) / stack_size;
	
	p_task_info->stack_usage = (U8) stack_percent;
	return OS_R_OK;
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
