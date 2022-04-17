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
	printf("Enter the number you want to test for: ");
	int n;
	scanf("%d", &n);
	while (n % 2 == 0)
	{
		printf("%d ", 2);
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			printf("%d ", i);
			n = n / i;
		}
	}
	if (n > 2) printf("%d ", n);
}
