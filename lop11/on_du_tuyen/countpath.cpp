#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
int n;
struct Matrix {
	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		vector<vector<long long>> tmp(n, vector<long long>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++){
					tmp[i][k] += (long long) a[i][j] * other.a[j][k];
					if(tmp[i][k] >= 8LL * mod * mod)
						tmp[i][k] %= mod;
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				product.a[i][j] = tmp[i][j] % mod;

		return product;
	}
};

Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,n) product.a[i][i] = 1;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}

void count_path()

int main() {
	int m;
	long long k;
	cin >> n >> m >> k;
	Matrix single;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		single.a[u-1][v-1] = 1;
	}
	Matrix total = expo_power(single, k);
	int answer = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			answer = (answer + total.a[i][j]) % mod;
	cout << answer << endl;
}