#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, max = 0;
	cin >> n;
	long a[n], dp[n] = {};
	
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 1; i < n; i++){
		if (a[i] * a[i - 1] < 0) dp[i] = dp[i - 1] + 1;
		if (dp[i] > max) max = dp[i];
	}
	cout << max + 1;
}
