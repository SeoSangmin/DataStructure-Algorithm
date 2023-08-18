#include <iostream>
#include "m_heap.hpp"

void l()
{
	system("leaks $PPID");
}

int main()
{
	//atexit(l);

	int size = 10;
	int arr[10] = {5, 2, 56, 1, 4, 67, 1, 9, 23, 34};

	Heap heap(arr, size);

	std::cout << "FOR MORE TESTS..\n";

	heap.insert(100);
	heap.insert(0);
	heap.insert(2312);
	
	while (heap.getSize())
		std::cout << heap.pop() << " ";
	std::cout << "\n";
	
	return 0;
}
