#include <bits/stdc++.h>
#define task "RobotArms"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

bool cmp(ii x, ii y){
	if (x.se == y.se) return x.fi > y.fi;
	return x.se < y.se;
}

int n, ans = 0, tmp = LLONG_MIN;
ii a[maxn], b[maxn];

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].fi >> a[i].se;

	for (int i = 1; i <= n; i++)
		b[i] = {a[i].fi - a[i].se, a[i].fi + a[i].se};

	std::sort(b + 1, b + n + 1, cmp);

	for (int i = 1; i <= n; i++){
		int l = b[i].fi, r = b[i].se;
		if (l >= tmp){
			tmp = r;
			ans++;
		}
	}

	std::cout << ans;

	return 0;
}