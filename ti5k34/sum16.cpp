#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	long double n, x;
	std::cin >> n >> x;
	long double tmp = x;
	long double ans = 1983;
	for (int i = 1; i <= n; i++){
		if (i % 2 != 0)
			ans -= x / i;
		else
			ans += x / i;
		x *= tmp;
	}

	std::cout << std::setprecision(5) << std::fixed << ans;

	return 0;
}