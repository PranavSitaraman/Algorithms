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
	printf("Enter a square n: ");
	int n;
	scanf("%d", &n);
	getchar();
	printf("Enter n numbers separated by spaces: ");
	int* arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
	int* sum = (int*)calloc(int(sqrt(n)), sizeof(int));
	for (int i = 0; i < int(sqrt(n)); i++)
	{
		int tot = 0;
		for (int j = 0; j < int(sqrt(n)); j++)
		{
			tot += arr[int(sqrt(n)) * i + j];
		}
		sum[i] = tot;
	}
	int p, k;
	printf("Enter p and k to increment index p by k: ");
	scanf("%d %d", &p, &k);
	getchar();
	arr[p] += k;
	int a, b;
	printf("Enter a and b to sum the indexes between a and b inclusive: ");
	scanf("%d %d", &a, &b);
	getchar();
	int tot = 0;
	for (int i = a; i <= b; i++)
	{
		if (i % int(sqrt(n)) != 0)
		{
			tot += arr[i];
		}
		else
		{
			if (i + int(sqrt(n)) - 1 <= b)
			{
				tot += sum[int(i / int(sqrt(n)))];
				i += int(sqrt(n)) - 1;
			}
			else
			{
				tot += arr[i];
			}
		}
	}
	cout << tot;
}
