#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include <memory>

class TTreeItem
{
public:
	TTreeItem();
	TTreeItem(std::shared_ptr<Figure> figure);
	friend std::ostream& operator<<(std::ostream& os, const TTreeItem obj);
	bool CheckLeft();
	void Show();
	std::shared_ptr<Figure> GetPtrFigure();
	std::shared_ptr<TTreeItem> Set(std::shared_ptr<TTreeItem> seed, std::shared_ptr<Figure> figure, int k);
	std::shared_ptr<TTreeItem> DelItem(std::shared_ptr<TTreeItem> oldSeed, std::shared_ptr<TTreeItem> seed);
	std::shared_ptr<TTreeItem> GetLeft(std::shared_ptr<TTreeItem> seed);
	std::shared_ptr<Figure> GetFigure() const;
	virtual ~TTreeItem();
private:
	std::shared_ptr<Figure> figure;
	std::shared_ptr<TTreeItem> left;
	std::shared_ptr<TTreeItem> right;
};

#endif
