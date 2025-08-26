#include <bits/stdc++.h>
using namespace std;

long long n, k, a[10000000], prf[10000000], dd[10000000], ans = 0, i;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sdivk.inp", "r", stdin);
	freopen("sdivk.out", "w", stdout);
	cin >> n >> k;
	for (i = 1; i <= n; i++){
		cin >> a[i];
		prf[i] = (prf[i - 1] + a[i]) % k;
	}
	
	for (i = 0; i <= n; i++){
		ans += dd[prf[i]];
		dd[prf[i]]++;
	}
	
	cout << ans;
}
