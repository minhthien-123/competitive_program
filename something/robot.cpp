#include <bits/stdc++.h>
using namespace std;

bool ktnt(long long m)
{
	bool kt = true;
	if (m < 2)
	{
		kt = false;
	}
	else
	{
		for (int i = 2; i <= trunc(sqrt(m)); i++)
		{
			if (m % i == 0)
			{
				kt = false;
				break;
			}
		}
	}
	return kt;
}

int main()
{
	long long n, i;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
	}
	else if (ktnt(n))
	{
		cout << n - 1;
	}
	else if (trunc(sqrt(n)) * trunc(sqrt(n)) == n)
	{
		cout << n * 2 - 2;
	}
	else
	{
		i = trunc(sqrt(n));
		while (n % i != 0)
		{
			i--;
		}
		cout << i + trunc(n / i) - 2;
	}
}
