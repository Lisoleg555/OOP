#include "tree.h"

TTree::TTree() : seed(nullptr){
}

TTree::TTree(const TTree& orig){
	seed = orig.seed;
}

std::ostream& operator<<(std::ostream& os, const TTree& tree)
{
	TTreeItem *item = tree.seed;
	if(item == nullptr)
	{
		return os;
	}
	item->Show();
	return os;
}

void TTree::push(Hexagon hexagon, int k)
{
	seed = seed->SetNext(hexagon, k);
}

bool TTree::empty()
{
	return seed == nullptr;
}

Hexagon TTree::pop()
{
	Hexagon result;
	TTreeItem *oldSeed;
	if(seed != nullptr)
	{
		if(seed->CheckLeft() == true)
		{
			oldSeed = seed->GetLeft(seed);
			result = oldSeed->GetHexagone();
		}
		else
		{
			oldSeed = seed;
			result = oldSeed->GetHexagone();
		}
	}
	seed = seed->DelItem(result);
	return result;
}

TTree::~TTree()
{
	delete seed;
}
