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
void getZarr(string str, int Z[])
{
	int n = str.length();
	int L, R, k;
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		}
		else
		{
			k = i - L;
			if (Z[k] < R - i + 1)
				Z[i] = Z[k];
			else
			{
				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}
void search(string text, string pattern)
{
	string concat = pattern + "$" + text;
	int l = concat.length();
    int* Z = (int*)malloc(sizeof(int) * l);
	getZarr(concat, Z);
	for (int i = 0; i < l; ++i)
	{
		if (Z[i] == pattern.length())
			cout << "Pattern found at index "
			<< i - pattern.length() - 1 << endl;
	}
}
int main()
{
	string text = "TESTING WE ARE TESTING";
	string pattern = "TEST";
	search(text, pattern);
}
