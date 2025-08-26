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

	ll t;
	std::cin >> t;
	while (t--){
		ll n;
		std::cin >> n;
		long double ans = 0;
		for (int i = 1; i <= n; i++){
			ans = sqrt(i + sqrt(ans));
			std::cout << ans << " ";
		}

		std::cout << std::setprecision(5) << std::fixed << ans;
		std::cout << "\n";
	}
	return 0;
}