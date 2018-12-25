#include <iostream>
#include <cmath>
#include "octagon.h"

Octagon::Octagon() : Octagon(0)
{
	std::cout << "Octagon created: default" << std::endl;
}

Octagon::Octagon(size_t i) : side(i)
{
	std::cout << "Octagon created: " << side << std::endl;
}

Octagon::Octagon(const Octagon& orig)
{
	std::cout << "Octagon copy created" << std::endl;
	side = orig.side;
}

void Octagon::Print()
{
	std::cout << "Octagon's side = " << side <<std::endl;
}

double Octagon::Square()
{
	return 2 * (1 + sqrt(2)) * pow(side, 2);
}

Octagon& Octagon::operator=(const Octagon& right)
{
	if(this == &right)
		return *this;
	std::cout << "Octagon copied" << std::endl;
	side = right.side;
	return *this;
}

Octagon::~Octagon()
{
	std::cout << "Octagon deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj)
{
	os << "side = " << obj.side;
	return os;
}
