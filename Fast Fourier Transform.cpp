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
typedef complex<double> cd;
const double PI = 3.1415926536;
unsigned int bitReverse(unsigned int x, int log2n)
{
	int n = 0;
	for (int i = 0; i < log2n; i++)
	{
		n <<= 1;
		n |= (x & 1);
		x >>= 1;
	}
	return n;
}
void fft(vector<cd>& a, vector<cd>& A, int log2n)
{
	int n = 4;
	for (unsigned int i = 0; i < n; ++i)
	{
		int rev = bitReverse(i, log2n);
		A[i] = a[rev];
	}
	const complex<double> J(0, 1);
	for (int s = 1; s <= log2n; ++s) {
		int m = 1 << s;
		int m2 = m >> 1;
		cd w(1, 0);
		cd wm = exp(J * (PI / m2));
		for (int j = 0; j < m2; ++j)
		{
			for (int k = j; k < n; k += m)
			{
				cd t = w * A[k + m2];
				cd u = A[k];
				A[k] = u + t;
				A[k + m2] = u - t;
			}
			w *= wm;
		}
	}
}
int main()
{
	vector<cd> a{ 1, 2, 3, 4 };
	vector<cd> A(4);
	fft(a, A, 2);
	for (int i = 0; i < 4; ++i) cout << A[i] << "\n";
}
