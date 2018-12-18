#include <cstdlib>
#include <iostream>
#include <memory>
#include "figure.h"
#include "hexagon.h"
#include "triangle.h"
#include "octagon.h"
#include "tree.h"
#include "treeitem.h"
#include "allocation.h"

int main(int argc, char** argv)
{
	std::shared_ptr<TTree<Figure>> tree = std::shared_ptr<TTree<Figure>>(new TTree<Figure>);
	std::shared_ptr<Figure> f;
	int figure, size, count = 0, key = 1;
	std::cout << "What figure you want to create:" << std::endl;
	std::cout << "1) triangle" << std::endl << "2) hexagon" << std::endl << "3) octagon" << std::endl;
	std::cout << "Input number of figure" << std::endl << "Another number stops creating" << std::endl;
	std::cin >> figure;
	while(figure >= 1 && figure <= 3)
	{
		std::cout << "Input figure's size" << std::endl;
		std::cin >> size;
		if(figure == 1)
		{
			f = std::shared_ptr<Triangle>(new Triangle(size));
			tree->push(f, key);
		}
		else if(figure == 2)
		{
			f = std::shared_ptr<Hexagon>(new Hexagon(size));
			tree->push(f, key);
		}
		else if(figure == 3)
		{
			f = std::shared_ptr<Octagon>(new Octagon(size));
			tree->push(f, key);
		}
		count++;
		key = 0;
		std::cin >> figure;
	}
	std::cout << "\n\n" << *tree << std::endl;
	std::cout << "Хотите удолить что-то из конкретного контейнеро? Введите путь к контейнеру состоящий из l, r и 0 - конечноя ветко. e - конец удоления" << std::endl;
	char way[20];
	scanf("%s", way);
	while(way[0] != 'e')
	{
		tree->Del(way, 0);
		count--;
		scanf("%s", way);
	}
	std::cout << "\n\n" << *tree << std::endl;
	while(count > 0)
	{
		f = tree->pop();
		f->Print();
		count--;
	}
	return 0;
}

