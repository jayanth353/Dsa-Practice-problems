/*
Given an array find the next greater element of ith element ,if no such element found on right side
search from starting of the  array.(If no such element print -1)(ex:In below example next greater element of
9 is 12.
input:						        a[5]={12,3,4,7,9}
							   	               | | | | |
output:		nxtGreaterElement[5]={-1,4,7,9,12}

Approach:
1)Use a stack to maintain the heights in increasing order,which helps to find next greater
element of each ith element."Traverse from reverse".
2)Inorder to consider elements like 9 in above example we can make another copy of same array and by
following step 1, we can get the answer(where n size becoms 2n).
3)We actually need not append copy of  array to make a another copy instead we can use % to get
corresponding value.

Explaination:https://youtu.be/Du881K7Jtk8
*/
#include<bits/stdc++.h>
using namespace std;

void nge(int a[], int n)
{
	int nxtGt[n];
	stack<int> s;
	for (int i = 2 * n - 1; i >= 0; --i)
	{
		while (!s.empty() && a[i % n] >= s.top()) s.pop(); //pops an element if current element is greater than s.top only if stack is not empty
		if (i < n)  nxtGt[i] = s.empty() ? -1 : s.top();
		s.push(a[i % n]);
	}
	for (int i : nxtGt) cout << i << " ";
}


int main()
{
	int a[5] = {12, 3, 4, 7, 9};
	nge(a, 5);
}
