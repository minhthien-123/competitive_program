#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 2e5 + 5;

ll  d, a, s[maxn], ans;
int n;
std::pair<ll, ll> x[maxn];
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> d >> a;

	for (int i = 1; i <= n; i++) {
		std::cin >> x[i].fi >> x[i].se;
		x[i].se = (x[i].se + a - 1) / a;
	}

	std::sort(x + 1, x + n + 1);

	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		int tmp = x[i].se - s[i];
		if (tmp <= 0)
			continue;
		ans += tmp;
		s[i] += tmp;
		int l = i, r = n;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (x[m].fi <= (x[i].fi + (2 * d)))
				l = m;
			else
				r = m - 1;
		}

		s[l + 1] -= tmp;

	}

	std::cout << ans;

	return 0;
}