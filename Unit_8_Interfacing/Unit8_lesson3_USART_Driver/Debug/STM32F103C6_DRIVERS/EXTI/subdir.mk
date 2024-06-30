################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.c 

OBJS += \
./STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.o 

C_DEPS += \
./STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.o: ../STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/hassa/workspace/EmbeddedC2/.metadata/Unit8_lesson3_USART_Driver/STM32F103C6_DRIVERS" -I"C:/Users/hassa/workspace/EmbeddedC2/.metadata/Unit8_lesson3_USART_Driver/STM32F103C6_DRIVERS/USART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/EXTI/stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

