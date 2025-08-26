#include <bits/stdc++.h>
#define task "buy"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;

struct buy
{
	int num, val, dex;
};

struct cmp
{
	bool operator()(buy a, buy b)
	{
		return a.val > b.val;
	}
};

buy a[maxn];
int cnt[maxn];
int ans = 0;
int m, n;

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::freopen(task ".inp", "r", stdin);
	std::freopen(task ".out", "w", stdout);

	std::priority_queue<buy, std::vector<buy>, cmp> heap;

	std::cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i].num >> a[i].val;
		a[i].dex = i;
		heap.push(a[i]);
	}

	while (m > 0 && heap.size())
	{
		buy tmp = heap.top();
		heap.pop();

		int t = std::min(m, tmp.num);
		cnt[tmp.dex] = t;
		ans += tmp.val * t;
		m -= t;
	}

	std::cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		std::cout << cnt[i] << "\n";
	}

	return 0;
}