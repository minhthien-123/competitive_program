#include <bits/stdc++.h>
#define task "X"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 5e3 + 7;

int n, ans = 0;
std::map<int, int> m;
int d[50007], res[50007], a[50007];

void sub123(){
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			m[a[i] + a[j]]++;

	for (int k = 1; k <= n; k++)
		if (m[2 * a[k]])
			ans++;

	std::cout << ans;
}

void sub4(){
	for (int i = 1; i <= n; i++)
		d[a[i]]++;
	for (int i = 1; i <= maxn; i++)
		if (d[i]){
			d[i]--;
			for (int j = i; j <= maxn; j++)
				if (d[j])
					res[i + j]++;
		}

	for (int i = 1; i <= n; i++)
		if (res[2 * a[i]])
			ans++;

	std::cout << ans;
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	if (n <= 3000) sub123();
	else		   sub4();

	return 0;
}