################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/libsparse/Src/libsparse.c 

OBJS += \
./Drivers/libsparse/Src/libsparse.o 

C_DEPS += \
./Drivers/libsparse/Src/libsparse.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/libsparse/Src/%.o: ../Drivers/libsparse/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F072xB -DUSE_FULL_LL_DRIVER -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/libsparse/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Drivers/CMSIS/Include" -I"C:/Users/nickh/workspace/libsparse/test/f072-disco-serial-echo/f072-disco-serial-echo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


