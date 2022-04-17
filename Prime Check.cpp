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
	int a;
	scanf("%d", &a);
	int b = ceil(sqrt(a));
	vector<int> prime;
	for (int i = 2; i * i <= b; i++)
	{
		prime.push_back(i);
	}
	for (int p = 2; p * p <= b; p++)
	{
		if (find(prime.begin(), prime.end(), p) != prime.end())
		{
			for (int i = p * p; i <= b; i += p) remove(prime.begin(), prime.end(), i);
		}
	}
	bool isPrime = true;
	for (int i = 0; i < prime.size(); i++)
	{
		if (a % prime[i] == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime == true)
	{
		cout << "Prime" << endl;
	}
	else
	{
		cout << "Not Prime" << endl;
	}
}
