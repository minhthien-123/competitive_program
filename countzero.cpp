#include <bits/stdc++.h>
using namespace std;

long long n, k, d = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	int tmp = 5;

	
	while (tmp <= n){
		d += n / tmp;
		k += 1;
		tmp *= 5;
	}
	
	cout << d;
	
}
