#include <bits/stdc++.h>
#define ll long long

ll ans, res1, res2, a[1000005], n;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("18cis.inp", "r", stdin);
    std::freopen("18cis.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);

    if (a[1] >= 0 || a[n] <= 0 || a[2] >= 0)
        ans = a[n] * a[n - 1] * a[n - 2] + a[n - 3] * a[n - 4] * a[n - 5];
    else if (a[n - 1] <= 0){
        ans = a[1] * a[2];
        ans = std::max(ans * a[3] + a[4] * a[5] * a[6], ans * a[n] + a[3] * a[4] * a[5]);
    }else{
        res1 = a[1] * a[2];
        res2 = a[n - 1] * a[n - 2];
        ans  = std::max(res1 * a[n] + res2 * a[n - 3], res1 * a[n - 3] + res2 * a[n]);
    }

    std::cout << ans;

    return 0;
}
