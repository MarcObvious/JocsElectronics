CPP_SRCS += \
../src/coldet/box.cpp \
../src/coldet/box_bld.cpp \
../src/coldet/coldet.cpp \
../src/coldet/coldet_bld.cpp \
../src/coldet/math3d.cpp \
../src/coldet/mytritri.cpp \
../src/coldet/sysdep.cpp 

C_SRCS += \
../src/coldet/tritri.c 

OBJS += \
./src/coldet/box.o \
./src/coldet/box_bld.o \
./src/coldet/coldet.o \
./src/coldet/coldet_bld.o \
./src/coldet/math3d.o \
./src/coldet/mytritri.o \
./src/coldet/sysdep.o \
./src/coldet/tritri.o 

C_DEPS += \
./src/coldet/tritri.d 

CPP_DEPS += \
./src/coldet/box.d \
./src/coldet/box_bld.d \
./src/coldet/coldet.d \
./src/coldet/coldet_bld.d \
./src/coldet/math3d.d \
./src/coldet/mytritri.d \
./src/coldet/sysdep.d 


# Each subdirectory must supply rules for building sources it contributes
src/coldet/%.o: ../src/coldet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/coldet/%.o: ../src/coldet/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


