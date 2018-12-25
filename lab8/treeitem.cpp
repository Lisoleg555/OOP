#include "treeitem.h"
#include <iostream>

template <class F> TTreeItem<F>::TTreeItem()
{
	this->figure = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->go = 0;
	std::cout << "Tree item: created" << std::endl;
}

template <class F> TTreeItem<F>::TTreeItem(std::shared_ptr<F>& figure)
{
	this->figure = figure;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->go = 0;
	std::cout << "Tree item: created" << std::endl;
}

template <class F> Allocator TTreeItem<F>::treeitem_allocator(sizeof(TTreeItem<F>), 127);

template <class F> bool TTreeItem<F>::CheckLeft()
{
	if (this->left == nullptr)
		return false;
	else
		return true;
}

template <class F> bool TTreeItem<F>::CheckRight()
{
	if (this->right == nullptr)
		return false;
	else
		return true;
}

template <class F> void TTreeItem<F>::Show()
{
	if(this->left != nullptr)
	{
		this->left->Show();
	}
	std::cout << "Tree item = ";
	this->figure->Print(); 
	if(this->right != nullptr)
	{
		this->right->Show();
	}
	return;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::Set(std::shared_ptr<TTreeItem<F>> papa , std::shared_ptr<TTreeItem<F>> seed, std::shared_ptr<F> figure, int k)
{
	if(k == 1)
	{
		std::shared_ptr<TTreeItem<F>> newTreeItem = std::make_shared<TTreeItem<F>>(*(new TTreeItem<F>(figure)));
		newTreeItem->parent = papa;
		return newTreeItem;
	}
	else if(seed->figure->Square() > figure->Square())
	{
		if(seed->left == nullptr)
			k = 1;
		papa = seed;
		seed->left = seed->left->Set(papa, seed->left, figure, k);
	}
	else if(seed->figure->Square() <= figure->Square())
	{
		if(seed->right == nullptr)
			k = 1;
		papa = seed;
		seed->right = seed->right->Set(papa, seed->right, figure, k);
	}
	return seed;
}

template <class F> std::shared_ptr<F> TTreeItem<F>::GetFigure() const
{
	return this->figure;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::GetRight()
{
	return this->right;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::GetParent()
{
	return this->parent;
}

template <class F> void TTreeItem<F>::Increase()
{
	++go;
	return;
}

template <class F> void TTreeItem<F>::NullPar()
{
	this->parent = nullptr;
	return;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::GetLeft(std::shared_ptr<TTreeItem<F>> seed)
{
	std::shared_ptr<TTreeItem<F>> oldSeed;
	if(seed->left != nullptr)
	{
		oldSeed = seed->GetLeft(seed->left);
	}
	else
	{
		oldSeed = seed;		
	}
	return oldSeed;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::DelItem(std::shared_ptr<TTreeItem<F>> oldSeed, std::shared_ptr<TTreeItem<F>> seed)
{
	if (seed != oldSeed)
	{
		seed->left = seed->DelItem(oldSeed, seed->left);
	}
	else
	{
		if(seed->right != nullptr)
		{
			treeitem_allocator.deallocate(seed.get());
			seed = seed->right;
		}
		else
		{
			treeitem_allocator.deallocate(seed.get());
			seed = nullptr;
		}
	}
	return seed;
}

template <class F> std::shared_ptr<F> TTreeItem<F>::GetPtrFigure() 
{
		return figure;
}

template <class F> TTreeItem<F>::~TTreeItem()
{
	std::cout << "Tree item: deleted" << std::endl;
}

template <class F> std::ostream& operator<<(std::ostream& os, TTreeItem<F>& obj)
{
	obj.GetPtrFigure()->Print();
	return os;
}

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::Min(std::shared_ptr<TTreeItem<F>> seed)
{
	std::shared_ptr<TTreeItem<F>> min;
	if(seed->left != nullptr)
	{
		min = Min(seed->left);
	}
	else
	{
		min = seed;
	}
	return min;
}
template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::Max(std::shared_ptr<TTreeItem<F>> seed)
{
	std::shared_ptr<TTreeItem<F>> max;
	if(seed->right != nullptr)
	{
		max = Max(seed->right);
	}
	else
	{
		max = seed;
	}
	return max;
}

template <class F> void * TTreeItem<F>::operator new(size_t size)
{
	return treeitem_allocator.allocate();
}

template <class F> void TTreeItem<F>::operator delete(void *p)
{
	treeitem_allocator.deallocate(p);
}

template <class F>
std::shared_ptr<TTreeItem<F>> TTreeItem<F>::NewSet(std::shared_ptr<TTreeItem<F>> papa, std::shared_ptr<TTreeItem<F>> seed, std::shared_ptr<F> figure, int k)
{
	if(k == 1)
	{
		std::shared_ptr<TTreeItem<F>> newTreeItem = std::make_shared<TTreeItem<F>>(*(new TTreeItem<F>(figure)));
		newTreeItem->parent = papa;
		return newTreeItem;
	}
	else if(go == 0)
	{
		go++;
		if(seed->left == nullptr)
		{
			seed->left = NewSet(seed, seed->left, figure, 1);
		}
		else
		{
			seed->left = NewSet(seed, seed->left, figure, k);
		}
	}
	else if(go == 1)
	{
		go--;
		if(seed->right == nullptr)
		{
			seed->right = NewSet(seed, seed->right, figure, 1);
		}
		else
		{
			seed->right = NewSet(seed, seed->right, figure, k);
		}
	}
	return seed;
}

#include "figure.h"
template class TTreeItem<Figure>;
template <class Figure> std::ostream& operator<<(std::ostream& os, const TTreeItem<Figure>& obj);
