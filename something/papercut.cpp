#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull m, n, a, b, d, i, ans, res;

void solve(ull x, ull i){
    if (x % i == 0) ans++;
    if (i > trunc(sqrt(x))) return;
    solve(x, i + 1);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("papercut.inp", "r", stdin);
    //freopen("papercut.out", "w", stdout);

    cin >> m >> n;
    ans = 1;
    solve(m, 1);
    res = ans;
    ans = 1;
    solve(n, 1);
    cout << ans * res;
}
