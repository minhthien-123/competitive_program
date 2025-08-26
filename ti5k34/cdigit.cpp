#include <bits/stdc++.h>
#define task ""
#define int unsigned long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	int n, x;
	std::cin >> n;
	x = n;
	int d = 1;
	while (x /= 10)
		d++;

	int m = 0;
	while (d--)
		m = m * 10 + 9;

	//std::cout << n;


	//std::cout << m << "\n";

	int t = 9, k = 1, ans = 0;
	while (t <= m){
		//std::cout << t << " ";
		int cmp = (t + 1) / 10;
		if (t > n) t = n;

		//std::cout << t << " ";

		ans = ans + (t - cmp + 1) * k;

		//std::cout << t << " " << cmp << "\n";

		t = t * 10 + 9;

		k++;
	}

	std::cout << ans;

	return 0;
}