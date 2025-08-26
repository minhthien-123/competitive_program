#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], d, d1, d2;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > 0) d++;
		else if(a[i] == 0) d1++;
		else 				d2++;
	}	
	if (d1 != 0) cout << -1;
	else		 cout << abs(d - d2);
}
