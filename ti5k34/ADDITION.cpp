#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);
	std::string a, b;
	std::cin >> a >> b;
	if (a.size() < b.size())
		std::swap(a, b);

	while (b.size() < a.size())
		b = '0' + b;

	int tmp = 0, ans = 0;
	for (int i = a.size() - 1; i >= 0; i--){
		int x = a[i] - '0', y = b[i] - '0';
		if (x + y + tmp >= 10){
			tmp = 1;
			ans++;
		}else{
			tmp = 0;
		}
	}

	std::cout << ans;

	return 0;
}