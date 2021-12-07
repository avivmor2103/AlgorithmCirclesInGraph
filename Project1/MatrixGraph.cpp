#include "MatrixGraph.h"

MatrixGraph::MatrixGraph() 
{
	matrix = NULL;
	degreeArray = NULL;
	numOfVertex = 0;
}

MatrixGraph::MatrixGraph(int n)
{
	MakeEmptyGraph(n);
	// This array holds for each vertex his degee which is the sum of in and out edges
	
}

MatrixGraph::MatrixGraph(const MatrixGraph& obj)
{
	this->matrix = obj.matrix;
	this->numOfVertex = obj.numOfVertex;
	this->degreeArray = obj.degreeArray;

}

MatrixGraph :: ~MatrixGraph()
{
	for (int i = 0; i < numOfVertex; i++)
	{
		delete[] (matrix[i]);
	}
	delete[] matrix;
	delete degreeArray;
}


void MatrixGraph::MakeEmptyGraph(const int n)
{
	matrix = new int*[n];
	degreeArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		degreeArray[i] = 0;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			matrix[i][j] = 0;
		}
	}

	numOfVertex = n;
	
}

bool MatrixGraph::IsAdjancent(int u, int v) { return (matrix[u][v]); }


void MatrixGraph::AddEdge(int u, int v)
{
	matrix[u - 1][v - 1]=1;

	//We incrise the degree value of each vertex , one foe in-degree , and one for out-degree
	degreeArray[u - 1]++;
	degreeArray[v - 1]++;
}


int MatrixGraph::IsEmpty() { return numOfVertex == 0 ? true : false; }

