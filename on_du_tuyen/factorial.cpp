#include <bits/stdc++.h>
#define task "factorial"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;
std::string s;
int a[10], adj[10][10];

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	//std::freopen(task ".inp", "r", stdin);
	//std::freopen(task ".out", "w", stdout);

	std::cin >> n;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int tmp = s[i] - '0';
		for (int j = 1; j <= tmp; j++)
		{
			a[j]++;
		}
	}

	// for (int k = 1; k <= 9; k++)
	// std::cout << a[k];
	// std::cout <<"\n";

	a[2] += a[4] * 2;
	a[2] += a[8] * 3;
	a[2] += a[6];
	a[3] += a[6];
	a[3] += a[9] * 2;
	a[4] = a[6] = a[8] = a[9] = 0;

	// for (int k = 1; k <= 9; k++)
	// std::cout << a[k];
	// std::cout <<"\n";

	for (int i = 9; i > 1; i--)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			std::cout << i;
			// std::cout << "\n";
			for (int k = 1; k < i; k++)
			{
				if (k == 4)
				{
					a[2] -= 2;
				}
				else if (k == 6)
				{
					a[2] -= 1;
					a[3] -= 1;
				}
				else if (k == 8)
					a[2] -= 3;
				else if (k == 9)
					a[3] -= 2;
				else
					a[k]--;
			}

			// for (int k = 1; k <= 9; k++)
			// std::cout << a[k] << " ";
			// std::cout << "\n";
		}
	}
	return 0;
}