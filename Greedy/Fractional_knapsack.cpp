/*
Approach:
1.sort items in value/weight ratio
2.for i=1 to no
  2.1.if current weight is less than Weight of knapsack,add item to bag and update the current weight 
  2.2 else add fraction of next item in which resulting weight is equal remaining weight(weight of knapsack-current weight) and break the loop
*/

#include<bits/stdc++.h>
using namespace std;

struct item
{
	int v;
	int w;
};

bool comp(struct item a, struct item b)
{
	double r1 = double(a.v) / a.w;
	double r2 = double(b.v) / b.w;
	return r1 > r2;

}

double fractional_knapsack(struct item a[], int n, int w)
{
	sort(a, a + n, comp);

	int curr_weight = 0;
	double ans = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if (curr_weight + a[i].w <= w)
		{
			ans += a[i].v;
			curr_weight += a[i].w;
		}
		else
		{
			int r = w - curr_weight;
			ans += a[i].v * ((double)r / a[i].w);
			break;
		}
	}
	return ans;
}

int main()
{

	int n; //no.of items
	cin >> n;
	int w; //weight of knapsack
	cin >> w;
	struct item a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].v >> a[i].w;
	}
	cout << "Max value:" << fractional_knapsack(a, n, w);

}


/*
Input:

*/
