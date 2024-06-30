################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C6_DRIVERS/USART/subdir.mk
-include STM32F103C6_DRIVERS/RCC/subdir.mk
-include STM32F103C6_DRIVERS/GPIO/subdir.mk
-include STM32F103C6_DRIVERS/EXTI/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Unit8_lesson3_USART_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit8_lesson3_USART_Driver.list \

OBJCOPY_BIN += \
Unit8_lesson3_USART_Driver.bin \


# All Target
all: Unit8_lesson3_USART_Driver.elf secondary-outputs

# Tool invocations
Unit8_lesson3_USART_Driver.elf: $(OBJS) $(USER_OBJS) C:\Users\hassa\workspace\EmbeddedC2\.metadata\Unit8_lesson3_USART_Driver\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Unit8_lesson3_USART_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\hassa\workspace\EmbeddedC2\.metadata\Unit8_lesson3_USART_Driver\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit8_lesson3_USART_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit8_lesson3_USART_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit8_lesson3_USART_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit8_lesson3_USART_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit8_lesson3_USART_Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
