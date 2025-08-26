#include <bits/stdc++.h>
#define task "npri"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;

bool isPrime[maxn];

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

bool solve(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int t;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	int q;
	std::cin >> q;
	sieve();

	if (q <= 1e2)
	{
		while (q--)
		{
			int n;
			std::cin >> n;
			int i = 0, j = 0;
			while (!solve(n + i))
			{
				i++;
			}

			while (!solve(n - j) && j < n)
			{
                j++;
            }

			if (i < j)
			{
				std::cout << n + i;
			}
			else if (j > i)
			{
				std::cout << n - j;
			}
			else
			{
				std::cout << std::min(n + i, n - j);
			}
			std::cout << "\n";
		}
	}
	else
	{
		while (q--)
		{
			int n;
			std::cin >> n;
			int i = 0, j = 0;
			while (!isPrime[n + i])
			{
				i++;
			}

			while (!isPrime[n - j] && j < n)
			{
				j++;
			}

			//std::cout << i << " " << j << "\n";

			if (i < j)
			{
				std::cout << n + i;
			}
			else if (j > i)
			{
				std::cout << n - j;
			}
			else
			{
				std::cout << std::min(n + i, n - j);
			}
			std::cout << "\n";
		}
	}

	return 0;
}