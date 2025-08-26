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

	int t;
	std::cin >> t;
	while (t--){
		int n, m;

		std::cin >> n >> m;

		if (n % (m + 1) == 0)
			std::cout << "B\n";
		else
			std::cout << "A\n";
	}

	return 0;
}