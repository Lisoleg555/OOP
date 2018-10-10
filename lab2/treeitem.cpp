#include "treeitem.h"
#include <iostream>

TTreeItem::TTreeItem(const Hexagon& hexagon)
{
	this->hexagon = hexagon;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree item: created" << std::endl;
}
TTreeItem::TTreeItem(const TTreeItem& orig)
{
	this->hexagon = orig.hexagon;
	this->left = orig.left;
	this->right = orig.right;
	std::cout << "Tree item: copied" << std::endl;
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
	std::cout << "Tree item = " << *this;
	if(this->right != nullptr)
	{
		this->right->Show();
	}
	return;
}

TTreeItem* TTreeItem::DelItem(Hexagon res)
{
	if(res.Square() < this->hexagon.Square())
	{
		this->left = this->left->DelItem(res);
		return this;
	}
	else if(res.Square() == this->hexagon.Square())
	{
		TTreeItem* saveRight = this->GetRight();
		return saveRight;
	}
	return this;
}

TTreeItem* TTreeItem::SetNext(Hexagon hex, int k)
{
	if(k == 1)
	{
		TTreeItem *newTreeItem = new TTreeItem(hex);
		return newTreeItem;
	}
	else if(this->hexagon.Square() > hex.Square())
	{
		if(this->left == nullptr)
			k = 1;
		this->left = this->left->SetNext(hex, k);
	}
	else if(this->hexagon.Square() < hex.Square())
	{
		if(this->right == nullptr)
			k = 1;
		this->right = this->right->SetNext(hex, k);
	}
	return this;
}

Hexagon TTreeItem::GetHexagone() const
{
	return this->hexagon;
}

TTreeItem* TTreeItem::GetLeft(TTreeItem* seed)
{
	TTreeItem *oldSeed;
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

TTreeItem* TTreeItem::GetRight()
{
	return this->right;
}

TTreeItem::~TTreeItem()
{
	std::cout << "Tree item: deleted" << std::endl;
	delete left;
	delete right;
}

std::ostream& operator<<(std::ostream& os, const TTreeItem& obj)
{
	os << "Tree's hexagon: "<< std::endl << obj.hexagon;
	return os;
}
