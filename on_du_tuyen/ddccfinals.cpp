#include <bits/stdc++.h>
#define task "ddccfinals"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

ll a, b, x, y;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> x >> y;

	a = 100000 * (4 - x) * (x <= 3);
	b = 100000 * (4 - y) * (y <= 3);

	//std::cout << a << " " << b << " ";

	std::cout << a + b + 400000 * (x == 1 && y == 1);

	return 0;
}