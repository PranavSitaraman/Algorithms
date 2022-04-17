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
int root(int v, int nodes[20])
{
	if (nodes[v] == -1)
	{
		return v;
	}
	int parent = root(nodes[v], nodes);
	return parent;
}
void findunion(int u, int v, int nodes[20])
{
	int uroot = root(u, nodes);
	int vroot = root(v, nodes);
	nodes[uroot] = vroot;
}
int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	int nodes[20][3] = { 0 };
	int previous[20] = { 0 };
	int k;
	printf("Enter number of node connections: ");
	scanf("%d", &k);
	printf("List node connections and their distances line by line:\n");
	int current;
	int pointer;
	int distance;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &current, &pointer, &distance);
		nodes[i][0] = current;
		nodes[i][1] = pointer;
		nodes[i][2] = distance;
		previous[current] = pointer;
	}
	for (int i = 1; i <= 20; i++)
	{
		if (previous[i] == 0)
		{
			previous[i] = -1;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (nodes[i][2] > nodes[j][2])
			{
				int temp0 = nodes[i][0];
				int temp1 = nodes[i][1];
				int temp2 = nodes[i][2];
				nodes[i][0] = nodes[j][0];
				nodes[i][1] = nodes[j][1];
				nodes[i][2] = nodes[j][2];
				nodes[j][0] = temp0;
				nodes[j][1] = temp1;
				nodes[j][2] = temp2;
			}
		}
	}
	int length = 0;
	int newtree[20] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		newtree[i] = -1;
	}
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		if (root(nodes[i][0], newtree) != root(nodes[i][1], newtree) || newtree[nodes[i][0]] == -1)
		{
			newtree[nodes[i][0]] = nodes[i][1];
			length += nodes[i][2];
		}
	}
	printf("Length: %d", length);
}
