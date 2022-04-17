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
bool flooded[20] = { false };
void flooditerate(int depth, int node, int n, int nodes[20][2])
{
	if (depth == n)
	{
		return;
	}
	for (int i = 0; i < 20; i++)
	{
		if (nodes[i][0] == node)
		{
			flooded[nodes[i][1]] = true;
			flooditerate(depth + 1, nodes[i][1], n, nodes);
		}
	}
	return;
}
int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	int k;
	printf("Enter number of node connections: ");
	scanf("%d", &k);
	int nodes[20][2];
	printf("List node connections line by line:\n");
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &nodes[i][0], &nodes[i][1]);
	}
	printf("Enter starting node: ");
	int start;
	scanf("%d", &start);
	flooded[start] = true;
	flooditerate(1, start, n, nodes);
	for (int i = 1; i <= n; i++)
	{
		if (flooded[i] == true)
		{
			printf("%d: true\n", i);
		}
		else
		{
			printf("%d: false\n", i);
		}
	}
}
