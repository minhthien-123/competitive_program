#include <bits/stdc++.h>
using namespace std;

long long n, s, t = 0, a[405], dp[405], i, j, d[405];

int main(){
	//freopen("tugofwar.inp", "r", stdin);
	//freopen("tugofwar.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (i = 0; i < n; i++){
		cin >> a[i];
		t += a[i];
	}

	s = t / 2;

	while (s > 0){
		bool dp[n + 5][s + 5], d[n + 5];

		for (i = 0; i <= n; i++) dp[i][0] = 1;

		for (i = 1; i <= s; i++) dp[0][i] = 0;

		for (i = 1; i <= n; i++){
			for (j = 1; j <= s; j++){
				if (j <= a[i - 1]) dp[i][j] = dp[i - 1][j];
				else			   dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
			}
		}

		if (dp[n][s] == 1){
			while (s > 0){
		        for (int i = 1; i <= n; i++) if (dp[i][s]){
					s -= a[i];
					d[i] = 1;
					break;
				}
		    }

		    for (i = 0; i < n; i++){
		    	if (d[i]) cout << i << " ";
			}
		}
		else{
			s -= 1;
		}
	}

	for (i = 0; i <= s; i++) cout << dp[i];

}
