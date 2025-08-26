#include <bits/stdc++.h>

const int maxn = 1e6;

int n, a[maxn + 5], res[2 * maxn + 5], ans = 0;

int main(){
    std::freopen("dxb4.inp", "r", stdin);
    std::freopen("dxb4.out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        if (x % 2 == 0) a[i] = 1;
        else            a[i] = -1;
    }

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    /*for (int i = 0; i <= n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";*/

    for (int i = 0; i <= n; i++)
        res[a[i] + maxn]++;

    for (int i = 0; i <= n; i++){
        int tmp = res[a[i] + maxn];
        //std::cout << tmp << " ";
        ans += tmp * (tmp - 1) / 2;
        res[a[i] + maxn] = 0;
    }
    std::cout << "\n";
    std::cout << ans;
}