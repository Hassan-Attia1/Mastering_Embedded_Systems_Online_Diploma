################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stmdrivers/GPIO/stm32_F103C6_gpio_driver.c 

OBJS += \
./stmdrivers/GPIO/stm32_F103C6_gpio_driver.o 

C_DEPS += \
./stmdrivers/GPIO/stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stmdrivers/GPIO/stm32_F103C6_gpio_driver.o: ../stmdrivers/GPIO/stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/hassa/workspace/EmbeddedC2/unit7_lesson1_assignment/stmdrivers" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"stmdrivers/GPIO/stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

