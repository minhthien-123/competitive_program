#include <bits/stdc++.h>
using namespace std;

long long n, m, i, x, k, ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("mindis.inp", "r", stdin);
	freopen("mindis.out", "w", stdout);

	cin >> n >> m;
	long long a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	//for (i = 0; i < n; i++) cout << a[i] << " ";
	//cout << "\n";

	for (i = 0; i < m; i++){
        cin >> x;
        ans = lower_bound(a, a + n, x) - a;

        cout << min(abs(x - a[ans - 1]), abs(x - a[ans])) << "\n";
	}
}
