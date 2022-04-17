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
int CrossProduct(vector<vector<int>>& A)
{
	int X1 = (A[1][0] - A[0][0]);
	int Y1 = (A[1][1] - A[0][1]);
	int X2 = (A[2][0] - A[0][0]);
	int Y2 = (A[2][1] - A[0][1]);
	return (X1 * Y2 - Y1 * X2);
}
bool isConvex(vector<vector<int>>& points)
{
	int N = points.size();
	int prev = 0;
	int curr = 0;
	for (int i = 0; i < N; i++)
	{
		vector<vector<int>> temp = { points[i], points[(i + 1) % N], points[(i + 2) % N] };
		curr = CrossProduct(temp);
		if (curr != 0)
		{
			if (curr * prev < 0)
			{
				return false;
			}
			else
			{
				prev = curr;
			}
		}
	}
	return true;
}
struct Point
{
	int x;
	int y;
};
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) return true;
	return false;
}
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}
bool isSimple(vector<vector<int>>& points)
{
	int N = points.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 2; j < N; j++)
		{
			if (i == 0 && j == N - 1)
			{
				continue;
			}
			if (doIntersect({ points[i % N][0], points[i % N][1] }, { points[(i + 1) % N][0], points[(i + 1) % N][1] }, { points[j % N][0], points[j % N][1] }, { points[(j + 1) % N][0], points[(j + 1) % N][1] }) == true)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int n;
	printf("Enter the number of sides of the polygon: ");
	scanf("%d", &n);
	getchar();
	vector<vector<int>> points;
	printf("Enter the coordinates of each vertex in order:\n");
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		points.push_back({ a, b });
	}
	if (isConvex(points))
	{
		cout << "Polygon is convex" << endl;
	}
	else
	{
		cout << "Polygon is not convex" << endl;
	}
	if (isSimple(points))
	{
		cout << "Polygon is simple" << endl;
	}
	else
	{
		cout << "Polygon is not simple" << endl;
	}
}
