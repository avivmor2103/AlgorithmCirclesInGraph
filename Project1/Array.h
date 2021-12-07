#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Array {
private:
	int* array;
	int size;
public:

	Array() 
	{
		array = NULL;
		size = 0;
	};
	Array(int n);
	Array(const Array& obj);
	~Array() { delete[] array; };

	int* GetArray() { return this->array; }
	void SetArray(int n) { array[n] = 1; }
	int GetSize() { return this->size; }
	void setSize(int n) { this->size = n; }
};
#endif // !ARRAY_H