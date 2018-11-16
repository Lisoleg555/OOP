#include "tree.h"

template <class F> TTree<F>::TTree() : seed(nullptr){
}

template <class F> std::ostream& operator<<(std::ostream& os, const TTree<F>& tree)
{
	std::shared_ptr<TTreeItem<F>> item = tree.seed;
	if(item == nullptr)
	{
		return os;
	}
	item->Show();
	return os;
}

template <class F> void TTree<F>::push(std::shared_ptr<F> figure, int k)
{
	seed = seed->Set(nullptr, seed, figure, k);
}

template <class F> std::shared_ptr<TTreeItem<F>> TTree<F>::GetSeed() {
	return this->seed;
}

template <class F> std::shared_ptr<F> TTree<F>::pop()
{
	std::shared_ptr<F> result;
	std::shared_ptr<TTreeItem<F>> oldSeed;
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

template <class F> TIterator<F, TTreeItem<F>> TTree<F>::begin()
{
	return TIterator<F, TTreeItem<F>>(seed->Min(seed));
}

template <class F> TIterator<F, TTreeItem<F>> TTree<F>::end()
{
	return TIterator<F, TTreeItem<F>>(nullptr);
}

template <class F> TTree<F>::~TTree(){
}

#include "figure.h"
template class TTree<Figure>;
template std::ostream& operator<<(std::ostream& os, const TTree<Figure>& obj);
