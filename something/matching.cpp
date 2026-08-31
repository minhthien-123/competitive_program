#include <bits/stdc++.h>
#define task "matching"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 21;
const int mod  = 1e9 + 7;
int dp[(1 << maxn) + 7], a[maxn][maxn];
int n;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> a[i][j];

	dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        int i = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) 
            if (a[i][j] && !(mask & (1 << j)))
                (dp[mask | (1 << j)] += dp[mask]) %= mod;
    }

    std::cout << dp[(1 << n) - 1];

	return 0;
}