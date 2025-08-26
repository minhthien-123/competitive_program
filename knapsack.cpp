#include <bits/stdc++.h>
using namespace std;

int main(){
	long k, s;
	int n, i, j;
	long w[100], v[100];
	
	cin >> n >> k;
	
	long f[n + 1][k + 1];
	
	for (i = 0; i < n; i++){
		cin >> w[i] >> v[i];
	}
	
	for (i = 0; i <= n; i++){
		for (j = 0; j <= k; j++){
			if ((i == 0) or (j == 0)){
				f[i][j] = 0;
			}else if (w[i - 1] <= k){
				f[i][j] = max(f[i - 1][j - w[i - 1]] + v[i - 1] , f[i - 1][j]);
			}else{
				f[i][j] = f[i - 1][j];
			}
		}
	}
	
	cout << f[n][k];
}
