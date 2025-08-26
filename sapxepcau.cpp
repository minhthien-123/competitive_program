#include <bits/stdc++.h>
using namespace std;

long long n, k, d1, d2, i, s[1000005], d;
string s1, s2;
vector<long long> a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sapxepxau.inp", "r", stdin);
    freopen("sapxepxau.out", "w", stdout);

    cin >> n >> k;
    cin >> s1 >> s2;

    for (i = 0; i < n; i++) cin >> s[i];

    d1 = 0;
    d2 = 0;
    for (i = 0; i < n; i++){
        if (s1[i] == s2[i]){
            if (d1 != 0) a.push_back(d1);
            d1 = 0;
            d2 += s[i];
        }else{
            if (d2 != 0) b.push_back(d2);
            d2 = 0;
            d1 += s[i];
        }
    }

    if (d1 != 0) a.push_back(d1);
    if (d2 != 0) b.push_back(d2);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    /*for (i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << "\n";
    for (i = 0; i < b.size(); i++) cout << b[i] << " ";
    cout << "\n";*/

    d = 0;
    if (k > a.size()){
        for (i = 0; i < k; i++)
            d += a[i];
        cout << d;
    }else{
        for (i = 0; i < a.size(); i++) d += a[i];
        k = a.size() - k;
        for (i = 0; i < k; i++) d += b[i];

        cout << d;
    }
}
