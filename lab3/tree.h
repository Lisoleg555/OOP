#ifndef TTREE_H
#define TTREE_H

#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "treeitem.h"
#include <memory>

class TTree
{
public:
	TTree();
	void push(std::shared_ptr<Figure> figure, int k);
	bool empty();
	std::shared_ptr<Figure> pop();
	friend std::ostream& operator<<(std::ostream& os, const TTree& tree);
	virtual ~TTree();
private:
	std::shared_ptr<TTreeItem> seed;
};

#endif
