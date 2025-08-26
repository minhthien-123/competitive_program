#include <bits/stdc++.h>
using namespace std;

long long i, n, m;
string s = "";

long long big_mod(string a, long long b){
    long long res = 0;
    for (int i = 0; i < a.size(); i++) ans = (ans * 10 + (a[i] - '0')) % b;
        
    return ans;
}

int main(){
	cin >> s >> n;
	
	cout << big_mod(s, n);
	
}
