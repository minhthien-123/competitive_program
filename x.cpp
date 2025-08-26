#include <bits/stdc++.h>
#define task "x"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn], dp[maxn][3];

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	if (std::fopen(task".inp", "r"))
	{
		std::freopen(task".inp", "r", stdin);
		std::freopen(task".out", "w", stdout);
	}

	int n, x;
	std::cin >> n >> x;
	int ans = -1e18;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		dp[i][0] = std::max(a[i], dp[i - 1][0] + a[i]);
        dp[i][1] = std::max({a[i] * x, dp[i - 1][1] + a[i] * x, dp[i - 1][0] + a[i] * x});
        dp[i][2] = std::max({a[i], dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]});
        ans = std::max({ans, dp[i][0], dp[i][1], dp[i][2]});
	}
	if (ans < 0)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << ans;
	}

	return 0;
}
