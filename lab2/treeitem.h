#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "hexagon.h"

class TTreeItem
{
public:
	TTreeItem(const Hexagon& hexagon);
	TTreeItem(const TTreeItem& orig);
	friend std::ostream& operator<<(std::ostream& os, const TTreeItem& obj);
	bool CheckLeft();
	void Show();
	TTreeItem* DelItem(Hexagon res);
	TTreeItem* SetNext(Hexagon hex, int k);
	TTreeItem* GetLeft(TTreeItem* seed);
	TTreeItem* GetRight();
	Hexagon GetHexagone() const;
	virtual ~TTreeItem();
private:
	Hexagon hexagon;
	TTreeItem *left;
	TTreeItem *right;
};

#endif
