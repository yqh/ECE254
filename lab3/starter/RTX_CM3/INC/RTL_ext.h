/*----------------------------------------------------------------------------
 *      RL-ARM - A P I 
 *----------------------------------------------------------------------------
 *      Name:    RTL_ext.h 
 *      Purpose: Application Programming Interface for ECE254 Labs
 *      Rev.:    V4.60
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2012 KEIL - An ARM Company. All rights reserved.
 *      NOTE: modfied to complete ECE254 kernel programming
 *---------------------------------------------------------------------------*/

#ifndef __RTL_EXT_H__
#define __RTL_EXT_H__

/*----------------------------------------------------------------------------
 *                             RTX Kernel API
 *---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"  {
#endif

typedef signed char     S8;
typedef unsigned char   U8;
typedef short           S16;
typedef unsigned short  U16;
typedef int             S32;
typedef unsigned int    U32;
typedef long long       S64;
typedef unsigned long long U64;
typedef unsigned char   BIT;
typedef unsigned int    BOOL;

/* Definition of Semaphore type */
typedef U32 OS_SEM[2];

/* Definition of Mailbox type */
#define os_mbx_declare(name,cnt)    U32 name [4 + cnt]
typedef U32 OS_MBX[];

/* Definition of Mutex type */
typedef U32 OS_MUT[3];

/* Task Identification number. */
typedef U32 OS_TID;

/* Function return of system calls returning an object identification */
typedef void *OS_ID;

/* Function return of system calls indicating an event or completion state */
typedef U32 OS_RESULT;

/* Return codes */
#define OS_R_TMO        0x01
#define OS_R_EVT        0x02
#define OS_R_SEM        0x03
#define OS_R_MBX        0x04
#define OS_R_MUT        0x05

#define OS_R_OK         0x00
#define OS_R_NOK        0xff

#define OS_TCB_SIZE     48
#define OS_TMR_SIZE     8

/* Error Codes */
#define OS_ERR_STK_OVF  1
#define OS_ERR_FIFO_OVF 2
#define OS_ERR_MBX_OVF  3

#if !(__TARGET_ARCH_6S_M || __TARGET_ARCH_7_M || __TARGET_ARCH_7E_M)

/*----------------------------------------------------------------------------
 *      Functions ARM
 *---------------------------------------------------------------------------*/


#else

/*----------------------------------------------------------------------------
 *      Functions Cortex-M
 *---------------------------------------------------------------------------*/


/* Definitions */
#define __SVC_0         __svc_indirect(0)

/* task sate user level macro added in ECE254 lab1 keil_proc */
#define INACTIVE        0
#define READY           1
#define RUNNING         2
#define WAIT_DLY        3
#define WAIT_ITV        4
#define WAIT_OR         5
#define WAIT_AND        6
#define WAIT_SEM        7
#define WAIT_MBX        8
#define WAIT_MUT        9
#define WAIT_MEM        10

/* Structures */
/* struct rl_task_info added in ECE254 lab1 keil_proc */
typedef struct rl_task_info {
  U8     state;                   /* Task state                              */
  U8     prio;                    /* Execution priority                      */
  U8     task_id;                 /* Task ID value for optimized TCB access  */
  U8     stack_usage;             /* Stack usage percent value. eg.=58 if 58%*/
  void   (*ptask)();              /* Task entry address                      */ 
} RL_TASK_INFO;

/* Task Management */

/* ECE254 Comment: added for ECE254 lab2 Proc Management Assignment  */
extern int rt_tsk_count_get (void); 

/* ECE254 Comment: added for ECE254 lab3 Proc Management Assignment   */
extern OS_RESULT rt_tsk_get (OS_TID task_id, RL_TASK_INFO *p_task_info); 
extern void     *rt_alloc_box_s (void *mpool);
extern OS_RESULT rt_free_box_s  (void *mpool, void *ptr);

/* ECE254 Comment: added for ECE254 lab2 Proc Management Assignment  */
#define os_tsk_count_get()   _os_tsk_count_get((U32)rt_tsk_count_get)

/* ECE254 Comment: added for ECE254 lab3 Proc Management Assignment   */
#define os_tsk_get(task_id, p_task_info)   _os_tsk_get((U32)rt_tsk_get, task_id, p_task_info)
#define os_mem_alloc(mpool)                _os_mem_alloc((U32)rt_alloc_box_s, mpool)
#define os_mem_free(mpool, ptr)            _os_mem_free ((U32)rt_free_box_s, mpool, ptr)

/* ECE254 Comment: added for ECE254 lab2 Proc Management Assignment  */
extern int _os_tsk_count_get (U32 p) __SVC_0;

/* ECE254 Comment: added for ECE254 lab3 Proc Management Assignment   */
extern OS_RESULT _os_tsk_get (U32 p, OS_TID task_id, RL_TASK_INFO *p_task_info) __SVC_0;
extern void     *_os_mem_alloc (U32 p, void *mpool)                             __SVC_0;
extern int       _os_mem_free  (U32 p, void *mpool, void *ptr)                  __SVC_0;

#endif

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

#endif
 
