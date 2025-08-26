#include <bits/stdc++.h>
#define task "partition"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
int n, l, ans = 0, s = 0;

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::freopen(task ".inp", "r", stdin);
	std::freopen(task ".out", "w", stdout);

	std::cin >> l >> n;
	for (int i = 1, x; i <= n; i++)
	{
		std::cin >> x;
		heap.push(x);
		s += x;
	}

	if (l > s)
		heap.push(l - s);

	while (heap.size() > 1)
	{
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();

		ans += a + b;
		heap.push(a + b);
	}

	std::cout << ans;

	return 0;
}