#include <cstdlib>
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

int main(int argc, char** argv)
{
	std::cout << "Enter Triangle's side" << std::endl;
	Figure *ptr1 = new Triangle(std::cin);
	ptr1->Print();
	std::cout << ptr1->Square() << std::endl;
	delete ptr1;
	std::cout << "Enter Octagon's side" << std::endl;
	Figure *ptr2 = new Octagon(std::cin);
	ptr2->Print();
	std::cout << ptr2->Square() << std::endl;
	delete ptr2;
	std::cout << "Enter Hexagon's side" << std::endl;
	Figure *ptr3 = new Hexagon(std::cin);
	ptr3->Print();
	std::cout << ptr3->Square() << std::endl;
	delete ptr3;
	return 0;
}
