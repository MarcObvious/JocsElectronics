OBJS=\
box.o\
box_bld.o\
cdmath3d.o\
coldet.o\
coldet_bld.o\
multiobject.o\
mytritri.o\
sysdep.o\
tritri.o

libcoldet.a: $(OBJS)
	ar cr libcoldet.a $(OBJS)
	
box.o: ../src/coldet/box.cpp
	g++ -c -DGCC -O2 ../src/coldet/box.cpp

box_bld.o: ../src/coldet/box_bld.cpp
	g++ -c -DGCC -O2 ../src/coldet/box_bld.cpp

cdmath3d.o: ../src/coldet/cdmath3d.cpp
	g++ -c -DGCC -O2 ../src/coldet/cdmath3d.cpp

coldet.o: ../src/coldet/coldet.cpp
	g++ -c -DGCC -O2 ../src/coldet/coldet.cpp

coldet_bld.o: ../src/coldet/coldet_bld.cpp
	g++ -c -DGCC -O2 ../src/coldet/coldet_bld.cpp

multiobject.o: ../src/coldet/multiobject.cpp
	g++ -c -DGCC -O2 ../src/coldet/multiobject.cpp

mytritri.o: ../src/coldet/mytritri.cpp
	g++ -c -DGCC -O2 ../src/coldet/mytritri.cpp

sysdep.o: ../src/coldet/sysdep.cpp
	g++ -c -DGCC -O2 ../src/coldet/sysdep.cpp

tritri.o: ../src/coldet/tritri.c
	gcc -c -DGCC -O2 ../src/coldet/tritri.c
