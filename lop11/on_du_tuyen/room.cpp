#include <bits/stdc++.h>
#define task "room"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, a, b;
ii res;
bool flag = true, check = true;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> a >> b;
	n *= 6;

	if (a > b){
		std::swap(a, b);
		flag = true;
	}

	while (check){
		for (int i = 1; i <= sqrt(n); i++){
	    	if (n % i == 0){
	    		int j = n / i;
	    		if (i >= a && j >= b){
	    			res = {i, j};
	    			check = false;
	    		}
	    	}
	    }
		n++;
	}

	if (!flag) std::swap(res.fi, res.se);

	std::cout << res.fi * res.se << "\n";
	std::cout << res.fi << " " << res.se;

	return 0;
}
