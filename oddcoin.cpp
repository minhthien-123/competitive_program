#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	long a[16] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
	for (int i = 0; i < q; i++){
		long x, t, d = 0, k = 0;
		cin >> x >> t;
		a[15] = x;
		sort(a, a + 16);
		int j = 15;
		while ((j >= 0) || (t > 0)){
			long d1 = t / a[j];
			d += d1;
			k += d1 * a[j];
			t %= t / a[j];
			
		}
		if (k == t) cout << d;
		else		cout << d + 1;
	}
}
