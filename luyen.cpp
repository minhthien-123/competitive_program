#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	long n, d;
	cin >> t;
	for (int i = 0; i <= n; i++){
		cin >> n;
		d = 0;
		while (n != 1){
			if (n % 2 == 0){
				n = trunc(n / 2);
				d += 1;
			}else if(n % 3 == 0){
				n = trunc(n / 3);
				d += 1;
			}else{
				n -= 1;
				d += 1;
			}
		}
		cout << d << endl;
	}
}
