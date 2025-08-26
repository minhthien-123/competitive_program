#include <bits/stdc++.h>
#define task "bai4"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int a[1000005];
int mx, mn, ans, n;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++){
		if (i % 2 == 0){
			mn += a[i / 2];
			mx += a[n - i / 2 + 1];
		}

		ans += mx - mn;

		std::cout << ans << " ";
	}

	return 0;
}