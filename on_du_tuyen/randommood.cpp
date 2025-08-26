#include <bits/stdc++.h>
#define task "randommood"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;
double p, ans = 1.0;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n >> p;
	while (n > 0){
		if (n % 2 == 1)
            ans = ans * (1 - p) + (1 - ans) * p;
        p = 2 * p * (1 - p);
        n /= 2;
	}

	std::cout << std::setprecision(10) << std::fixed << ans;

	return 0;
}