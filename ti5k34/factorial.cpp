#include <bits/stdc++.h>
#define task "factorial"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 123456789;
int n, ans = 1;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	while (n > 0){
		ans *= n;
		ans %= mod;
		n--;
	}

	std::cout << ans;

	return 0;
}