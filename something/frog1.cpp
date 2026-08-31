#include <bits/stdc++.h>
using namespace std;

int main(){
long n;
	cin >> n;
	long a[100000000], f[100000000];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	f[1] = 0;
	f[2] = abs(a[2] - a[1]);
	for (int i = 3; i <= n; i++){
		f[i] = min(f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << f[n];
}
