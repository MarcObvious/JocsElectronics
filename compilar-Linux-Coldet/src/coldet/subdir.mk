CPP_SRCS += \
../src/coldet/box.cpp\
../src/coldet/box_bld.cpp\
../src/coldet/cdmath3d.cpp\
../src/coldet/coldet.cpp\
../src/coldet/coldet_bld.cpp\
../src/coldet/multiobject.cpp\
../src/coldet/mytritri.cpp\
../src/coldet/sysdep.cpp\
../src/coldet/tritri.c

OBJS += \
./src/coldet/box.o\
./src/coldet/box_bld.o\
./src/coldet/cdmath3d.o\
./src/coldet/coldet.o\
./src/coldet/coldet_bld.o\
./src/coldet/multiobject.o\
./src/coldet/mytritri.o\
./src/coldet/sysdep.o\
./src/coldet/tritri.o

CPP_DEPS += \
./src/coldet/box.d\
./src/coldet/box_bld.d\
./src/coldet/cdmath3d.d\
./src/coldet/coldet.d\
./src/coldet/coldet_bld.d\
./src/coldet/multiobject.d\
./src/coldet/mytritri.d\
./src/coldet/sysdep.d\
./src/coldet/tritri.d


src/coldet/libcoldet.a: $(OBJS)
	ar cr libcoldet.a $(OBJS)

src/coldet/%.o: ../src/coldet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	#g++ -c -DGCC -O2 ../src/coldet/box.cpp
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
src/coldet/tritri.o: ../src/coldet/tritri.c
	gcc -c -DGCC -O2 ../src/coldet/tritri.c -o ./src/coldet/tritri.o
	
#src/coldet/box.o: ../src/coldet/box.cpp
#	g++ -c -DGCC -O2 ../src/coldet/box.cpp

#src/coldet/box_bld.o: ../src/coldet/box_bld.cpp
#	g++ -c -DGCC -O2 ../src/coldet/box_bld.cpp

#src/coldet/cdmath3d.o: ../src/coldet/cdmath3d.cpp
#	g++ -c -DGCC -O2 ../src/coldet/cdmath3d.cpp

#src/coldet/coldet.o: ../src/coldet/coldet.cpp
#	g++ -c -DGCC -O2 ../src/coldet/coldet.cpp

#src/coldet/coldet_bld.o: ../src/coldet/coldet_bld.cpp
#	g++ -c -DGCC -O2 ../src/coldet/coldet_bld.cpp

#src/coldet/multiobject.o: ../src/coldet/multiobject.cpp
#	g++ -c -DGCC -O2 ../src/coldet/multiobject.cpp

#src/coldet/mytritri.o: ../src/coldet/mytritri.cpp
#	g++ -c -DGCC -O2 ../src/coldet/mytritri.cpp

#src/coldet/sysdep.o: ../src/coldet/sysdep.cpp
#	g++ -c -DGCC -O2 ../src/coldet/sysdep.cpp


