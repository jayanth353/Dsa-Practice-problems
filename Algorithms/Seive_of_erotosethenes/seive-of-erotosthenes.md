# Seive of erotosthenes

```cpp

void seive(int n) //n is number upto which primes are calculated
{
	vector<bool> p(n + 1, true);
	p[1] = false;
	p[0] = false;

	//seive algorithm
	for (int i = 2; i <= sqrt(n); ++i) //(or) for (int i = 2; i*i <n; ++i) (or) for(int i = 2; i <=n/2; ++i)
	{
		if (p[i] == true)
		{
			for (int j = i * i; j <= n; j += i) //(or)for (int j = 2 * i; j < = n; j += i)
			{
				p[j] = false;
			}
		}

	}
	//Uncomment to print the primes
	/*
	for (int j = 0; j <= n; ++j)
	{
		if (p[j] == true)
			cout << j << " ";
	}
	*/
}
```


## Optimization 1
* If n is a composite number then there exist atleast two factors of n such that one number is less than or equal to sqrt(n) a and another is greater than or equal to sqrt(n)
 i.e x<=sqrt(n) and y>=sqrt(n)
  * Ex:Consider n=36 so factors of 36 will be,
    * 1x36
    * 2x18
    * 3x12 
    * 4x9
    * **6x6**
    * 9X4
    * 12x3
    * 18x2
    * 36x1
* If x\*y=36 then x can be any number in first half and y can be any number in second half which satisfies the above condition(i.e x<=sqrt(36) and y>=sqrt(36))
* Also y is exactly divisible by x,hence after marking the factors of x we need not mark factors of y as they are marked by x,<br>
  thus 
  ```c++
  for(int i=0;i<=n;i++)
  // can be written as 
 
  for(int i=0;i<=sqrt(n);++i)
  //or
  for(int i=0;i*i<=n;++i)
  ```
## Optimization 2
* To mark the factors of i<sup>th</sup> number we would start marking from 2<sup>nd</sup> multiple of of i ,so rather than marking from 2x of i we can iterate
  from ```i*i``` as the previous factors are marked by previous numbers.
 * Ex : Consider i as 5
        We can start from 25 because 10,15,20 are marked by 2,3,2 numbers respectively
    hence,
    ```cpp
    for(int j=2*i;j<=n;j+=i)
    // can be written as
    for(int j=i*i;j<=n;j+=i)
    ```
