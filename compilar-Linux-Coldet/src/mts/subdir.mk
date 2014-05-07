################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/mts/MeshManager.cpp \
../src/mts/TextureManager.cpp \
../src/mts/mesh.cpp \
../src/mts/rendertotexture.cpp \
../src/mts/shader.cpp \
../src/mts/texture.cpp 

OBJS += \
./src/mts/MeshManager.o \
./src/mts/TextureManager.o \
./src/mts/mesh.o \
./src/mts/rendertotexture.o \
./src/mts/shader.o \
./src/mts/texture.o 

CPP_DEPS += \
./src/mts/MeshManager.d \
./src/mts/TextureManager.d \
./src/mts/mesh.d \
./src/mts/rendertotexture.d \
./src/mts/shader.d \
./src/mts/texture.d 


# Each subdirectory must supply rules for building sources it contributes
src/mts/%.o: ../src/mts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


