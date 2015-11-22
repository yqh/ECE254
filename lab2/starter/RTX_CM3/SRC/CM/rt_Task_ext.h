/*----------------------------------------------------------------------------
 *      ECE254 Lab Task Management
 *----------------------------------------------------------------------------
 *      Name:    RT_TASK_EXT.H
 *      Purpose: Header file for extended task management  
 *      Rev.:    V4.60
 *----------------------------------------------------------------------------
 *      This code extends the RealView Run-Time Library.
 *      Created by University of Waterloo ECE254 Lab Staff.
 *---------------------------------------------------------------------------*/
/* Definitions */

/* Structures */
/* added in ECE254 lab keil_proc, better to put in a separate file. */
typedef struct rl_task_info {
  U8     state;                   /* Task state                              */
  U8     prio;                    /* Execution priority                      */
  U8     task_id;                 /* Task ID value for optimized TCB access  */
  U8     stack_usage;             /* Stack usage percent value. eg.=58 if 58%*/
  void   (*ptask)();              /* Task entry address                      */ 
} RL_TASK_INFO;

/* Variables */

/* Functions */

/* added in ECE254 lab keil_rtx */
extern int rt_tsk_count_get(void);

/* added in ECE254 lab keil_proc */
extern OS_RESULT rt_tsk_get(OS_TID task_id, RL_TASK_INFO *p_task_info);


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
