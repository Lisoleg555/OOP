#include <iostream>
#include <cmath>
#include "triangle.h"

Triangle::Triangle() : Triangle(0)
{
	std::cout << "Triangle created: default" << std::endl;
}

Triangle::Triangle(size_t i) : side(i)
{
	std::cout << "Triangle created: " << side << std::endl;
}

Triangle::Triangle(const Triangle& orig)
{
	std::cout << "Triangle copy created" << std::endl;
	side = orig.side;
}

void Triangle::Print()
{
	std::cout << "Triangle's side = " << side << std::endl;
}

double Triangle::Square()
{
	return sqrt(3) / 4 * pow(side, 2);
}

Triangle& Triangle::operator=(const Triangle& right)
{
	if(this == &right)
		return *this;
	std::cout << "Triangle copied" << std::endl;
	side = right.side;
	return *this;
}

Triangle::~Triangle()
{
	std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj)
{
	os << "side = " << obj.side;
	return os;
}
