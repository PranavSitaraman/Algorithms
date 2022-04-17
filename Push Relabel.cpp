#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cstdlib>
#include<ctype.h>
#include<math.h>
#include<cmath>
#include<time.h>
#include<ctime>
#include<string.h>
#include<string>
#include<limits.h>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<complex>
using namespace std;
struct edgE
{
	int flow, capacity;
	int u, v;
	edgE(int flow, int capacity, int u, int v)
	{
		this->flow = flow;
		this->capacity = capacity;
		this->u = u;
		this->v = v;
	}
};
struct verteX
{
	int h, e_flow;
	verteX(int h, int e_flow)
	{
		this->h = h;
		this->e_flow = e_flow;
	}
};
class grapH
{
	int v;
	vector<verteX> ver;
	vector<edgE> edge;
	bool push(int u);
	void relabel(int u);
	void preflow(int s);
	void updateReverseEdgeFlow(int i, int flow);
public:
	grapH(int v);
	void addEdge(int u, int v, int w);
	int getMaxFlow(int s, int t);
};
grapH::grapH(int v)
{
	this->v = v;
	for (int i = 0; i < v; i++)
		ver.push_back(verteX(0, 0));
}
void grapH::addEdge(int u, int v, int capacity)
{
	edge.push_back(edgE(0, capacity, u, v));
}
void grapH::preflow(int s)
{
	ver[s].h = ver.size();
	for (int i = 0; i < edge.size(); i++)
	{
		if (edge[i].u == s)
		{
			edge[i].flow = edge[i].capacity;
			ver[edge[i].v].e_flow += edge[i].flow;
			edge.push_back(edgE(-edge[i].flow, 0, edge[i].v, s));
		}
	}
}
int overFlowVertex(vector<verteX>& ver)
{
	for (int i = 1; i < ver.size() - 1; i++)
		if (ver[i].e_flow > 0)
			return i;
	return -1;
}
void grapH::updateReverseEdgeFlow(int i, int flow)
{
	int u = edge[i].v, v = edge[i].u;
	for (int j = 0; j < edge.size(); j++)
	{
		if (edge[j].v == v && edge[j].u == u)
		{
			edge[j].flow -= flow;
			return;
		}
	}
	edgE e = edgE(0, flow, u, v);
	edge.push_back(e);
}
bool grapH::push(int u)
{
	for (int i = 0; i < edge.size(); i++)
	{
		if (edge[i].u == u)
		{
			if (edge[i].flow == edge[i].capacity)
				continue;
			if (ver[u].h > ver[edge[i].v].h)
			{
				int flow = min(edge[i].capacity - edge[i].flow,
					ver[u].e_flow);
				ver[u].e_flow -= flow;
				ver[edge[i].v].e_flow += flow;
				edge[i].flow += flow;
				updateReverseEdgeFlow(i, flow);
				return true;
			}
		}
	}
	return false;
}
void grapH::relabel(int u)
{
	int mh = INT_MAX;
	for (int i = 0; i < edge.size(); i++)
	{
		if (edge[i].u == u)
		{
			if (edge[i].flow == edge[i].capacity)
				continue;
			if (ver[edge[i].v].h < mh)
			{
				mh = ver[edge[i].v].h;
				ver[u].h = mh + 1;
			}
		}
	}
}
int grapH::getMaxFlow(int s, int t)
{
	preflow(s);
	while (overFlowVertex(ver) != -1)
	{
		int u = overFlowVertex(ver);
		if (!push(u))
			relabel(u);
	}
	return ver.back().e_flow;
}
int main()
{
	int v = 6;
	grapH g(v);
	g.addEdge(0, 1, 16);
	g.addEdge(0, 2, 13);
	g.addEdge(1, 2, 10);
	g.addEdge(2, 1, 4);
	g.addEdge(1, 3, 12);
	g.addEdge(2, 4, 14);
	g.addEdge(3, 2, 9);
	g.addEdge(3, 5, 20);
	g.addEdge(4, 3, 7);
	g.addEdge(4, 5, 4);
	int s = 0, t = 5;
	cout << "Maximum flow is " << g.getMaxFlow(s, t);
}
