#include "tree.h"

template <class F>
TTree<F>::TTree()
{
	this->seed = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->count = 0;
	std::cout<< "Global tree: created" << std::endl;
}

template <class F>
std::ostream& operator<<(std::ostream& os, const TTree<F>& tree)
{
	if(tree.left != nullptr)
	{
		std::cout << *tree.left;
	}
	std::shared_ptr<TTreeItem<F>> item = tree.seed;
	if(item == nullptr)
	{
		return os;
	}
	item->Show();
	std::cout << std::endl;
	if(tree.right != nullptr)
	{
		std::cout << *tree.right;
	}
	return os;
}

template <class F>
void TTree<F>::Del(char* way, int size)
{
	if(way[size] == '0')
	{
		std::shared_ptr<TTreeItem<F>> oldSeed;
		oldSeed = seed->GetLeft(seed);
		seed = seed->DelItem(oldSeed, seed);
		oldSeed = nullptr;
		count--;
	}
	else if(way[size] == 'l' && left != nullptr)
	{
		left->Del(way, size + 1);
		if(left->GetCount() == 0)
		{
			left = nullptr;
		}
	}
	else if(way[size] == 'r' && right != nullptr)
	{
		right->Del(way, size + 1);
		if(right->GetCount() == 0)
		{
			right = nullptr;
		}
	}
	else
	{
		std::cout << "Чё-то не то в пути" << std::endl; 
	}
	return;
}

template <class F>
void TTree<F>::push(std::shared_ptr<F> figure, int k)
{
	if(this->count < 5)
	{
		seed = seed->Set(nullptr, seed, figure, k);
		count++;
	}
	else if(this->seed->GetFigure()->Square() < figure->Square())
	{
		if(right == nullptr)
		{
			k = 1;
			std::shared_ptr<TTree<F>> newtree = std::shared_ptr<TTree<Figure>>(new TTree<Figure>);
			newtree->push(figure, k);
			right = newtree;
		}
		else
		{
			right->push(figure, k);
		}
	}
	else
	{
		if(left == nullptr)
		{
			k = 1;
			std::shared_ptr<TTree<F>> newtree = std::shared_ptr<TTree<Figure>>(new TTree<Figure>);
			newtree->push(figure, k);
			left = newtree;
		}
		else
		{
			left->push(figure, k);
		}
	}
}

template <class F>
std::shared_ptr<F> TTree<F>::pop()
{
	int k = 0;
	std::shared_ptr<F> result;
	if(left != nullptr && left->GetCount() > 0)
	{
		result = left->pop();
	}
	else if(count > 0)
	{
		std::shared_ptr<TTreeItem<F>> oldSeed;
		if(seed != nullptr) 
		{
			if(seed->CheckLeft()) 
			{
				oldSeed = seed->GetLeft(seed);
				result = oldSeed->GetFigure();
				seed = seed->DelItem(oldSeed, seed);
				oldSeed = nullptr;
				count--;
				k = 1;
			}
			else
			{
				oldSeed = seed;
				result = seed->GetFigure();
				seed = seed->DelItem(oldSeed, seed);
				oldSeed = nullptr;
				count--;
				k = 1;
			}
		}
	}
	else
	{
		result = right->pop();
	}
	if(k == 0 && left != nullptr &&left->GetCount() == 0)
	{
		left = left->GetRight();
	}
	return result;
}

template <class F>
int TTree<F>::GetCount()
{
	return this->count;
}

template <class F>
std::shared_ptr<TTree<F>> TTree<F>::GetRight()
{
	return this->right;
}

template <class F>
TTree<F>::~TTree(){
}

#include "figure.h"
template class TTree<Figure>;
template std::ostream& operator<<(std::ostream& os, const TTree<Figure>& obj);
