################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/USB_Device/ch32v30x_usbhs_device.c \
../User/USB_Device/usb_desc.c 

OBJS += \
./User/USB_Device/ch32v30x_usbhs_device.o \
./User/USB_Device/usb_desc.o 

C_DEPS += \
./User/USB_Device/ch32v30x_usbhs_device.d \
./User/USB_Device/usb_desc.d 


# Each subdirectory must supply rules for building sources it contributes
User/USB_Device/%.o: ../User/USB_Device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\Debug" -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\Core" -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\User" -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\User\UART" -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\User\USB_Device" -I"D:\RISC-V\mrs_workspace\USB_CDC_CH32V305FBP6\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


