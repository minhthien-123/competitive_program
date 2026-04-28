#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

std::queue<ii> q;
std::unordered_set<int> vis;
int n, m;

int bfs(){
	while (q.size()){
		ii t = q.front();
		q.pop();

		if (t.fi == m)
			return t.se;

		if (t.fi <= m && vis.find(t.fi * 2) == vis.end()){
			q.push({t.fi * 2, t.se + 1});
			vis.ins(t.fi * 2);
		}

		if (t.fi - 1 >= 0 && vis.find(t.fi - 1) == vis.end()){
			q.push({t.fi - 1, t.se + 1});
			vis.ins(t.fi - 1);
		}
	}

	return -1;
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> m;
	if (n >= m){
		std::cout << n - m;
		return 0;
	}

	q.push({n, 0});
	vis.ins(n);

	std::cout << bfs();

	return 0;
}