#include <bits/stdc++.h>
#define task "npri"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;

bool isPrime[maxn];

int q;

bool solve(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}


void sub1()
{
	while (q--)
	{
		int n;
		std::cin >> n;
		int i = 0;
		while (!solve(n + i) && !solve(n - i))
		{
			i++;
		}

		if (solve(n - i))
		{
			std::cout << n - i << "\n";
		}
		else
		{
			std::cout << n + i << "\n";
		}
	}
}

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= maxn; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}


void sub2()
{
	sieve();
	while (q--)
	{
		int n;
		std::cin >> n;
		int i = 0;
		while (!isPrime[n + i] && !isPrime[n - i])
		{
			i++;
		}


		if (isPrime[n - i])
		{
			std::cout << n - i << "\n";
		}
		else
		{
			std::cout << n + i << "\n";
		}
	}
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	if (std::fopen(task".inp", "r"))
	{
		std::freopen(task".inp", "r", stdin);
		std::freopen(task".out", "w", stdout);
	}

	std::cin >> q;

	if (q <= 1e2)
	{

	}
	else
	{

	}

	return 0;
}