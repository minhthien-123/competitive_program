#include <bits/stdc++.h>
using namespace std;

long long i, j;
string s, kt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    kt = "hello";
    j = 0;
    for (i = 0; i < s.size(); i++){
        //cout << s[i] << " " << kt[j] << "\n";
        if (s[i] == kt[j]) j++;
    }

    //cout << j;

    if (j == 5) cout << "YES";
    else		cout << "NO";
}
