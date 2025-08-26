#include <bits/stdc++.h>
using namespace std;

int n, i, j;
long long f[405];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
//	freopen("iparb.inp", "r", stdin);
//	freopen("iparb.out", "w", stdout);
	
	cin >> n;
	
	f[0] = 1;
	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			f[j] = f[j] + f[j - i];
		}
	}
	
	cout << f[n];
}
