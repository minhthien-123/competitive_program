#include <bits/stdc++.h>
#define task "heap1"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	//std::freopen(task ".inp", "r", stdin);
	//std::freopen(task ".out", "w", stdout);

	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
		for (int i = 1, x; i <= n; i++)
		{
			std::cin >> x;
			heap.push(x);
		}

		int ans = 0;
		while (heap.size() > 1)
		{
			int a = heap.top();
			heap.pop();
			int b = heap.top();
			heap.pop();

			ans += a + b;

			std::cout << a << " " << b << "\n";

			heap.push(a + b);
		}

		std::cout << ans << "\n";
	}

	return 0;
}