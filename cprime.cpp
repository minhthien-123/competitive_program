r#include <bits/stdc++.h>
#define task "cprime"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, ans = 0;
bool a[10007];

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
    for (int i = 1; i <= n; i++)
    	if(solve(i))
    		ans++;

   	std::cout << ans;

	return 0;
}