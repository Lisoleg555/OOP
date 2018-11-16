#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Hexagon : public Figure
{ 
public:
	Hexagon();
	Hexagon(size_t i);
	Hexagon(const Hexagon& orig);
	void Print();
	double Square();
	friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
	Hexagon& operator=(const Hexagon& right);
	virtual ~Hexagon();
private:
	size_t side;
};

#endif
