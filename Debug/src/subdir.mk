################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CApp.cpp \
../src/SpaceInvader++.cpp 

OBJS += \
./src/CApp.o \
./src/SpaceInvader++.o 

CPP_DEPS += \
./src/CApp.d \
./src/SpaceInvader++.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eleve/eclipse-workspace/SpaceInvaders++/h" -I"/home/eleve/eclipse-workspace/SpaceInvaders++/CFigure" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


