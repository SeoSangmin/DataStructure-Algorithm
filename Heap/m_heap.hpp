#ifndef M_HEAP_HPP
#define M_HEAP_HPP

#define HEAP_VOID_NUM 30 // should always greater than 0.

// Min-Heap
class Heap
{
private:
	int *heap;
	int max;
	int size;

	//void _heapify();
	void _expand_size();
	void _swap(int a, int b);

public:
	Heap(int *arr, int size);
	~Heap();

	void insert(int item);
	const int pop();

	const int& getSize();
	const int & operator[] (int idx) const;
};

#endif
