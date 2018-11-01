#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include <memory>

template <class F> class TTreeItem
{
public:
	TTreeItem();
	TTreeItem(std::shared_ptr<F>& figure);
	template <class B> friend std::ostream& operator<<(std::ostream& os, const TTreeItem<B>& obj);
	bool CheckLeft();
	void Show();
	std::shared_ptr<F> GetPtrFigure();
	std::shared_ptr<TTreeItem<F>> Set(std::shared_ptr<TTreeItem<F>> seed, std::shared_ptr<F> figure, int k);
	std::shared_ptr<TTreeItem<F>> DelItem(std::shared_ptr<TTreeItem<F>> oldSeed, std::shared_ptr<TTreeItem> seed);
	std::shared_ptr<TTreeItem<F>> GetLeft(std::shared_ptr<TTreeItem<F>> seed);
	std::shared_ptr<F> GetFigure() const;
	virtual ~TTreeItem();
private:
	std::shared_ptr<F> figure;
	std::shared_ptr<TTreeItem<F>> left;
	std::shared_ptr<TTreeItem<F>> right;
};

#endif
