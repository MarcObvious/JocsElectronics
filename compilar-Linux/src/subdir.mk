CPP_SRCS += \
../src/bullet.cpp \
../src/bulletManager.cpp \
../src/camera.cpp \
../src/controller.cpp \
../src/enemic.cpp \
../src/aliat.cpp \
../src/entity.cpp \
../src/entityboard.cpp \
../src/entitymesh.cpp \
../src/game.cpp \
../src/jugador.cpp \
../src/main.cpp \
../src/movingentity.cpp \
../src/nau.cpp \
../src/world.cpp 

OBJS += \
./src/bullet.o \
./src/bulletManager.o \
./src/camera.o \
./src/controller.o \
./src/enemic.o \
./src/aliat.o \
./src/entity.o \
./src/entityboard.o \
./src/entitymesh.o \
./src/game.o \
./src/jugador.o \
./src/main.o \
./src/movingentity.o \
./src/nau.o \
./src/world.o 

CPP_DEPS += \
./src/bullet.d \
./src/bulletManager.d \
./src/camera.d \
./src/controller.d \
./src/enemic.d \
./src/aliat.d \
./src/entity.d \
./src/entityboard.d \
./src/entitymesh.d \
./src/game.d \
./src/jugador.d \
./src/main.d \
./src/movingentity.d \
./src/nau.d \
./src/world.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


