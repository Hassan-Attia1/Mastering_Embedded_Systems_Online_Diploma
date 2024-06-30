################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_DRIVER/LCD.c 

OBJS += \
./HAL/LCD_DRIVER/LCD.o 

C_DEPS += \
./HAL/LCD_DRIVER/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_DRIVER/LCD.o: ../HAL/LCD_DRIVER/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/hassa/workspace/EmbeddedC2/.metadata/Unit7_lesson4_new/HAL" -I"C:/Users/hassa/workspace/EmbeddedC2/.metadata/Unit7_lesson4_new/STM32F103C6_DRIVERs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD_DRIVER/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

