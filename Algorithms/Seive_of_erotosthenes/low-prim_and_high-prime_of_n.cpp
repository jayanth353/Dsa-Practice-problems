#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<bool> p(N, true);
vector<int> lp(N, 0), hp(N, 0);

void lp_and_hp() //caluculates low prime and high prime for each number upto N(line 4)
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
	cout << "low_prime" << "\t" << "high_prime" << endl;

	for (int j = 2; j <= N; ++j)
	{

		cout << "\t" << lp[j] << "\t \t \t" << hp[j] << "\n";
	}
}

int main()
{

	lp_and_hp();
	
}
