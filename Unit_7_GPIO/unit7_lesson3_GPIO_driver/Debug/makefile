################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
STM_32_F103_C6_Drivers.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM_32_F103_C6_Drivers.list \

OBJCOPY_HEX += \
STM_32_F103_C6_Drivers.hex \

OBJCOPY_BIN += \
STM_32_F103_C6_Drivers.bin \


# All Target
all: STM_32_F103_C6_Drivers.elf secondary-outputs

# Tool invocations
STM_32_F103_C6_Drivers.elf: $(OBJS) $(USER_OBJS) C:\Users\hassa\workspace\EmbeddedC2\STM_32_F103_C6_Drivers\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "STM_32_F103_C6_Drivers.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\hassa\workspace\EmbeddedC2\STM_32_F103_C6_Drivers\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM_32_F103_C6_Drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM_32_F103_C6_Drivers.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM_32_F103_C6_Drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

STM_32_F103_C6_Drivers.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM_32_F103_C6_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM_32_F103_C6_Drivers.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM_32_F103_C6_Drivers.bin"
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
