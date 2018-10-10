#include <cstdlib>
#include <iostream>
#include "hexagon.h"
#include "tree.h"
#include "treeitem.h"

int main(int argc, char** argv)
{
	int c, b, k;
	Hexagon u,h;
	std::cout << "How many hexagons you want to create: ";
	std::cin >> c;
	b = c;
	TTree tree;
	std::cout << "Enter hexagon's side: ";
	std::cin >> u;
	k = 1;
	while(c > 0)
	{
		tree.push(u, k);
		c--;
		if(c == 0)
			break;
		k = 0;
		std::cout << "Enter hexagon's side: ";
		std::cin >> u;
	}
	std::cout << std::endl << std::endl << tree;
	std::cout << std::endl << std::endl;
	while(b > 0)
	{
		h = tree.pop();
		std::cout << h;
		b--;
	}
	return 0;
}
