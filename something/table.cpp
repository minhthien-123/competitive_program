#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, mini = 1, minj = n, i, j;
	cin >> n;
	for (i = 1; i <= (n / 2) + 1; i++){
		if (n % i == 0) j = n / i;
		else			j = n / i + 1;
		if (i + j <= mini + minj) {
			mini = i;
			minj = j;
		}
	}
	cout << mini << " " << minj;
}

