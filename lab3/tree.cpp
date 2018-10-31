#include "tree.h"

TTree::TTree() : seed(nullptr){
}

std::ostream& operator<<(std::ostream& os, const TTree& tree)
{
	std::shared_ptr<TTreeItem> item = tree.seed;
	if(item == nullptr)
	{
		return os;
	}
	item->Show();
	return os;
}

void TTree::push(std::shared_ptr<Figure> figure, int k)
{
	seed = seed->Set(seed, figure, k);
}

bool TTree::empty()
{
	return seed == nullptr;
}

std::shared_ptr<Figure> TTree::pop()
{
	std::shared_ptr<Figure> result;
	std::shared_ptr<TTreeItem> oldSeed;
	if(seed != nullptr) 
	{
		if(seed->CheckLeft()) 
		{
			oldSeed = seed->GetLeft(seed);
			result = oldSeed->GetFigure();
			seed = seed->DelItem(oldSeed, seed);
			oldSeed = nullptr;
		}
		else
		{
			oldSeed = seed;
			result = seed->GetFigure();
			seed = seed->DelItem(oldSeed, seed);
			oldSeed = nullptr;
		}
	}
	return result;
}

TTree::~TTree(){
}
