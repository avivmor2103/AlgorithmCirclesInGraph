#pragma once 
#include "List.h"
#include "Edges.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <math.h>
#include <iostream>

using namespace std;

class AlgorithmSystem
{
public:
	AlgorithmSystem() {};
	~AlgorithmSystem() {};

public:
	void chooseAlgorithm(int*& result, int algoType, int numVertex, Edges* array, int numeEdges);
	void createMatrixGraph(MatrixGraph*& matrixG, int numVertex, Edges* array, int numEdges);
	void createListGraph(ListGraph*& listG, int numVertex, Edges* array, int numEdges);
	void algo1(int*& result, ListGraph& listG, MatrixGraph& matrixG, int numVertex,int degree,int AlgoType);
	void algo2(int*& result , MatrixGraph& matrixG, int numVertex);
	void algo3(int*& result, MatrixGraph& matrixG, ListGraph& listG, int numVertex, int numEdges,int degree,int AlgoType,Edges*edgesArray);
	void findCircle(int*& result, MatrixGraph& matrixG, MatrixGraph& matrixG_2, MatrixGraph& matrixG_3, int numVertex);
	void multiplyMatrix(MatrixGraph& resultMat, MatrixGraph& matrix1, MatrixGraph& matrix2, int numVertex);
};