#include <bits/stdc++.h>
#define task "DIGITSUM"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::string s;
	std::cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		ans += (s[i] - '0');

	std::cout << ans;

	return 0;
}