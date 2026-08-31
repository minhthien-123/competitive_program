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

	int t;
	std::cin >> t;

	while (t--){
		bool check = true;
		std::string a, b;
		std::cin >> a >> b;
		if (a.size() < b.size()) check = false;
		int tmp = a.size() - b.size();

		for (int i = 0; i < b.size(); i++)
			if (a[i + tmp] != b[i])
				check = false;

		if (check) std::cout << "YES\n";
		else	   std::cout << "NO\n";
	}

	return 0;
}