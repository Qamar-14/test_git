################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.c 

OBJS += \
./Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.o 

C_DEPS += \
./Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.o: ../Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/STM32_DRIVERS/Src/STM32F103C_Drivers/MCAL_Drivers" -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/STM32_DRIVERS/Src/STM32F103C_Drivers/HAL_Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32F103C_Drivers/MCAL_Drivers/EXTI_DRIVER/ext_interrupt.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

