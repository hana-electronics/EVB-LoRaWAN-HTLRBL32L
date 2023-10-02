################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include HT_BLE_API/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/hal/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/cryptolib/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/RNGMGR/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/PKAMGR/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/NVMDB/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/Bluetooth_LE/src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/BLE_Application/Profiles/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/BLECNTR/Src/subdir.mk
-include HTLRBL32L-SDK/Middlewares/ST/AESMGR/Src/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/sx126x/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Mac/region/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Mac/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Crypto/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Core/subdir.mk
-include HTLRBL32L-SDK/LoRaWAN/Utils/subdir.mk
-include HTLRBL32L-SDK/Drivers/Peripherals_Drivers/src/subdir.mk
-include HTLRBL32L-SDK/Drivers/CMSIS/Device/ST/BlueNRG_LP/Source/subdir.mk
-include HTLRBL32L-SDK/Drivers/BSP/STEVAL-IDB011V1/Src/subdir.mk
-include HTLRBL32L-SDK/Drivers/BSP/Components/lsm6dsox_STdC/driver/subdir.mk
-include HTLRBL32L-SDK/Drivers/BSP/Components/lps22hh_STdC/driver/subdir.mk
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
PushButton_LoRaWAN_BLE.hex \

POST_BUILD_PRINT_SIZE += \
elf-size \


# All Target
all: PushButton_LoRaWAN_BLE.elf secondary-outputs

# Tool invocations
PushButton_LoRaWAN_BLE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -nostartfiles -nodefaultlibs -Wl,--gc-sections -Wl,-Map="PushButton_LoRaWAN_BLE.map" -T"../HTLRBL32L.ld" -L"C:\Projetos\EVB-LoRaWAN-HTLRBL32L\Firmware\HTLRBL32L-SDK\Libraries" -L"C:\Projetos\EVB-LoRaWAN-HTLRBL32L\Firmware\HTLRBL32L-SDK\Middlewares\ST\Bluetooth_LE\library" -L"C:\Projetos\EVB-LoRaWAN-HTLRBL32L\Firmware\HTLRBL32L-SDK\Middlewares\ST\cryptolib" --specs=nano.specs -o "PushButton_LoRaWAN_BLE.elf"  -Wl,--start-group @"objects.list" $(USER_OBJS) $(LIBS) -lm -lc  -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

PushButton_LoRaWAN_BLE.hex: PushButton_LoRaWAN_BLE.elf
	@echo 'Invoking: Generate binary'
	arm-none-eabi-objcopy -O ihex "PushButton_LoRaWAN_BLE.elf"  "PushButton_LoRaWAN_BLE.hex"
	@echo 'Finished building: $@'
	@echo ' '

elf-size: PushButton_LoRaWAN_BLE.elf
	@echo 'Invoking: Print Size'
	arm-none-eabi-size -B "PushButton_LoRaWAN_BLE.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(POST_BUILD_OBJCOPY)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(POST_BUILD_PRINT_SIZE)$(C_DEPS) PushButton_LoRaWAN_BLE.elf PushButton_LoRaWAN_BLE.bin *.map
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O binary PushButton_LoRaWAN_BLE.elf PushButton_LoRaWAN_BLE.bin
	-@echo ' '

secondary-outputs: $(POST_BUILD_OBJCOPY) $(POST_BUILD_PRINT_SIZE)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
