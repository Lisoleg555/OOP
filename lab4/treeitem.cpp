#include "treeitem.h"
#include <iostream>

template <class F> TTreeItem<F>::TTreeItem()
{
	this->figure = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree item: created" << std::endl;
}

template <class F> TTreeItem<F>::TTreeItem(std::shared_ptr<F>& figure)
{
	this->figure = figure;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree item: created" << std::endl;
}

template <class F> bool TTreeItem<F>::CheckLeft()
{
	if (this->left == nullptr)
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

template <class F> std::shared_ptr<TTreeItem<F>> TTreeItem<F>::Set(std::shared_ptr<TTreeItem<F>> seed, std::shared_ptr<F> figure, int k)
{
	if(k == 1)
	{
		std::shared_ptr<TTreeItem<F>> newTreeItem = std::make_shared<TTreeItem<F>>(*(new TTreeItem(figure)));;
		return newTreeItem;
	}
	else if(seed->figure->Square() > figure->Square())
	{
		if(seed->left == nullptr)
			k = 1;
		seed->left = seed->left->Set(seed->left, figure, k);
	}
	else if(seed->figure->Square() <= figure->Square())
	{
		if(seed->right == nullptr)
			k = 1;
		seed->right = seed->right->Set(seed->right, figure, k);
	}
	return seed;
}

template <class F> std::shared_ptr<F> TTreeItem<F>::GetFigure() const
{
	return this->figure;
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
			seed = seed->right;
		}
		else
			seed = nullptr;
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

#include "figure.h"
template class TTreeItem<Figure>;
template <class Figure> std::ostream& operator<<(std::ostream& os, const TTreeItem<Figure>& obj);
