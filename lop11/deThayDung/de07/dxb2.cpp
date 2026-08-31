#include <bits/stdc++.h>

long long n, x, a[1000005];
long long ans = -1e7;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dxb2.inp", "r", stdin);
    std::freopen("dxb2.out", "w", stdout);

    std::cin >> n;
    for (int long long i = 1, x; i <= n; i++){
        std::cin >> a[i];
        if (a[i] < 0)
            ans = std::max(ans, a[i]);
    }

    for (int i = 1; i <= n; i++)
        if (a[i] == ans){
            std::cout << i;
            return 0;
        }

    std::cout << -1;

    return 0;
}