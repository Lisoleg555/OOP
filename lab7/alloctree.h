#ifndef TALLOCTREE_H
#define TALLOCTREE_H
#include <memory>

class Alloctree
{
public:
	Alloctree();
	std::shared_ptr<Alloctree> add(char *_used_blocks, std::shared_ptr<Alloctree> seed);
	void killtree(char *pointer, size_t _count);
	char *push(size_t _count);
	virtual ~Alloctree();
private:
	char *_here;
	std::shared_ptr<Alloctree> _left;
	std::shared_ptr<Alloctree> _right;
};

#endif
