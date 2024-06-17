################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Barrio.cpp \
../src/Coordenadas.cpp \
../src/Indice.cpp \
../src/LineaDeColectivos.cpp \
../src/Parada.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Barrio.d \
./src/Coordenadas.d \
./src/Indice.d \
./src/LineaDeColectivos.d \
./src/Parada.d \
./src/main.d 

OBJS += \
./src/Barrio.o \
./src/Coordenadas.o \
./src/Indice.o \
./src/LineaDeColectivos.o \
./src/Parada.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Barrio.d ./src/Barrio.o ./src/Coordenadas.d ./src/Coordenadas.o ./src/Indice.d ./src/Indice.o ./src/LineaDeColectivos.d ./src/LineaDeColectivos.o ./src/Parada.d ./src/Parada.o ./src/main.d ./src/main.o

.PHONY: clean-src

