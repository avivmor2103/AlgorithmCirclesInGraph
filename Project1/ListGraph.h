#pragma once
#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#include "List.h"

struct Edge {
	int vertex;
	bool used = false;

	friend ostream& operator<<(ostream& os, const Edge e) {
		cout << e.vertex;
		return os;
	}

	bool operator== (const int& v) {
		return vertex == v;
	}
	bool operator== (const Edge& e) {
		return vertex == e.vertex;
	}
	void operator= (const Edge& e) {
		this->vertex = e.vertex;
		this->used = e.used;
	}
	void operator= (const int& v)
	{
		this->vertex = v;
	}

};

class ListGraph {
private:
	List<Edge>* adjacencyList;
	int numOfVertex;
	int* degreeArray;

public:
	ListGraph() { numOfVertex = 0;adjacencyList = NULL;degreeArray = NULL; };
	ListGraph(int n);
	ListGraph(const ListGraph& obj);
	~ListGraph();
	void MakeEmptyGraph(int n);
	bool IsAdjancent(int u, int v);
	List<Edge>& GetAdjList(int u)const;
	void AddEdge(int u, int v);
	Edge* makeNewEdge(int v);
	void PrintGraph();
	int IsEmpty();
	const int& getNumOfVertex() const { return numOfVertex; }
};

#endif // !LISTGRAPH_H