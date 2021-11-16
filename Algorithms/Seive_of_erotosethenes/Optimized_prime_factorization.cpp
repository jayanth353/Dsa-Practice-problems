/*
Any number can be expressed as the product of primes,for example 24 can be expressed as 2^3 * 3^1.
If we able to find low and high primes of n (2 and 3 for 24) then Prime factorization of a number can be caluculated in O(log n) of time.
Below program finds the prime factorization of n using low and high primes of a number.
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<bool> p(N, true);
vector<int> lp(N, 0), hp(N, 0);

void seive() //caluculates low prime and high prime for each number upto N()
{

	p[1] = false;
	p[0] = false;

	//seive algorithm
	for (int i = 2; i <= N; ++i)
	{

		if (p[i] == true)
		{
			lp[i] = i;
			hp[i] = i;
			for (int j = 2 * i; j <= N; j += i)
			{
				p[j] = false;
				hp[j] = i;
				if (lp[j] == 0) lp[j] = i;

			}
		}
	}
	// cout << "low_prime" << "\t" << "high_prime" << endl;

	// for (int j = 2; j <= n; ++j)
	// {

	// 	cout << "\t" << lp[j] << "\t \t \t" << hp[j] << "\n";
	// }
}

int main()
{
	int n;
	cin >> n;//n value should be less than N(line 4)
	seive();
	vector<int> Pfactorisation;
	while (n > 1)
	{
		int Pfactor = lp[n];
		while (n % Pfactor == 0)
		{
			Pfactorisation.push_back(Pfactor);
			n /= Pfactor;
		}
	}
	for (int p : Pfactorisation) cout << p << " ";
}
