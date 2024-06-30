################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C6_DRIVERs/GPIO/subdir.mk
-include STM32F103C6_DRIVERs/EXTI/subdir.mk
-include HAL/LCD_DRIVER/subdir.mk
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
Unit7_lesson4_new.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit7_lesson4_new.list \

OBJCOPY_BIN += \
Unit7_lesson4_new.bin \


# All Target
all: Unit7_lesson4_new.elf secondary-outputs

# Tool invocations
Unit7_lesson4_new.elf: $(OBJS) $(USER_OBJS) C:\Users\hassa\workspace\EmbeddedC2\.metadata\Unit7_lesson4_new\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Unit7_lesson4_new.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\hassa\workspace\EmbeddedC2\.metadata\Unit7_lesson4_new\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit7_lesson4_new.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit7_lesson4_new.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit7_lesson4_new.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit7_lesson4_new.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit7_lesson4_new.bin"
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
