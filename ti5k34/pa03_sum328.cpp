#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ld long double
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	ll t;
	std::cin >> t;
	while (t--){
		ll n;
		std::cin >> n;
		ld ans = 1;

		for (int i = 1; i <= n; i++){
			ans += 1;
			ans = (ld)(1) / ans;
		}

		std::cout << std::setprecision(5) << std::fixed << ans << "\n";
	}

	return 0;
}