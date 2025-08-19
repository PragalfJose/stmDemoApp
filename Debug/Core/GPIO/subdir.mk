################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GPIO/GPIO.c 

OBJS += \
./Core/GPIO/GPIO.o 

C_DEPS += \
./Core/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GPIO/%.o Core/GPIO/%.su Core/GPIO/%.cyclo: ../Core/GPIO/%.c Core/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"F:/WorkSpace/stmDemoApp/Core/GPIO" -I"F:/WorkSpace/stmDemoApp/Core/Common" -I"F:/WorkSpace/stmDemoApp/Core/LED" -I"F:/WorkSpace/stmDemoApp/Core/UART" -I"F:/WorkSpace/stmDemoApp/Core/Console" -I"F:/WorkSpace/stmDemoApp/Core/System" -I"F:/WorkSpace/stmDemoApp/Core/OS" -I"F:/WorkSpace/stmDemoApp/Core/MQueue" -I"F:/WorkSpace/stmDemoApp/Core/ThreadFunction" -I"F:/WorkSpace/stmDemoApp/Core/TaskFunctions" -I"F:/WorkSpace/stmDemoApp/Core/Semaphore" -I"F:/WorkSpace/stmDemoApp/Core/Mutex" -I"F:/WorkSpace/stmDemoApp/Core/SwitchTask" -I"F:/WorkSpace/stmDemoApp/Core/BlinkTask" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GPIO

clean-Core-2f-GPIO:
	-$(RM) ./Core/GPIO/GPIO.cyclo ./Core/GPIO/GPIO.d ./Core/GPIO/GPIO.o ./Core/GPIO/GPIO.su

.PHONY: clean-Core-2f-GPIO

