#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,  i;
	long m, x, k;
	char s[500], st[500];
	
	cin >> n >> m >> k >> x;
	cin >> s;
	
	st = "";
	
	for (int i = n; i >= 0; i--){
		if (s[i] != "#"){
			st = s[i] + st;
		}
	}
	cout << st;
}
