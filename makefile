all: create compile
CFLAGS = -g
create:	Figure.cpp Figure.h Triangle.h Rectangle.h Sphere.h Parall.h Notch.h Corners.cpp Corners.h
		g++ $(CFLAGS) -c Figure.cpp Figure.h
		g++ $(CFLAGS) -c Triangle.cpp Triangle.h
		g++ $(CFLAGS) -c Rectangle.cpp Rectangle.h
		g++ $(CFLAGS) -c Sphere.cpp Sphere.h
		g++ $(CFLAGS) -c Parall.cpp  Parall.h
		g++ $(CFLAGS) -c Notch.cpp  Notch.h
		g++ $(CFLAGS) -c Corners.cpp Corners.h
compile: main.cpp Figure.o Triangle.o Rectangle.o Sphere.o Parall.o Notch.o Corners.o
		 g++ $(CFLAGS) main.cpp Figure.o Triangle.o Rectangle.o Sphere.o Parall.o Notch.o Corners.o -o run.out
run: 
		./run.out
clean:
		rm Figure.o
		rm run.out
		rm Figure.h.gch
		rm Sphere.o
		rm Parall.o
		rm Notch.o
		rm Triangle.o
		rm Rectangle.o
		rm Sphere.h.gch
		rm Parall.h.gch
		rm Notch.h.gch
		rm Triangle.h.gch
		rm Rectangle.h.gch
		rm Corners.o
		rm Corners.h.gch
		
