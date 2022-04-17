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
int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	int nodes[20][3] = { 0 };
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
	}
	int dist[20];
	for (int i = 0; i < 20; i++)
	{
		dist[i] = 10000;
	}
	int visited[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		visited[i] = 0;
	}
	int previous[20] = { -1 };
	for (int i = 0; i < 20; i++)
	{
		previous[i] = -1;
	}
	int start;
	int end;
	printf("Enter starting node: ");
	scanf("%d", &start);
	printf("Enter ending node: ");
	scanf("%d", &end);
	dist[start] = 0;
	bool empty = true;
	int v = 0;
	while (empty == true)
	{
		int largest = 1000000;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0 && dist[i] < largest)
			{
				largest = dist[i];
				v = i;
			}
		}
		visited[v] = 1;
		for (int i = 0; i < k; i++)
		{
			if (nodes[i][0] == v)
			{
				if (visited[nodes[i][1]] == 0)
				{
					if (nodes[i][2] < dist[nodes[i][1]])
					{
						dist[nodes[i][1]] = nodes[i][2];
						previous[nodes[i][1]] = v;
					}
				}
			}
		}
		empty = false;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				empty = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d: %d\n", i, dist[i]);
	}
}
