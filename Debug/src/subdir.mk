################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CApp.cpp \
../src/SpaceInvarders++.cpp 

OBJS += \
./src/CApp.o \
./src/SpaceInvarders++.o 

CPP_DEPS += \
./src/CApp.d \
./src/SpaceInvarders++.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eleve/eclipse-workspace/SpaceInvarders++/h" -I"/home/eleve/eclipse-workspace/SpaceInvarders++/CContainer" -I"/home/eleve/eclipse-workspace/SpaceInvarders++/CFigure" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


