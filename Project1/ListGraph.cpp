#include "ListGraph.h"

ListGraph::ListGraph(int n)
{
	MakeEmptyGraph(n);
	this->degreeArray =new int[n];
	for (int i = 0;i < n;i++)
	{
		degreeArray[i] = 0;
	}
}

void ListGraph::MakeEmptyGraph(const int n)
{
	adjacencyList = new List<Edge>[n]();
	numOfVertex = n;
}
ListGraph::ListGraph(const ListGraph& obj)
{
	this->adjacencyList = obj.adjacencyList;
	this->degreeArray = obj.degreeArray;
	this->numOfVertex = obj.numOfVertex;
}


bool ListGraph::IsAdjancent(int u, int v) { return adjacencyList[u - 1].IsAdjancent(v); }

List<Edge>& ListGraph::GetAdjList(const int u)const { return adjacencyList[u - 1]; }

void ListGraph::AddEdge(int u, int v)
{
	adjacencyList[u - 1].addDataToEnd(v);
	degreeArray[u - 1]++;
	degreeArray[v - 1]++;
}

ListGraph :: ~ListGraph() {
	delete[] adjacencyList;
	delete degreeArray;
}

Edge* ListGraph::makeNewEdge(const int v)
{
	Edge* e = new Edge();
	e->vertex = v;
	return e;
}

void ListGraph::PrintGraph() {
	for (int i = 1; i <= numOfVertex; i++) {
		Node<Edge>* curr = adjacencyList[i - 1].getHead();
		if (curr) {
			while (curr) {
				cout << "(" << i << "," << curr->data << ") ";
				curr = curr->next;
			}
			cout << endl;
		}

	}
}

int ListGraph::IsEmpty() { return numOfVertex == 0 ? true : false; }
