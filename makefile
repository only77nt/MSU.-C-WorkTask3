all: create compile
CFLAGS = -g
create:	Figure.cpp Figure.h
		g++ $(CFLAGS) -c Figure.cpp Figure.h
compile: main.cpp Figure.o
		 g++ $(CFLAGS) main.cpp Figure.o -o run.out
run: 
		./run.out
clean:
		rm Figure.o
		rm run.out
		rm Figure.h.gch
