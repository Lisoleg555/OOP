#ifndef TTREE_H
#define TTREE_H

#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "treeitem.h"
#include "iterator.h"
#include <memory>

template <class F> class TTree
{
public:
	TTree();
	void push(std::shared_ptr<F> figure, int k);
	std::shared_ptr<F> pop();
	std::shared_ptr<TTreeItem<F>> GetSeed();
	template <class B> friend std::ostream& operator<<(std::ostream& os, const TTree<B>& tree);
	virtual ~TTree();
	TIterator<F, TTreeItem<F>> begin();
	TIterator<F, TTreeItem<F>> end();
private:
	std::shared_ptr<TTreeItem<F>> seed;
};

#endif
