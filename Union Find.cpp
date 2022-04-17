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
int findroot(int v, int nodes[20])
{
	if (nodes[v] == -1)
	{
		return v;
	}
	int parent = findroot(nodes[v], nodes);
	return parent;
}
int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	int nodes[20] = { 0 };
	int k;
	printf("Enter number of node connections: ");
	scanf("%d", &k);
	printf("List node connections line by line:\n");
	int current;
	int pointer;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &current, &pointer);
		nodes[current] = pointer;
	}
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i] == 0)
		{
			nodes[i] = -1;
		}
	}
	int u, v, uroot, vroot;
	printf("Enter two nodes for union: ");
	scanf("%d %d", &u, &v);
	uroot = findroot(u, nodes);
	vroot = findroot(v, nodes);
	nodes[uroot] = vroot;
	for (int i = 1; i <= n; i++)
	{
		printf("%d: %d\n", i, nodes[i]);
	}
}
