#include <bits/stdc++.h>
using namespace std;

long long n, i, a[2000005], ans = LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BICYCLE.inp", "r", stdin);
    freopen("BICYCLE.out", "w", stdout);

    cin >> n;
    n *= 2;
    for (i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (i = 0; i < n / 2; i++)
        ans = max(ans, a[i] + a[n - i - 1]);

    cout << ans;
}