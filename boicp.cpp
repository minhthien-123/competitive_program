#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long l;

inline l gcd(l a, l b){ll r; while(b){r=a%b ;a=b; b=r;}return a;}
inline ll lcm(l x, l y){return x / gcd(x, y) * y;}

int main(){
	l n;
	cin >> n;
	long a[n];
	for (l i = 0; i < n; i++){
		cin >> a[i];
	}
	
}
