/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "core_cm3.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "string.h"
#include "../../MasteringEmbeddedSystems/RTOS/inc/Scheduler.h"

Task_strcuture Task1, Task2, Task3;
unsigned char task1_led,task2_led, task3_led ;

void task1()
{
	while(1)
	{
		task1_led^=1;
		//Task1 Code
	}
}


void task2()
{

	while(1)
	{
		task2_led^=1;
		//Task2 Code
	}
}

void task3()
{

	while(1)
	{
		task3_led^=1;
		//Task3 Code
	}
}
int main(void)
{
	Error_StateID error;

	HW_init();

	if (MyRTOS_init() != NoError)
		while (1);

	Task1.priority = 3;
	Task1.P_TaskEntry = task1;
	Task1.stack_sz=1024;
	strcpy(Task1.TaskName,"Task_1");

	strcpy(Task2.TaskName,"Task_2");
	Task2.priority = 3;
	Task2.P_TaskEntry = task2;
	Task2.stack_sz=1024;

	strcpy(Task3.TaskName,"Task_3");
	Task3.priority = 3;
	Task3.P_TaskEntry = task3;
	Task3.stack_sz=1024;

	error += MyRTOS_Create_Task(&Task1);
	error += MyRTOS_Create_Task(&Task2);
	error += MyRTOS_Create_Task(&Task3);

	MyRTOS_Activate_Task(&Task1);
	MyRTOS_Activate_Task(&Task2);
	MyRTOS_Activate_Task(&Task3);

	MyRTOS_StartOS();
	while (1)
	{

	}

}


