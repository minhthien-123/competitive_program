#include <bits/stdc++.h>
using namespace std;

long long maxn = 10e6;
vector<bool> a(maxn, true);

long long n, i, j, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("nearest.inp", "r", stdin);
    freopen("nearest.out", "w", stdout);

    a[0] = a[1] = false;
    for (i = 2; i * i <= maxn; i++){
        if (a[i]){
            for (j = i * i; j <= maxn; j += i){
                a[j] = false;
            }
        }
    }

    cin >> n;
    ans = 0;
    while (!a[n + ans] && !a[n - ans]) ans++;

    if (a[n - ans]) cout << n - ans;
    else cout << n + ans;

}