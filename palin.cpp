#include <bits/stdc++.h>
using namespace std;

int d = 0;
map<char, int> m;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;

    for(char ch : s) {
        m[ch]++;
        if (m[ch] % 2 == 1) d++;
        else                d--;
    }
    if (d > 1)
        cout << s.length() - d + 1;
    cout << s.length();
}

