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
#include <future>
#include <mutex>
#include <thread>

std::mutex stop;

std::shared_ptr<Figure>* forsort = nullptr;

int SetMas(int count)
{
	int i;
	for(i = 0; i < count; i++)
	{
		forsort[i] = nullptr;
	}
	return 0;
}

int Sort(int maxCount, int minCount)
{
	int i, j;
	std::shared_ptr<Figure> swap;
	for(i = minCount; i < maxCount - 1; i++)
	{
		for(j = i + 1; j < maxCount; j++)
		{
			if(forsort[j]->Square() < forsort[i]->Square())
			{
				swap = forsort[j];
				forsort[j] = forsort[i];
				forsort[i] = swap;
			}
		}
	}
	stop.lock();
	return 0;
}

int main(int argc, char** argv)
{
	TTree<Figure> tree;
	std::shared_ptr<Figure> f;
	int figure, size, count = 0;
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
			tree.NewPush(f, count + 1);
		}
		else if(figure == 2)
		{
			f = std::shared_ptr<Hexagon>(new Hexagon(size));
			tree.NewPush(f, count + 1);
		}
		else if(figure == 3)
		{
			f = std::shared_ptr<Octagon>(new Octagon(size));
			tree.NewPush(f, count + 1);
		}
		count++;
		std::cin >> figure;
	}
	std::cout << "\n\n" << std::endl;
	std::cout << tree << std::endl;
	std::cout << "\n\n" << std::endl;
	int sort;
	std::cout << "Выберете сортировку:\n1 - стандартная однопоточная\n2 - многопоточная\nОстальные варианты отменяют сортировку" << std::endl;
	std::cin >> sort;
	int kount;
	if(sort == 1)
	{
		TTree<Figure> remake;
		f = tree.pop();
		remake.push(f, 1);
		for(kount = 1; kount < count; kount++)
		{
			f = tree.pop();
			remake.push(f, 0);
		}
		std::cout << "\n\n" << remake << "\n\n" << std::endl;
		while(count > 0)
		{
			f = remake.pop();
			f->Print();
			count--;
		}
	}
	else if (sort == 2)
	{
		std::cout << "Начата параллельная сортировка" << std::endl;
		forsort = (std::shared_ptr<Figure>*)malloc(count * sizeof(std::shared_ptr<Figure>));
		std::future<int> prepare = std::async(std::launch::async, SetMas, count);
		kount = prepare.get();
		for(kount = 0; kount < count; kount++)
		{
			f = tree.pop();
			forsort[kount] = f;
		}
		int size = count / 4;
		std::future<int> first = std::async(std::launch::async, Sort, size * 2, 0);
		std::future<int> second = std::async(std::launch::async, Sort, count, size * 2);
		kount = first.get();
		stop.unlock();
		kount = second.get();
		stop.unlock();
		kount = Sort(count, 0);
		stop.unlock();
		for(kount = 0; kount < count; kount++)
		{
			forsort[kount]->Print();
		}
		delete forsort;
	}
	else
	{
		while(count > 0)
		{
			f = tree.pop();
			f->Print();
			count--;
		}
	}
	return 0;
}

