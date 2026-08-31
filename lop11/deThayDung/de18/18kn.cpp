#include <bits/stdc++.h>
#define ll long long

int n, k, a[1000005];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("18kn.inp", "r", stdin);
    std::freopen("18kn.out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    if (k > n)
        std::cout << "NO";
    else{
        std::sort(a + 1, a + n + 1);
        std::cout << a[k];
    }

    return 0;
}
