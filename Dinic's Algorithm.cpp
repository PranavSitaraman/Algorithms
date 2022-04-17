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
#define V 6
struct edge
{
	int v;
	int flow;
	int C;
	int rev;
};
class graph
{
	int Ve;
	int* level;
	vector<edge>* adj;
public:
	graph(int Ve)
	{
		adj = new vector<edge>[Ve];
		this->Ve = Ve;
		level = new int[Ve];
	}
	void addEdge(int u, int v, int C)
	{
		edge a{ v, 0, C, adj[v].size() };
		edge b{ u, 0, 0, adj[u].size() };
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, int ptr[]);
	int DinicMaxflow(int s, int t);
};
bool graph::BFS(int s, int t)
{
	for (int i = 0; i < V; i++)
		level[i] = -1;
	level[s] = 0;
	list< int > q;
	q.push_back(s);
	vector<edge>::iterator i;
	while (!q.empty())
	{
		int u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			edge& e = *i;
			if (level[e.v] < 0 && e.flow < e.C)
			{
				level[e.v] = level[u] + 1;
				q.push_back(e.v);
			}
		}
	}
	return level[t] < 0 ? false : true;
}
int graph::sendFlow(int u, int flow, int t, int start[])
{
	if (u == t)
		return flow;
	for (; start[u] < adj[u].size(); start[u]++)
	{
		edge& e = adj[u][start[u]];
		if (level[e.v] == level[u] + 1 && e.flow < e.C)
		{
			int curr_flow = min(flow, e.C - e.flow);
			int temp_flow = sendFlow(e.v, curr_flow, t, start);
			if (temp_flow > 0)
			{
				e.flow += temp_flow;
				adj[e.v][e.rev].flow -= temp_flow;
				return temp_flow;
			}
		}
	}
	return 0;
}
int graph::DinicMaxflow(int s, int t)
{
	if (s == t)
		return -1;
	int total = 0;
	while (BFS(s, t) == true)
	{
		int* start = new int[V + 1]{ 0 };
		while (int flow = sendFlow(s, INT_MAX, t, start))
			total += flow;
	}
	return total;
}
int main()
{
	graph g(6);
	g.addEdge(0, 1, 16);
	g.addEdge(0, 2, 13);
	g.addEdge(1, 2, 10);
	g.addEdge(1, 3, 12);
	g.addEdge(2, 1, 4);
	g.addEdge(2, 4, 14);
	g.addEdge(3, 2, 9);
	g.addEdge(3, 5, 20);
	g.addEdge(4, 3, 7);
	g.addEdge(4, 5, 4);
	cout << "Maximum flow " << g.DinicMaxflow(0, 5);
}
