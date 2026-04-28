#include <bits/stdc++.h>
#define task "bocsoi13"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;
std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
double ans = 0.0;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1, x; i <= n; i++){
		std::cin >> x;
		heap.push(x);
	}

	while (heap.size() > 1){
		int x = heap.top();
		heap.pop();
		int y = heap.top();
		heap.pop();

		ans += 0.05 * (x + y);
		heap.push(x + y);
	}

	std::cout << std::setprecision(2) << std::fixed << ans;

	return 0;
}