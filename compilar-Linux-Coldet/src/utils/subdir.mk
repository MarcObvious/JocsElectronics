# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/framework.cpp \
../src/utils/text.cpp \
../src/utils/utils.cpp 

OBJS += \
./src/utils/framework.o \
./src/utils/text.o \
./src/utils/utils.o 

CPP_DEPS += \
./src/utils/framework.d \
./src/utils/text.d \
./src/utils/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/%.o: ../src/utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


