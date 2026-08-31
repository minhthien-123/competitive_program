#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ld long double
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const ll maxn = 1e6 + 7;

ld f[maxn];

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	for (int i = 1; i <= maxn; i++)
		f[i] = sqrt(i + f[i - 1]);

	ll t;
	std::cin >> t;
	while (t--){
		ll n;
		std::cin >> n;
		
		std::cout << std::setprecision(5) << std::fixed << f[n] << "\n";

		//std::cout << f[n];
	}

	return 0;
}