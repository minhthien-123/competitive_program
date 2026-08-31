#include <bits/stdc++.h>
using namespace std;

bool kt(long long n){
	int kt = 1;
	long long i;
	for (int i = 2; i <= trunc(sqrt(n)); i++){
		if (n % i == 0){
			kt = 0;
		}
	}
	return kt == 1;
}

int main(){
	long long n;
	cin >> n;
	if(kt(n)){
		cout << "YES";
	}else{
		cout << "NO";
	}
}
