################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.c 

OBJS += \
./STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.o 

C_DEPS += \
./STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.o: ../STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/Seven_Segment" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/KEYPAD_DRIVER" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/LCD_DRIVER" -I"C:/Users/hassa/workspace/EmbeddedC2/Unit7_lesson3_section/STMF103C6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STMF103C6_DRIVERS/stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

