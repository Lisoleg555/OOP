#ifndef TALLOCATION_H
#define TALLOCATION_H

#include <cstdlib>
#include <memory>
#include "alloctree.h"

class Allocator
{
public:
	Allocator(size_t size, size_t count);
	void *allocate();
	void deallocate(void *pointer);
	virtual ~Allocator();
private:
	size_t _size;
	size_t _count;
	char *_used_blocks;
	size_t _free_count;
	std::shared_ptr<Alloctree> _tree;
};
#endif
