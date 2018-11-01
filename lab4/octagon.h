#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Octagon : public Figure
{
public:
	Octagon();
	Octagon(size_t i);
	Octagon(const Octagon& orig);
	friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
	Octagon& operator=(const Octagon& right);
	void Print();
	double Square();
	virtual ~Octagon();
private:
	size_t side;
};

#endif
