/**
* @file: helloworld.c
* @brief: Two simple tasks running pseduo-parallelly
*/
#include <LPC17xx.h>
#include <RTL.h>
#include <stdio.h>
#include "uart_polling.h"
__task void task1()
{
	unsigned int i = 0;
	for(;; i++)
	{
		printf("Task1: %d\n", i);
		os_dly_wait(100);
	}
}
__task void task2()
{
	while(1)
	{
		printf("Task2: HelloWorld!\n");
		os_dly_wait(300);
	}
}
__task void init(void)
{
	os_tsk_create(task1, 1); // task1 at priority 1
	os_tsk_create(task2, 1); // task2 at priority 1
	os_tsk_delete_self(); // must delete itself before exiting
}
int main ()
{
	SystemInit();
	uart0_init();
	os_sys_init(init);
}

