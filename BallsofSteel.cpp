#include <bits/stdc++.h>
#define task "BallsofSteel"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int t;

void solve(){
	int n, k;
	int x[105], y[105];
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
		std::cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++){
		bool check = true;
		for (int j = 1; j <= n; j++)
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
				check = false;
		if (check){
			std::cout << 1 << "\n";
			return;
		} 
	}

	std::cout << -1;
	std::cout << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> t;
	while (t--)
		solve();

	return 0;
}