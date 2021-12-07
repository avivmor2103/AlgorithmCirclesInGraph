#pragma once
#include <iostream>

using namespace std;

class Edges
{
public:
	Edges() : m_dst(0), m_src(0)
	{
	};

	Edges(int src, int dst) {
		m_src = src;
		m_dst = dst;
	};
	~Edges() {};

	int getSrc() { return m_src; };
	int getDst() { return m_dst; };
	void setSrc(int src) { m_src = src; }
	void setDst(int dst) { m_dst = dst; }

private:
	int m_src;
	int m_dst;
};
