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
	U16 size = os_stackinfo;
	U16 stack_used;
	U16 stack;
	U16 tsk_stack;
	
	p_task_info->task_id     = task_id;
	p_task_info->state       = ((P_TCB) os_active_TCB[task_id-1])->state;
	p_task_info->prio        = ((P_TCB) os_active_TCB[task_id-1])->prio;
	p_task_info->ptask       = ((P_TCB) os_active_TCB[task_id-1])->ptask;
	
	stack = (U16) (((P_TCB) os_active_TCB[task_id-1])->stack);
	
	if(p_task_info->state == RUNNING){
		tsk_stack = (U16)rt_get_PSP();
	}else{
		tsk_stack = (U16) (((P_TCB) os_active_TCB[task_id-1])->tsk_stack);
	}
	stack_used = (100*( size - (tsk_stack-stack ))) / size;
	
	p_task_info->stack_usage = (U8) stack_used;
	return OS_R_OK;
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
