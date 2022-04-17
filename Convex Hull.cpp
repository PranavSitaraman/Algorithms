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
#define MAXPOINTS 5
double zcrossprod(double x1, double y1, double x2, double y2)
{
	return (x1 * y2 - y1 * x2);
}
int cmpr(const void *p, const void *q)
{
	double* m = (double*)p;
	double* n = (double*)q;
	if (*(m + 2) > *(n + 2))
	{
		return 1;
	}
	else if (*(m + 2) < *(n + 2))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	double points[MAXPOINTS][3];
	printf("Enter the number of given points: ");
	int n;
	scanf("%d", &n);
	getchar();
	printf("Enter each point as a space separated pair on a new line:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &points[i][0], &points[i][1]);
		getchar();
	}
	double midx = 0, midy = 0;
	for (int i = 0; i < n; i++)
	{
		midx = midx + points[i][0] / n;
		midy = midy + points[i][1] / n;
	}
	for (int i = 0; i < n; i++)
	{
		points[i][2] = atan2(points[i][1] - midy, points[i][0] - midx);
	}
	qsort(points, n, sizeof(points[0]), cmpr);
	double hull[MAXPOINTS][2] = { 0 };
	hull[0][0] = points[0][0];
	hull[0][1] = points[0][1];
	hull[1][0] = points[1][0];
	hull[1][1] = points[1][1];
	int hullpos = 2;
	for (int i = 2; i < n - 1; i++)
	{
		while (hullpos > 1 && zcrossprod(hull[hullpos - 2][0] - hull[hullpos - 1][0], hull[hullpos - 2][1] - hull[hullpos - 1][1], hull[hullpos - 1][0] - points[i][0], hull[hullpos - 1][1] - points[i][1]) < 0)
		{
			hullpos = hullpos - 1;
		}
		hull[hullpos][0] = points[i][0];
		hull[hullpos][1] = points[i][1];
		hullpos++;
	}
	while (hullpos > 1 && zcrossprod(hull[hullpos - 2][0] - hull[hullpos - 1][0], hull[hullpos - 2][1] - hull[hullpos - 1][1], hull[hullpos - 1][0] - points[n - 1][0], hull[hullpos - 1][1] - points[n - 1][1]) < 0)
	{
		hullpos = hullpos - 1;
	}
	int hullstart = 0;
	bool flag = false;
	double px = points[n - 1][0];
	double py = points[n - 1][1];
	do
	{
		flag = false;
		if (hullpos - hullstart >= 2 && zcrossprod(px - hull[hullpos - 1][0], py - hull[hullpos - 1][1], hull[hullstart][0] - px, hull[hullstart][1] - py) < 0)
		{
			px = hull[hullpos - 1][0];
			py = hull[hullpos - 1][1];
			hullpos = hullpos - 1;
			flag = true;
		}
		if (hullpos - hullstart >= 2 && zcrossprod(hull[hullstart][0] - px, hull[hullstart][1] - py, hull[hullstart + 1][0] - hull[hullstart][0], hull[hullstart + 1][1] - hull[hullstart][1]) < 0)
		{
			hullstart = hullstart + 1;
			flag = true;
		}
	} while (flag);
	hull[hullpos][0] = px;
	hull[hullpos][1] = py;
	hullpos = hullpos + 1;
	cout << "Hull:" << endl;
	for (int i = 0; i < hullpos; i++)
	{
		cout << hull[i][0] << " " << hull[i][1] << endl;
	}
	double perimeter = 0;
	for (int i = 1; i < hullpos; i++)
	{
		perimeter += sqrt(pow(hull[i][0] - hull[i - 1][0], 2) + pow(hull[i][1] - hull[i - 1][1], 2));
	}
	perimeter += sqrt(pow(hull[hullpos - 1][0] - hull[0][0], 2) + pow(hull[hullpos - 1][1] - hull[0][1], 2));
	cout << "Perimeter: " << perimeter << endl;
}
