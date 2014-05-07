# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/camera.cpp \
../src/controller.cpp \
../src/entity.cpp \
../src/entitymesh.cpp \
../src/game.cpp \
../src/main.cpp \
../src/movingentity.cpp \
../src/world.cpp \
../src/enemic.cpp \
../src/jugador.cpp \
../src/bullet.cpp \
../src/bulletManager.cpp

OBJS += \
./src/camera.o \
./src/controller.o \
./src/entity.o \
./src/entitymesh.o \
./src/game.o \
./src/main.o \
./src/movingentity.o \
./src/world.o \
./src/enemic.o \
./src/jugador.o \
./src/bullet.o \
./src/bulletManager.o

CPP_DEPS += \
./src/camera.d \
./src/controller.d \
./src/entity.d \
./src/entitymesh.d \
./src/game.d \
./src/main.d \
./src/movingentity.d \
./src/world.d \
./src/enemic.d \
./src/jugador.d \
./src/bullet.d \
./src/bulletManager.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


