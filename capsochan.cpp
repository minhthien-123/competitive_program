#include <bits/stdc++.h>
using namespace std;

int main(){
	long n;
	long long s = 0;
	cin >> n;
	long k = n;
	for (long i = 2; i <= n; i+=2){
		s += k;
		k--;
	}
	cout << s;
}
