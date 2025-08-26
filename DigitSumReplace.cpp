#include <bits/stdc++.h>
#define task "DigitSumReplace"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 2e5 + 7;

int m;
int d[maxn], c[maxn];

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> m;
	for (int i = 1; i <= m; i++){
		std::cin >> d[i] >> c[i];
		d[i] *= c[i];
		c[i] += c[i - 1];
		d[i] += d[i - 1];
	}

	std::cout << (c[m] - 1) + (d[m] - 1) / 9;

	return 0;
}