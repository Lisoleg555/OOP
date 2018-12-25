#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Triangle : public Figure
{
public:
	Triangle();
	Triangle(size_t i);
	Triangle(const Triangle& orig);
	friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
	Triangle& operator=(const Triangle& right);
	void Print();
	double Square();
	virtual ~Triangle();
private:
	size_t side;
};

#endif
