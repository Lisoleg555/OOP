clean: main.exe
	rm *.o
main.exe: main.o tree.o hexagon.o treeitem.o
	g++ -Wall -g main.o tree.o hexagon.o treeitem.o -o main.exe
main.o: main.cpp treeitem.h hexagon.h tree.h
	g++ -c -g -Wall main.cpp
tree.o: tree.cpp tree.h
	g++ -c -g -Wall tree.cpp 
treeitem.o: treeitem.cpp treeitem.h
	g++ -c -g -Wall treeitem.cpp 
hexagon.o: hexagon.cpp hexagon.h
	g++ -c -g -Wall hexagon.cpp
