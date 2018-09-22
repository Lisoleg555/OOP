#include <iostream>
#include <cmath>
#include "triangle.h"

Triangle::Triangle() : Triangle(0){
}

Triangle::Triangle(size_t i) : side(i)
{
	std::cout << "Triangle created: " << side << std::endl;
}

Triangle::Triangle(std::istream &is)
{
	is >> side;
}

Triangle::Triangle(const Triangle& orig)
{
	std::cout << "Triangle copy created" << std::endl;
	side = orig.side;
}

double Triangle::Square()
{
	return sqrt(3) / 4 * pow(side, 2);
}

void Triangle::Print()
{
	std::cout << "side = " << side << std::endl;
}

Triangle::~Triangle()
{
	std::cout << "Triangle deleted" << std::endl;
}
