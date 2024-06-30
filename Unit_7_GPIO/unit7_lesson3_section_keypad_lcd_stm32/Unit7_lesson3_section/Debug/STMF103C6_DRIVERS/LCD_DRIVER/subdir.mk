################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STMF103C6_DRIVERS/LCD_DRIVER/LCD.c 

OBJS += \
./STMF103C6_DRIVERS/LCD_DRIVER/LCD.o 

C_DEPS += \
./STMF103C6_DRIVERS/LCD_DRIVER/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
STMF103C6_DRIVERS/LCD_DRIVER/LCD.o: ../STMF103C6_DRIVERS/LCD_DRIVER/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/Seven_Segment" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/KEYPAD_DRIVER" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/LCD_DRIVER" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STMF103C6_DRIVERS/LCD_DRIVER/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

