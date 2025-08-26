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

	ld n, x;
	std::cin >> n >> x;
	ld tmp = x, cmp = 1, ans = 0;

	for (int i = 1; i <= n; i++){
		//std::cout << tmp << " " << cmp << "\n";
		ans += tmp / cmp;
		tmp *= x;
		cmp *= (i + 1);
	}

	std::cout << std::setprecision(5) << std::fixed << ans;

	return 0;
}