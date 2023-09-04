################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include driver/subdir.mk
-include Middlewares/LoRaWAN/Utils/subdir.mk
-include Middlewares/LoRaWAN/SX126X/subdir.mk
-include Middlewares/LoRaWAN/Region/subdir.mk
-include Middlewares/LoRaWAN/MAC/subdir.mk
-include Middlewares/LoRaWAN/Crypto/subdir.mk
-include Middlewares/LoRaWAN/Core/subdir.mk
-include Middlewares/HAL/subdir.mk
-include Drivers/Peripheral_Drivers/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
POST_BUILD_OBJCOPY += \
Application1.hex \

POST_BUILD_PRINT_SIZE += \
elf-size \


# All Target
all: Application1.elf secondary-outputs

# Tool invocations
Application1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -nostartfiles -nodefaultlibs -Wl,--gc-sections -Wl,--print-gc-sections -Wl,-Map="Application1.map" -T"../HTLRBL32L.ld" -L../../Middlewares/ST/cryptolib -L../../Middlewares/ST/Bluetooth_LE/library -Wl,--cref -u _printf_float -o "Application1.elf"  -Wl,--start-group @"objects.list" $(USER_OBJS) $(LIBS) -lm -lc  -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

Application1.hex: Application1.elf
	@echo 'Invoking: Generate binary'
	arm-none-eabi-objcopy -O ihex "Application1.elf"  "Application1.hex"
	@echo 'Finished building: $@'
	@echo ' '

elf-size: Application1.elf
	@echo 'Invoking: Print Size'
	arm-none-eabi-size -B "Application1.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(POST_BUILD_OBJCOPY)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(POST_BUILD_PRINT_SIZE)$(C_DEPS) Application1.elf Application1.bin *.map
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O binary Application1.elf Application1.bin
	-@echo ' '

secondary-outputs: $(POST_BUILD_OBJCOPY) $(POST_BUILD_PRINT_SIZE)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
