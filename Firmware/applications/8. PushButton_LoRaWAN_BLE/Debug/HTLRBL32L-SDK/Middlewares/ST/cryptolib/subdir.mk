################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/cryptolib/aes_hw.c 

OBJS += \
./HTLRBL32L-SDK/Middlewares/ST/cryptolib/aes_hw.o 

C_DEPS += \
./HTLRBL32L-SDK/Middlewares/ST/cryptolib/aes_hw.d 


# Each subdirectory must supply rules for building sources it contributes
HTLRBL32L-SDK/Middlewares/ST/cryptolib/aes_hw.o: C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/cryptolib/aes_hw.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -DOVER_THE_AIR_ACTIVATION=0 -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_HW_SMPS_10uH -DBLE_STACK_BASIC_CONF -DDEFAULT_REGION=1 -DCONFIG_HW_LS_RO -DUSE_FULL_LL_DRIVER -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/Bluetooth_LE/inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/applications/3. PushButton_LoRaWAN_BLE/HT_BLE_API/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/cryptolib/inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/cryptolib/inc/Common" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/hal/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/NVMDB/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/PKAMGR/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/RNGMGR/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/applications/3. PushButton_LoRaWAN_BLE/inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/AESMGR/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/BLE_Application/layers_inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/BLE_Application/Profiles/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/BLECNTR/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/Utils" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/hal/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Middlewares/ST/STSAFE_Axx0/CoreModules/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/sx126x" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Crypto" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Mac" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Mac/region" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/LoRaWAN/lorawan_specifics/Core" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/Peripherals_Drivers/inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/CMSIS/Include" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/BSP/STEVAL-IDB011V1/Inc" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/BSP/Components/lsm6dsox_STdC" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/BSP/Components/lsm6dsox_STdC/driver" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/BSP/Components/lps22hh_STdC/driver" -I"C:/Projetos/EVB-LoRaWAN-HTLRBL32L-master/Firmware/HTLRBL32L-SDK/Drivers/BSP/Common/Inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


