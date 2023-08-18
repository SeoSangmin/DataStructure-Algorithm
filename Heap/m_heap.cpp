#include "m_heap.hpp"

Heap::Heap(int *arr, int size)
{
	if (size < 0)
		throw "size can't be negative.";

	if (arr == nullptr)
		throw "array is nullptr.";

	this->heap = new int[size + HEAP_VOID_NUM];
	if (this->heap == nullptr)
		throw "allocation of heap array has failed.";

	max = size + HEAP_VOID_NUM;
	this->size = 0;
	for (int i = 0; i < size; ++i)
		insert(arr[i]);
}

Heap::~Heap()
{
	if (this->heap)
		delete []heap;
}

void	Heap::insert(int item)
{
	if (size == max - 1)
		_expand_size();

	size++;
	heap[size] = item;

	int index = size;
	while (index > 1 && heap[index] < heap[index / 2])
	{
		_swap(index, index / 2);
		index = index / 2;
	}
}

// return and delete the root of heap
const int Heap::pop()
{
	int ret = 0;

	if (size < 1)
		return ret;

	ret = heap[1];
	heap[1] = heap[size];
	size--;
	int index = 1;
	while (index * 2 <= size)
	{
		int child;

		if (index * 2 == size)
			child = index * 2;
		else
		{
			if (heap[index * 2] < heap[index * 2 + 1])
				child = index * 2;
			else
				child = index * 2 + 1;
		}

		if (heap[index] <= heap[child])
			break;
		_swap(index, child);
		index = child;
	}

	return ret;
}

const int& Heap::getSize()
{
	return size;
}

void	Heap::_expand_size()
{
	// copy first
	this->max += HEAP_VOID_NUM;
	int *new_heap = new int[this->max];

	for (int i = 0; i < size + 1; ++i)
		new_heap[i] = (this->heap)[i];

	delete[] heap;
}

void	Heap::_swap(int a, int b)
{
	if (a < 0 || b < 0 || a > size || b > size)
		throw "swap: index range error";

	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}

const int & Heap::operator[](int index) const
{
	if (index < 0 || index > size)
		throw "index range error";
	return heap[index];
}
