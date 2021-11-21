/*
Given an array find the next greater element of ith element.(If no such element print -1)
input:						       a[5]={5,3,4,7,9}
								               | | | | |
output:	nxtGreaterElement[5]={7,4,7,9,-1}

Approach:Use a stack to maintain the heights in increasing order,which helps to find next greater
		 element of each ith element."Traverse from reverse".

Explaination:https://youtu.be/Du881K7Jtk8
*/
#include<bits/stdc++.h>
using namespace std;

void nge(int a[], int n)
{
	int nxtGt[n];
	stack<int> s;
	for (int i = n - 1; i >= 0; --i)
	{
		while (!s.empty() && a[i] >= s.top()) s.pop(); //pops an element if current element is greater than s.top only if stack is not empty
		nxtGt[i] = s.empty() ? -1 : s.top();
		s.push(a[i]);
	}
	for (int i : nxtGt) cout << i << " ";
}


int main()
{
	int a[5] = {5, 3, 4, 7, 9};
	nge(a, 5);
}
