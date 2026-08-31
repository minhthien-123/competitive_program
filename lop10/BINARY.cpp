#include <bits/stdc++.h>
#define task "BINARY"
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

	int n;
	std::cin >> n;
	std::string s;
	while (n > 0){
		if (n % 2 == 0)
			s = '0' + s;
		else
			s = '1' + s;
		n /= 2;
	}

	std::cout << s;

	return 0;
}