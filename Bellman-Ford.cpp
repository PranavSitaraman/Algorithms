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
	int previous[20];
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
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (dist[nodes[j][0]] + nodes[j][2] < dist[nodes[j][1]])
			{
				dist[nodes[j][1]] = dist[nodes[j][0]] + nodes[j][2];
				previous[nodes[j][1]] = nodes[j][0];
			}
		}
	}
	printf("%d ", dist[end]);
}
