#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			std::cin >> g[i][j];
			val = (g[i][j] == '*');
			pre[i][j] = val + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}

	while (q--){
		
	}

	return 0;
}