#include <bits/stdc++.h>

inline bool ss(long long a, long long b){return a > b;}
int n, k;
long long ans, a[1000005];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("exp12.inp", "r", stdin);
    std::freopen("exp12.out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a, a + n, ss);

    ans = a[0];

    for (int i = 1; i <= k; i++)
        ans += a[i];
    for (int i = k + 1; i < n; i++)
        ans -= a[i];

    std::cout << ans;

    return 0;
}