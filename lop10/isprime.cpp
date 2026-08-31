#include <bits/stdc++.h>
#define task "isprime"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;

bool solve(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;
	if (solve(n))
		std::cout << "YES";
	else
		std::cout << "NO";

	return 0;
}