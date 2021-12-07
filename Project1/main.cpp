#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Edges.h"
#include "AlgorithmSystem.h"

bool checkValidFile(ifstream& inputFile, int* algoT, int* numV);
bool checkLine(char* line, int numVertex);
void pullDataFromFile(Edges* array, ifstream& file, int* numEdges);
int checkNumVertex(ifstream& file);
int checkAlgoType(ifstream& file);

#define MAX_SIZE 100

using namespace std;
int main(int argc, char** args)
{
	char* fileNameInpute = new char[MAX_SIZE];
	char* fileNameOutpute = new char[MAX_SIZE];
	bool isValidVertex = false;
	char* line = new char[MAX_SIZE];
	int algoType, numVertex, numEdges;
	int i = 0;
	int* resultArray = new int[9];
	Edges* edgesArray ;
	ifstream inputFile;
	ofstream outputFile;

	fileNameInpute = args[1];
	fileNameOutpute = args[2];
	inputFile.open(fileNameInpute);

	//check input validation
	if (!inputFile.is_open())
	{
		cout << "This file is not valide, wrong input";
		exit(1);
	}
	isValidVertex = checkValidFile(inputFile, &algoType, &numVertex);
	edgesArray = new Edges[numVertex* numVertex];

	if (isValidVertex)
	{
		inputFile.seekg(0);
		pullDataFromFile(edgesArray, inputFile, &numEdges);
		
	}
	else
	{
		cout << "File is wrong, number of Egds or numer of vertex are wrong";
		exit(1);
	}
	AlgorithmSystem algorithmSystem = AlgorithmSystem();
	algorithmSystem.chooseAlgorithm(resultArray, algoType, numVertex, edgesArray, numEdges);
	outputFile.open(fileNameOutpute);

	if (!outputFile.is_open())
	{
		cout << "File is wrong, number of Egds or numer of vertex are wrong";
		exit(1);
	}
	if (resultArray == NULL)
	{
		outputFile << "No circles in the graph." << endl;
	}
	while (resultArray[i] != NULL)
	{
		outputFile << resultArray[i];
		if (i != 2)
			outputFile << ',';
		i++;
	}

	//if (algoType == 4)
	//{
	//	outputFile.open(fileNameOutpute);
	//	for (int i = 1;i < 4; i++)
	//	{
	//		algorithmSystem.chooseAlgorithm(resultArray, i, numVertex, edgesArray, numEdges);

	//	//	outputFile.open(fileNameOutpute);
	//		if (!outputFile.is_open())
	//		{
	//			cout << "File is wrong, number of Egds or numer of vertex are wrong";
	//			exit(1);
	//		}
	//		for (int i = 0; i < 3; i++)
	//		{
	//			if (resultArray[0] != 0)
	//			{
	//				outputFile << resultArray[i];
	//				if (i != 2)
	//				outputFile << ',';
	//			}
	//			else
	//			{
	//				outputFile << "No circles in the graph." << endl;
	//				i = 3;
	//			}
	//		}
	//		outputFile << '\n';

	//		
	//	}
	//	inputFile.close();
	//	outputFile.close();
	//}
	//else
	//{
	//	algorithmSystem.chooseAlgorithm(resultArray, algoType, numVertex, edgesArray, numEdges);

	//	outputFile.open(fileNameOutpute);
	//	if (!outputFile.is_open())
	//	{
	//		cout << "File is wrong, number of Egds or numer of vertex are wrong";
	//		exit(1);
	//	}
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (resultArray[0] != 0)
	//		{
	//			outputFile << resultArray[i];
	//			if (i != 2)
	//				outputFile << ',';
	//		}
	//		else
	//		{
	//			outputFile << "No circles in the graph." << endl;
	//			i = 3;
	//		}
	//	}

	//	inputFile.close();
	//	outputFile.close();
	//}

	inputFile.close();
	outputFile.close();
	delete[] edgesArray;
	delete[] resultArray;

	
}

void pullDataFromFile(Edges* array, ifstream& file, int* numEdges)
{
	char* line = new char[MAX_SIZE];
	char* token = new char[MAX_SIZE];
	int i = 0, vertex;

	//Inorder to move the index from the beginning of the file the first line of the vertex;
	file.getline(line, MAX_SIZE);
	file.getline(line, MAX_SIZE);

	while (!file.eof())
	{
		file.getline(line, MAX_SIZE);
		token = strtok(line, " ");
		vertex = atoi(token);
		array[i].setSrc(vertex);
		token = strtok(NULL, " ");
		vertex = atoi(token);
		array[i].setDst(vertex);
		i++;
	}
	//update num of edges
	*numEdges = i;

}
int checkNumVertex(ifstream& file)
{
	char* line = new char[MAX_SIZE];
	int numVertex;
	bool isValid = false;
	file.getline(line, MAX_SIZE);
	numVertex = atoi(line);
	if (numVertex < 1 || numVertex > 4)
	{
		numVertex = 0;
	}
	return numVertex;
}
int checkAlgoType(ifstream& file)
{
	int algoType;
	bool isValid = false;
	char* line = new char[MAX_SIZE];
	file.getline(line, MAX_SIZE);
	algoType = atoi(line);
	if (algoType < 1 || algoType > 4)
	{
		algoType = 0;
	}
	return algoType;
}

bool checkValidFile(ifstream& inputFile, int* algoT, int* numV)
{
	bool isValid = true;
	char* line = new char[MAX_SIZE];
	int algoType, numVertex;

	if (!inputFile)
	{
		cout << "Wroge Input" << endl;
		exit(1);
	}

	algoType = checkAlgoType(inputFile);
	inputFile.getline(line, MAX_SIZE);
	numVertex = atoi(line);
	if (numVertex < 1)
		isValid = false;
	*numV = numVertex;


	while (!inputFile.eof() && isValid)
	{
		inputFile.getline(line, MAX_SIZE);
		if (!checkLine(line, numVertex))
		{
			isValid = false;
		}
	}
	*algoT = algoType;
	return isValid;
}

bool checkLine(char* line, int numVertex)
{
	char* vertex = new char[MAX_SIZE];
	int val1, val2;
	bool isValisVertex = true;

	vertex = strtok(line, " ");
	val1 = atoi(vertex);
	vertex = strtok(NULL, " ");
	val2 = atoi(vertex);

	if (val1 < 0 || val1 > numVertex || val2 < 0 || val2 > numVertex || val1 == val2)
	{
		isValisVertex = false;
	}

	return isValisVertex;
}