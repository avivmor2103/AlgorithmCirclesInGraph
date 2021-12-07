#include "AlgorithmSystem.h"
#include <iostream>

using namespace std;
void AlgorithmSystem::chooseAlgorithm(int*& result,int algoType, int numVertex, Edges* array, int numEdges)
{
	int degree = (int)sqrt((double)numEdges);
	ListGraph* listG;
	createListGraph(listG,numVertex, array, numEdges);
	MatrixGraph* matrixG;
	createMatrixGraph(matrixG,numVertex, array, numEdges);
	switch (algoType)
	{
	case 1:
	{
		algo1(result,*listG, *matrixG, numVertex,degree, algoType);
		break;
	}
	case 2:
	{
		algo2(result,*matrixG, numVertex);
		break;
	}
	case 3:
	{
		algo3(result, *matrixG, *listG, numVertex,numEdges,degree, algoType,array);
		break;
	}
	case 4:
	{
		algo1(result, *listG, *matrixG, numVertex, degree, algoType);
		algo2(result, *matrixG, numVertex);
		algo3(result, *matrixG, *listG, numVertex, numEdges, degree, algoType, array);
		break;
	}
	default:
		break;
	}
	delete listG;
	delete matrixG;
}

void AlgorithmSystem::createMatrixGraph(MatrixGraph*& matrixG,int numVertex, Edges* array, int numEdges)
{
	matrixG = new MatrixGraph(numVertex);
	for (int i = 0; i < numEdges; i++)
	{
		matrixG->AddEdge(array[i].getSrc(), array[i].getDst());
	}
	//return matrixG;
}

void AlgorithmSystem::createListGraph(ListGraph*&listG,int numVertex, Edges* array, int numEdges)
{
	listG = new ListGraph(numVertex);
	for (int i = 0; i < numEdges; i++)
	{
		listG->AddEdge(array[i].getSrc(), array[i].getDst());
	}

	//return listG;
}
void AlgorithmSystem::algo3(int*& result, MatrixGraph& matrixG, ListGraph& listG, int numVertex,int numEdges,int degree,int AlgoType,Edges* edgesArray)
{
	int* NamesOfHighDegreeVertex = new int[2 * degree];
	int*HelperArray = new int[2 * degree];
	*HelperArray = { -1 };
	*NamesOfHighDegreeVertex = { -1 };
	algo1(result, listG, matrixG, numVertex, degree, AlgoType);
	int j = 0;
	if (result[0] == 0)
	{

		for (int i = 0;i < numVertex;i++)
		{
			if (matrixG.getDegreeArray()[i] > degree)
			{
				NamesOfHighDegreeVertex[j] = i;
				HelperArray[i] = j;
				j++;
				//check!
			}

		}

		MatrixGraph* matrixG2 = new MatrixGraph(j);

		for (int i = 0;i < numEdges;i++)
		{
			if (matrixG.getDegreeArray()[edgesArray[i].getSrc() - 1] > degree && matrixG.getDegreeArray()[edgesArray[i].getDst() - 1] > degree)
			{
				int x = HelperArray[matrixG.getDegreeArray()[edgesArray[i].getSrc()]];
				int y = HelperArray[matrixG.getDegreeArray()[edgesArray[i].getDst()]];
				matrixG2->AddEdge(x-1, y-1);//check!
			}
		}
		algo2(result, *matrixG2, j);
		if (result[0] != 0)
		{
			for (int i = 0;i < 3;i++)
			{
				result[i] = NamesOfHighDegreeVertex[result[i]];
			}
		}
        delete matrixG2;
	}
	
	delete[] NamesOfHighDegreeVertex;
	delete[] HelperArray;
}
void AlgorithmSystem::algo1(int*& result,ListGraph& listG, MatrixGraph& matrixG, int numVertex,int degree,int AlgoType)
{
	
	result[0] = 0;
	for (int i = 1; i <= numVertex; i++)
	{
		Node<Edge>* curr1 = listG.GetAdjList(i).getHead();

		while (curr1 != NULL)
		{
			Node<Edge>* curr2 = listG.GetAdjList(curr1->data.vertex).getHead();

			if (curr2 != NULL)
			{
				if ((matrixG.getDegreeArray()[curr2->data.vertex - 1] <= degree && AlgoType == 3) || AlgoType == 1)
				{
					while (curr2 != NULL)
					{
						if (matrixG.getMatrix()[curr2->data.vertex - 1][i - 1]) {
							
							result[0] = i;
							result[1] = curr1->data.vertex;
							result[2] = curr2->data.vertex;
							return;
						}
						curr2 = curr2->next;
					}
				}
			}
			curr1 = curr1->next;
		}
	}
	//return result;
}

void AlgorithmSystem::algo2(int*& result,MatrixGraph& matrixG, int numVertex)
{
	MatrixGraph* matrixG_2 = new MatrixGraph(numVertex);
	MatrixGraph* matrixG_3 = new MatrixGraph(numVertex);
	result[0] = 0;
	this->multiplyMatrix(*matrixG_2, matrixG, matrixG, numVertex);
	this->multiplyMatrix(*matrixG_3, matrixG, *matrixG_2, numVertex);

	findCircle(result,matrixG, *matrixG_2, *matrixG_3, numVertex);
	delete  matrixG_2;
	delete matrixG_3;
//	return resultArray;
}

void AlgorithmSystem::findCircle(int*& result,MatrixGraph& matrixG, MatrixGraph& matrixG_2, MatrixGraph& matrixG_3, int numVertex)
{
	bool isValid = false;
	result[0]=0;
	for (int i = 0; i < numVertex && !isValid; i++)
	{
		if (matrixG_3.getMatrix()[i][i] == 1)
		{
			isValid = true;
			result[0] = i + 1;
		}
	}

	if (isValid)
	{
		for (int i = 0; i < numVertex; i++)
		{
			if (matrixG_2.getMatrix()[result[0] - 1][i] > 0)
			{
				if (matrixG.getMatrix()[i][result[0] - 1])
				{
					for (int j = 0; i < numVertex; j++)
					{
						if (matrixG.IsAdjancent(result[0] - 1, j) && matrixG.IsAdjancent(j, i))
						{
							result[1] = j + 1;
							result[2] = i + 1;
							return ;
						}
					}
				}
			}
		}
	}

	//return result;
}

void AlgorithmSystem::multiplyMatrix(MatrixGraph& resultMat, MatrixGraph& matrix1, MatrixGraph& matrix2, int numVertex)
{
	//MatrixGraph* matrixG = new MatrixGraph(numVertex);
	// i is rows 
	//j is columns
	for (int i = 0; i < numVertex; ++i) {
		for (int j = 0; j < numVertex; ++j) {
			for (int k = 0; k < numVertex; ++k)
			{
				resultMat.getMatrix()[i][j] += matrix1.getMatrix()[i][k] * matrix2.getMatrix()[k][j];
			}
		}
	}
	/*for (int i = 0; i < numVertex; i++)
	{
		for (int j = 0; j < numVertex; j++)
		{
			cout << i << " " << j << "=";
			cout << resultMat.getMatrix()[i].GetArray()[j] << endl;
		}
	}*/
}







