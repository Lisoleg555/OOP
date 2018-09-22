clean: main.exe
	rm *.o
main.exe: main.o octagon.o hexagon.o triangle.o
	g++ -Wall main.o octagon.o hexagon.o triangle.o -o main.exe
main.o: main.cpp octagon.h hexagon.h triangle.h
	g++ -c -Wall main.cpp
octagon.o: octagon.cpp octagon.h
	g++ -c -Wall octagon.cpp 
triangle.o: triangle.cpp triangle.h
	g++ -c -Wall triangle.cpp 
hexagon.o: hexagon.cpp hexagon.h
	g++ -c -Wall hexagon.cpp
