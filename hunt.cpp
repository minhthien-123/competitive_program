#include <bits/stdc++.h>
using namespace std;

//long long re(long long n){}
long long n, m, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("hunt.inp", "r", stdin);
    freopen("hunt.out", "w", stdout);

    cin >> n;
    m = n;
    while (n--){
        string v, s;
        cin >> v;
        s = v;
        reverse(s.begin(), s.end());
        if (s == v) {
            ans = n;
            //cout << s << "\n";
        }
    }

    cout << m - ans;
}
