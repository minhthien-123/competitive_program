#include <bits/stdc++.h>
using namespace std;

long long n, i, ans, k;
long long a[10000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("chosebook.inp", "r", stdin);
    freopen("chosebook.out", "w", stdout);

    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    ans = LLONG_MAX;
    for (i = k; i <= n; i++) ans = min(ans, a[i] - a[i - k + 1]);

    cout << ans;
}
