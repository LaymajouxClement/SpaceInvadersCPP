################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CFigure/CAlien.cpp \
../CFigure/CFigure.cpp \
../CFigure/CShip.cpp \
../CFigure/CShipRocket.cpp 

OBJS += \
./CFigure/CAlien.o \
./CFigure/CFigure.o \
./CFigure/CShip.o \
./CFigure/CShipRocket.o 

CPP_DEPS += \
./CFigure/CAlien.d \
./CFigure/CFigure.d \
./CFigure/CShip.d \
./CFigure/CShipRocket.d 


# Each subdirectory must supply rules for building sources it contributes
CFigure/%.o: ../CFigure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/eleve/eclipse-workspace/SpaceInvarders++/h" -I"/home/eleve/eclipse-workspace/SpaceInvarders++/CContainer" -I"/home/eleve/eclipse-workspace/SpaceInvarders++/CFigure" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


