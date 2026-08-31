#include <bits/stdc++.h>
using namespace std;

int main(){
	long n, t = 0, a[100000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++){
			for (int k = j + 1; k < n; k++){
				t += a[i] * a[j] * a[k];
			}
		}
	}
	cout << t;
}
