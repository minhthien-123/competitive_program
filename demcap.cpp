#include <bits/stdc++.h>
using namespace std;

int main(){
	long a, b, n;
	cin >> n >> a >> b;
	long c = n - a, s = b - a + 1, d = c - s + 1;
	cout << (d + c) * s / 2;
	
}
