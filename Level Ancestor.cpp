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
int R = 0;
int getLen(int n)
{
	return (int)(log(n) / log(2)) + 1;
}
void setancestor(vector<vector<int>>& ancstr, vector<int>& depth, int* node, int len, int n)
{
	depth[R] = 0;
	for (int j = 1; j <= len; j++)
	{
		for (int i = 0; i < n; i++)
		{
			
			ancstr[node[i]][j] = ancstr[ancstr[node[i]][j - 1]][j - 1];
			if (ancstr[node[i]][j] == R && depth[node[i]] == -1)
			{
				depth[node[i]] = pow(2, j);
			}
			else if (ancstr[node[i]][j] == 0 && node[i] != R && depth[node[i]] == -1)
			{
				depth[node[i]] = pow(2, j - 1) + depth[ancstr[node[i]][j - 1]];
			}
		}
	}
}
void constructGraph(vector<vector<int>>& ancstr, int* node, vector<int>& depth, int* isNode, int c, int p, int i)
{
	node[i] = c;
	if (isNode[c] == 0)
	{
		isNode[c] = 1;
		ancstr[c][0] = p;
		if (R == p)
		{
			depth[c] = 1;
		}
	}
	return;
}
void removeNode(vector<vector<int>>& ancstr, int* isNode, int len, int x)
{
	if (isNode[x] == 0) cout << "node does not present in graph " << endl;
	else
	{
		isNode[x] = 0;
		for (int j = 0; j <= len; j++)
		{
			ancstr[x][j] = 0;
		}
	}
	return;
}
void addNode(vector<vector<int>>& ancstr, vector<int>& depth, int* isNode, int len,int x, int p)
{
	if (isNode[x] == 1)
	{
		cout << " Node is already present in array " << endl;
		return;
	}
	if (isNode[p] == 0)
	{
		cout << " ancestor not does not present in an array " << endl;
		return;
	}
	isNode[x] = 1;
	ancstr[x][0] = p;
	depth[x] = depth[p] + 1;
	int j = 0;
	while (ancstr[x][j] != 0)
	{
		ancstr[x][j + 1] = ancstr[ancstr[x][j]][j];
		j++;
	}
	while (j <= len)
	{
		ancstr[x][j] = 0;
		j++;
	}
	return;
}
void LA(vector<vector<int> >& ancstr, vector<int> depth, int* isNode, int x, int L)
{
	int j = 0;
	int temp = x;
	if (isNode[x] == 0)
	{
		cout << "Node is not present in graph " << endl;
		return;
	}
	int k = depth[x] - L;
	while (k > 0)
	{
		if (k & 1)
		{
			x = ancstr[x][j];
		}
		k = k >> 1;
		j++;
	}
	cout << L << "th level acestor of node " << temp << " is = " << x << endl;
	return;
}
int main()
{
	int n = 11;
	vector<vector<int>> ancestor(1000, vector<int>(10));
	vector<int> depth(1000);
	fill(depth.begin(), depth.end(), -1);
	int* node = new int[1000];
	int* isNode = new int[1000];
	memset(isNode, 0, 1000 * sizeof(int));
	int len = getLen(n);
	R = 2;
	constructGraph(ancestor, node, depth, isNode, 2, 0, 0);
	constructGraph(ancestor, node, depth, isNode, 5, 2, 1);
	constructGraph(ancestor, node, depth, isNode, 3, 5, 2);
	constructGraph(ancestor, node, depth, isNode, 4, 5, 3);
	constructGraph(ancestor, node, depth, isNode, 1, 5, 4);
	constructGraph(ancestor, node, depth, isNode, 7, 1, 5);
	constructGraph(ancestor, node, depth, isNode, 9, 1, 6);
	constructGraph(ancestor, node, depth, isNode, 10, 9, 7);
	constructGraph(ancestor, node, depth, isNode, 11, 10, 8);
	constructGraph(ancestor, node, depth, isNode, 6, 10, 9);
	constructGraph(ancestor, node, depth, isNode, 8, 10, 10);
	setancestor(ancestor, depth, node, len, n);
	LA(ancestor, depth, isNode, 8, 1);
	addNode(ancestor, depth, isNode, len, 12, 8);
	LA(ancestor, depth, isNode, 12, 2);
	removeNode(ancestor, isNode, len, 12);
	LA(ancestor, depth, isNode, 12, 1);
}
