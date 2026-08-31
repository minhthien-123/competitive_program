#include <bits/stdc++.h>
#define int long long

int mn, h[1000005], f[1000005], i, j, n, k;

signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> n >> k;
    for (i = 1; i <= n; i++)
        std::cin >> h[i];

    f[1] = 0;
    f[2] = abs(h[1] - h[2]);

    for (i = 3; i <= k; i++){
        mn = LLONG_MAX;
        for (j = 1; j <= i - 1; j++)
            mn = std::min(mn, f[j] + abs(h[j] - h[i]));
        f[i] = mn;
    }

    for (i = k + 1; i <= n; i++){
        mn = LLONG_MAX;
        for (j = i - k; j <= i - 1; j++)
            mn = std::min(mn, f[j] + abs(h[j] - h[i]));
        f[i] = mn;
    }

    /*for (i = 1; i <= n; i++)
        std::cout << f[i] << " ";

    std::cout << "\n";*/

    std::cout << f[n];
}
