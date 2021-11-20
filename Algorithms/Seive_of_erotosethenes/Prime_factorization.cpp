#include<bits/stdc++.h>
using namespace std;

void prime_factorization(int n)
{
	vector<int> p_factors;
	for (int i = 2; i <= sqrt(n); ++i) //refer prime.md file
	{

		while (n % i == 0)
		{
			p_factors.push_back(i);
			n /= i;
		}
	}

	if (n > 1) p_factors.push_back(n);//if n is prime number
	for (int f : p_factors)
		cout << f << " ";
}

int main()
{
	int n;
	cin >> n;// n is a number for which prime factorisation is calculated
	prime_factorization(n); //

}
