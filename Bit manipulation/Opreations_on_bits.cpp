//Prints a given binary number
void printBin(int a)
{
	for (int i = 10 ; i >= 0; --i)//prints upto 10 bits
	{
		cout << ( a >> i & 1);
	}
	cout << "\n";
}

//sets ith bit of a number
void set_i(int n, int i)
{
	printBin(n | (1 << i));
}

//unset ith bit of a number
void unset_i(int n, int i)
{
	/*
	ex:10110e
	to make 2 bit as unset(i.e 10010) we should do
	 10110
	&11011(is equal to ~(00100))
	 10010

	*/
	printBin(n & ~(1 << i));
}
//toogle ith bit
void toogle_i(int n , int i)
{
	printBin(n ^ (1 << i));
}

//counts set bits
int count_set(int n)
{
	int c = 0;
	while (n)
	{
		if (n & 1) c++;
		n = n >> 1;
	}

	/* (or)
	for (int i = 31; i >= 0; --i)
		if (n & (1 << i)) c++;
	*/

	/*( or ) using builtin function
	c = __builtin_popcount(n);
	*/
	return c;

}
