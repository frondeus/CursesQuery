################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CursesQuery/screen.cpp \
../CursesQuery/window.cpp \
../CursesQuery/window_input.cpp \
../CursesQuery/window_output.cpp 

OBJS += \
./CursesQuery/screen.o \
./CursesQuery/window.o \
./CursesQuery/window_input.o \
./CursesQuery/window_output.o 

CPP_DEPS += \
./CursesQuery/screen.d \
./CursesQuery/window.d \
./CursesQuery/window_input.d \
./CursesQuery/window_output.d 


# Each subdirectory must supply rules for building sources it contributes
CursesQuery/%.o: ../CursesQuery/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


