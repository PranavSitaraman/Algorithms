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
	int current, pointer, distance;
	int dist[20][20];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = 10000;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d %d", &current, &pointer, &distance);
		dist[current][pointer] = distance;
		dist[pointer][current] = distance;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int start;
	int end;
	printf("Enter starting node: ");
	scanf("%d", &start);
	printf("Enter ending node: ");
	scanf("%d", &end);
	printf("%d", dist[start][end]);
}
