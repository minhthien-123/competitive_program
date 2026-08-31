#include <bits/stdc++.h>
#define task "IronBarCutting"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;
ll s, ans, tmp;
ll a[200007];

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1; i <= n; i++){
		std::cin >> a[i];
		s += a[i];
		ans += a[i];
	}

	for (int i = 1; i <= n; i++){
		tmp += a[i];
		ans = std::min(ans, abs(tmp - (s - tmp)));
	}

	std::cout << ans;

	return 0;
}