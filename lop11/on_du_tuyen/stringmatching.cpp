#include <bits/stdc++.h>
#define task "stringmatching"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::string p, s;
	std::cin >> s >> p;
	std::string c = p + '#' + s;

	int n = (int)c.size();
	std::vector<int> v(n);

	for (int i = 1, j = 0; i < n; i++){
		while (j > 0 && c[j] != c[i]) 
			j = v[j - 1];
		if (c[i] == c[j])
			j++;
		v[i] = j;
	}

	int ans = 0;


	for (int l : v)
		if (l == p.size()) 
			ans++;
	std::cout << ans;
}