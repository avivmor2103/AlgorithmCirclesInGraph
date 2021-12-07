#include "Array.h"

Array::Array(int n)
{
	this->array = new int[n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = 0;
	}
	this->setSize(n);
}



Array::Array(const Array& obj)
{
	this->array = obj.array;
	this->size = obj.size;
}