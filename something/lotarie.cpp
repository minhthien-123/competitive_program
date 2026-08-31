#include <bits/stdc++.h>
using namespace std;

int n, d, dem = 0;
string s;

int main(){
    cin >> n;
    cin >> s;

    d = 0;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i - 1]) d++;
        else{
            dem += d / 2;
            d = 0;
        }
    }

    cout << dem;

    return 0;
}
