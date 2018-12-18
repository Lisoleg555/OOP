#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

#include "treeitem.h"
#include "tree.h"

template<class F, class node> class TIterator 
{
public:
	TIterator(std::shared_ptr<TTreeItem<F>> seed) 
	{
		tree = seed;
	}
	std::shared_ptr<F> operator*() 
	{
		return tree->GetFigure();
	}
	std::shared_ptr<F> operator->() 
	{
		return tree->GetFigure();
	}
	TIterator<F, node>& operator++() 
	{
		
		if(tree->CheckRight() != false)
		{
			tree->Increase();
			tree = tree->GetRight();
			tree = tree->Min(tree);
		}
		else
		{
			tree = tree->GetParent();
		}
		return *this;
	}
	bool operator==(const TIterator<F, node> &inend) 
	{
		return this->tree == inend.tree;
	}
	bool operator!=(const TIterator<F, node> &inend) 
	{
		return this->tree != inend.tree;
	}
private:
	std::shared_ptr<TTreeItem<F>> tree;
};
#endif 
