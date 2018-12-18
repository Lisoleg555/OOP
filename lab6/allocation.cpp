#include "allocation.h"
#include <iostream>

Allocator::Allocator(size_t size, size_t count): _size(size), _count(count)
{
		_used_blocks = (char*)malloc(_size * _count);
		_free_count = count;
		for(size_t i = 0; i < _count; i++)
		{
		 	_tree = _tree->add(_used_blocks + i * _size, _tree);
		}
		std::cout << "allocation: memory init" << std::endl;
}

void *Allocator::allocate()
{
	char *result = nullptr;
	if(_free_count > 0)
	{
		result = _tree->push(_free_count);
		_free_count--;
	}
	else
	{
		std::cout << "allocation: No memory exception" << std::endl;
	}
	return result;
}

void Allocator::deallocate(void *pointer)
{
	_tree->killtree((char*)pointer, _free_count);
	std::cout << "allocation: Deallocate block " << std::endl;
	_free_count++;
}

Allocator::~Allocator()
{
	_tree = nullptr;
	if(_free_count < _count)
		std::cout << "allocation: memory leak?" << std::endl;
	else
		std::cout << "allocation: memory freed" << std::endl;
	delete _used_blocks;
}
