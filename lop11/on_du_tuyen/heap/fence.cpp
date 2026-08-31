#include <bits/stdc++.h>
#define task "fence"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, ans = 0;
std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1, x; i <= n; i++)
	{
		std::cin >> x;
		heap.push(x);
	}

	while (heap.size() > 1)
	{
		int x = heap.top();
		heap.pop();
		int y = heap.top();
		heap.pop();

		ans += x + y;
		heap.push(x + y);
	}

	std::cout << ans;

	return 0;
}