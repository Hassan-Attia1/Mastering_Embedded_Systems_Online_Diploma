################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STMF103C6_DRIVERS/Seven_Segment/subdir.mk
-include STMF103C6_DRIVERS/LCD_DRIVER/subdir.mk
-include STMF103C6_DRIVERS/KEYPAD_DRIVER/subdir.mk
-include STMF103C6_DRIVERS/subdir.mk
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
Unit7_lesson3_section.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit7_lesson3_section.list \

OBJCOPY_HEX += \
Unit7_lesson3_section.hex \

OBJCOPY_BIN += \
Unit7_lesson3_section.bin \


# All Target
all: Unit7_lesson3_section.elf secondary-outputs

# Tool invocations
Unit7_lesson3_section.elf: $(OBJS) $(USER_OBJS) C:\Users\hassa\workspace\EmbeddedC2\Unit7_lesson3_section\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Unit7_lesson3_section.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\hassa\workspace\EmbeddedC2\Unit7_lesson3_section\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit7_lesson3_section.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit7_lesson3_section.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit7_lesson3_section.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit7_lesson3_section.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Unit7_lesson3_section.hex"
	@echo 'Finished building: $@'
	@echo ' '

Unit7_lesson3_section.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit7_lesson3_section.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
