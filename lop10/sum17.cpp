#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const ll mod = 	21111931;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	ll n, ans = 1;
	std::cin >> n;

	while (n >= 1){
		ans = (ans % mod) * (n % mod) % mod;
		n--;
	}

	std::cout << ans;

	return 0;
}