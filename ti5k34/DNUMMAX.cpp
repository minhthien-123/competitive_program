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

	int n;
	std::cin >> n;
	int tmp = n, cmp = 0;
	while (tmp > 0){
		cmp *= 10;
		cmp += 1;
		tmp /= 10;
	}

	if (cmp > n)
		cmp /= 10;

	std::cout << cmp * (n / cmp);

	return 0;
}