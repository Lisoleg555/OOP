#include "alloctree.h"
#include <iostream>

Alloctree::Alloctree()
{
	this->_here = nullptr;
	this->_left = nullptr;
	this->_right = nullptr;
}

std::shared_ptr<Alloctree> Alloctree::add(char *_used_blocks, std::shared_ptr<Alloctree> seed)
{
	
	if(seed == nullptr)
	{
		std::shared_ptr<Alloctree> tree(new Alloctree);
		tree->_here = _used_blocks;
		return tree;
	}
	else if(seed->_left == nullptr)
	{
		seed->_left = seed->_left->add(_used_blocks, seed->_left);
		return seed;
	}
	else
	{
		seed->_right = seed->_right->add(_used_blocks, seed->_right);
		return seed;
	}
}

void Alloctree::killtree(char *pointer, size_t _count)
{
	if(_count > 1)
	{
		this->_right->killtree(pointer, _count - 2);
	}
	else if(_count > 0)
	{
		this->_left->killtree(pointer, 0);
	}
	else
	{
		this->_here = pointer;
	}
}

char* Alloctree::push(size_t _count)
{
	if(_count == 1)
	{
		
		return this->_here;
	}
	else if(_count == 2)
	{
		_count--;
		return this->_left->push(_count);
	}
	else
	{
		_count--;
		_count--;
		return this->_right->push(_count);
	}
}

Alloctree::~Alloctree(){
}
