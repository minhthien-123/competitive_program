#include <bits/stdc++.h>
#define ll long long

ll m, n, i, j, a[1000005], b[1000005];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sortmer.inp", "r", stdin);
    std::freopen("sortmer.out", "w", stdout);

    std::cin >> m >> n;
    for (ll i = 1; i <= m; i++)
        std::cin >> a[i];
    for (ll i = 1; i <= n; i++)
        std::cin >> b[i];

    ll i = 1; j = 1;
    while (i <= m && j <= n) {
        if (a[i] < b[j]) {
            std::cout << a[i] << " ";
            i++;
        } else if (a[i] > b[j]) {
            std::cout << b[j] << " ";
            j++;
        } else {
            std::cout << a[i] << " ";
            i++;
            std::cout << b[j] << " ";
            j++;
        }
    }

    while (i <= m) {
        std::cout << a[i] << " ";
        i++;
    }
    while (j <= n) {
        std::cout << b[j] << " ";
        j++;
    }

    return 0;
}