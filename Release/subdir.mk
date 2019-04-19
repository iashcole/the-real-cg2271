################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../buzzer.cpp \
../cg2271.cpp \
../led.cpp \
../movement.cpp 

OBJS += \
./buzzer.o \
./cg2271.o \
./led.o \
./movement.o 

CPP_DEPS += \
./buzzer.d \
./cg2271.d \
./led.d \
./movement.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard" -I"C:\Users\teo_a\workspace\freeRTOS\Source\include" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


