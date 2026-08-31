#include <bits/stdc++.h>
#define task "ColorfulSlimes2"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;

ll mn = 1e9, mx = -1e9, ans = 0, n, pmn, pmx;
ll a[maxn];

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	for (int i = 1; i <= n; i++)
		if (a[i] == a[i - 1]){
			ans++;
			a[i] = -1;
		}

	std::cout << ans;

	return 0;
}