################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.c 

OBJS += \
./STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.o 

C_DEPS += \
./STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.o: ../STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/MasteringEmbeddedSystems/CMSIS_V5" -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/MasteringEmbeddedSystems/STM32F103C_Drivers/MCAL_Drivers" -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/MasteringEmbeddedSystems/STM32F103C_Drivers/HAL_Drivers" -I"C:/Users/qamar/STM32CubeIDE/workspace_1.4.0/MasteringEmbeddedSystems/STM32F103C_Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C_Drivers/HAL_Drivers/I2C_EEPROM_SLAVE/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

