################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CFigure/CFigure.cpp \
../CFigure/CShip.cpp 

OBJS += \
./CFigure/CFigure.o \
./CFigure/CShip.o 

CPP_DEPS += \
./CFigure/CFigure.d \
./CFigure/CShip.d 


# Each subdirectory must supply rules for building sources it contributes
CFigure/%.o: ../CFigure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eleve/eclipse-workspace/SpaceInvaders++/h" -I"/home/eleve/eclipse-workspace/SpaceInvaders++/CFigure" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


