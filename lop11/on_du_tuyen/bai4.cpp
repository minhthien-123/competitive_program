#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int k = 2; k <= n; k++){
		if (k % 2 == 0){
			summin += a[k / 2];
			summax += a[n - k / 2 + 1];
		}
		ans = ans + summax - summin;
		std::cout << ans << " ";
	}

	return 0;
}