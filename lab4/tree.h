#ifndef TTREE_H
#define TTREE_H

#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "treeitem.h"
#include <memory>

template <class F> class TTree
{
public:
	TTree();
	void push(std::shared_ptr<F> figure, int k);
	std::shared_ptr<F> pop();
	template <class B> friend std::ostream& operator<<(std::ostream& os, const TTree<B>& tree);
	virtual ~TTree();
private:
	std::shared_ptr<TTreeItem<F>> seed;
};

#endif
