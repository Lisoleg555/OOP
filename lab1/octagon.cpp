#include <iostream>
#include <cmath>
#include "octagon.h"

Octagon::Octagon() : Octagon(0){
}

Octagon::Octagon(size_t i) : side(i)
{
	std::cout << "Octagon created: " << side <<  std::endl;
}

Octagon::Octagon(std::istream &is)
{
	is >> side;
}

Octagon::Octagon(const Octagon& orig)
{
	std::cout << "Octagon copy created" << std::endl;
	side = orig.side;
}

double Octagon::Square()
{
	return 2 * (1 + sqrt(2)) * pow(side, 2);
}

void Octagon::Print()
{
	std::cout << "Octagon's side = " << side << std::endl;
}

Octagon::~Octagon()
{
	std::cout << "Octagon deleted" << std::endl;
}
