################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UI/layouts.cpp \
../UI/ui.cpp \
../UI/widgets.cpp 

OBJS += \
./UI/layouts.o \
./UI/ui.o \
./UI/widgets.o 

CPP_DEPS += \
./UI/layouts.d \
./UI/ui.d \
./UI/widgets.d 


# Each subdirectory must supply rules for building sources it contributes
UI/%.o: ../UI/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


