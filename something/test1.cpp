#include <bits/stdc++.h>
using namespace std;

int main(){
	long n;
	cin >> n;
	
	char s[13];
	for (long i = 0; i < n; i++){
		cin >> s;
		int d = 0;
		for (int j = 0; j < 13; i++){
			if (s[j] == "A") d += 4;
			else if (s[j] == "K"]) d += 3;
			else if (s[j] == "Q") d += 2;
			else if (s[j] == "J") d ++;
		}
		cout << d << endl;
	}
}
