#include <bits/stdc++.h>

int n, q;
long long k, a[1000005], ans, d;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sk15.inp", "r", stdin);
    std::freopen("sk15.out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    while (q--){
        std::cin >> k;
        ans = LLONG_MIN;
        d = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] <= k)
                d++;
            else{
                ans = std::max(ans, d);
                d = 0;
            }
        }

        std::cout << std::max(ans, d) << "\n";
    }

    return 0;
}