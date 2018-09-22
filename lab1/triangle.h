#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Triangle : public Figure
{
public:
	Triangle();
	Triangle(std::istream &is);
	Triangle(size_t i);
	Triangle(const Triangle& orig);
	double Square() override;
	void Print() override;
	virtual ~Triangle();
private:
	size_t side;
};
#endif
