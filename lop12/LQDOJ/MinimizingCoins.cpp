#include <bits/stdc++.h>
#define task MinimizingCoins
#define ll long long

int n, x, res[1000005];
ll a[1000005];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> x;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    res[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= n; j++)
            if (a[j] <= i)
                res[i] = std::min(res[i - a[j] + 1], res[i]);

    std::cout << res[x];

    return 0;
}
