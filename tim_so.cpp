#include <bits/stdc++.h>
using namespace std;

long long gt(long long x){
	long long i, s = 1;
	for (i = 1; i <= x; i++){
		s *= i;
	}
	
	return s;
}

/*long long p(long long a, long long b){
	long long s = a;
	for(long long i = 1; i <= b; i++){
		s*=a;
	}
	
	return s;
}*/

int main(){
	long long n, m, k, p, g;
	cin >> n >> m;
	//k = m;
	if (m == gt(n)){
		cout << 1;
	}else{
		k = m;
		p = pow(m, k);
		g = gt(n);
		while(g % p != 0){
			k --;
			p = pow(m, k);
			g = gt(n);
		cout << k;
		break;
		}
	}
	return 0;
}
