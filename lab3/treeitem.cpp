#include "treeitem.h"
#include <iostream>

TTreeItem::TTreeItem()
{
	this->figure = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree item: created" << std::endl;
}

TTreeItem::TTreeItem(std::shared_ptr<Figure> figure)
{
	this->figure = figure;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree item: created" << std::endl;
}

bool TTreeItem::CheckLeft()
{
	if (this->left == nullptr)
		return false;
	else
		return true;
}

void TTreeItem::Show()
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

std::shared_ptr<TTreeItem> TTreeItem::Set(std::shared_ptr<TTreeItem> seed, std::shared_ptr<Figure> figure, int k)
{
	if(k == 1)
	{
		std::shared_ptr<TTreeItem> newTreeItem = std::make_shared<TTreeItem>(*(new TTreeItem(figure)));;
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

std::shared_ptr<Figure> TTreeItem::GetFigure() const
{
	return this->figure;
}

std::shared_ptr<TTreeItem> TTreeItem::GetLeft(std::shared_ptr<TTreeItem> seed)
{
	std::shared_ptr<TTreeItem> oldSeed;
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

std::shared_ptr<TTreeItem> TTreeItem::DelItem(std::shared_ptr<TTreeItem> oldSeed, std::shared_ptr<TTreeItem> seed)
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

std::shared_ptr<Figure> TTreeItem::GetPtrFigure() 
{
		return figure;
}

TTreeItem::~TTreeItem()
{
	std::cout << "Tree item: deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, TTreeItem& obj)
{
	obj.GetPtrFigure()->Print();
	return os;
}
