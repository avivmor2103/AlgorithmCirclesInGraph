#pragma once
#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class MatrixGraph {
private:
	int** matrix;
	int numOfVertex;
	int* degreeArray;
public:
	MatrixGraph();
	MatrixGraph(int n);
	MatrixGraph(const MatrixGraph& obj);
	~MatrixGraph();
	void MakeEmptyGraph(int n);
	bool IsAdjancent(int u, int v);
	int** getMatrix() { return matrix; };
	int* getDegreeArray(){ return degreeArray; };
	void AddEdge(int u, int v);
	int IsEmpty();
	
	//MatrixGraph* multiplyMatrix(MatrixGraph matrix1, MatrixGraph matrix2, int numVertex);
	const int& getNumOfVertex() const { return numOfVertex; }
	void printGraph()
	{
		for (int i = 0;i < numOfVertex;i++)
		{
			for (int j = 0;j < numOfVertex;j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
#endif // !LISTGRAPH_H

