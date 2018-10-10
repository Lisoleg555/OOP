#ifndef TTREE_H
#define TTREE_H

#include "hexagon.h"
#include "treeitem.h"

class TTree
{
public:
	TTree();
	TTree(const TTree& orig);
	void push(Hexagon hex, int k);
	bool empty();
	Hexagon pop();
	friend std::ostream& operator<<(std::ostream& os, const TTree& tree);
	virtual ~TTree();
private:
	TTreeItem *seed;
};

#endif
