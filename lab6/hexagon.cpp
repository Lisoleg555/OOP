#include <iostream>
#include <cmath>
#include "hexagon.h"

Hexagon::Hexagon() : Hexagon(0)
{
	std::cout << "Hexagon created: default" << std::endl;
}

Hexagon::Hexagon(size_t i) : side(i)
{
	std::cout << "Hexagon created: " << side <<  std::endl;
}

Hexagon::Hexagon(const Hexagon& orig)
{
	std::cout << "Hexagon copy created" << std::endl;
	side = orig.side;
}

void Hexagon::Print()
{
	std::cout << "Hexagone's side = " << side << std::endl;
}

double Hexagon::Square()
{
	return 3 * sqrt(3) / 2 * pow(side, 2);
}

Hexagon& Hexagon::operator=(const Hexagon& right)
{
	if (this == &right)
		return *this;
	std::cout << "Hexagon copied" << std::endl;
	side = right.side;
	return *this;
}

Hexagon::~Hexagon()
{
	std::cout << "Hexagon deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj)
{
	os << "side = " << obj.side << std::endl;
	return os;
}

