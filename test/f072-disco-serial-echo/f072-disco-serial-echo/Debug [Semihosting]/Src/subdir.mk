################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/main.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c \
../Src/usart.c 

OBJS += \
./Src/gpio.o \
./Src/main.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o \
./Src/usart.o 

C_DEPS += \
./Src/gpio.d \
./Src/main.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F072xB -DUSE_FULL_LL_DRIVER -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/libsparse/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/CMSIS/Include" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


