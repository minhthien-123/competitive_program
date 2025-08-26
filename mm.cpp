#include <bits/stdc++.h>
using namespace std;

long long n, i, d = 0;
string s, st;
map<string, long long>m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("mm.inp", "r", stdin);
    freopen("mm.out", "w", stdout);

    cin >> s;
    i = 0;
    while (i < s.size()){
        if ('a' <= s[i] && s[i] <= 'z') st = ' ';
        else{
            while (s[i] = '0' && 'a' <= s[i - 1] && s[i - 1] <= 'z') s.erase(i, 1);
            while ('1' <= s[i] && s[i] <= '9' && i < s.size()){
                st += s[i];
                i++;
            }
            cout << st << "\n";
            /*if (m[st] == 0){
                m[st] = 1;
                d++;
            }*/
        }
        i++;
    }

    cout << d;
}
