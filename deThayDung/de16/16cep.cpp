#include <bits/stdc++.h>
typedef long long ll;

const int maxn = 1e6 + 5;

int n;
ll a[maxn], ans = LLONG_MIN, f[maxn], mx;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("16cep.inp", "r", stdin);
    std::freopen("16cep.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    mx = a[1];
    for (int i = 2; i <= n; i++){
        f[i + 1] = mx - a[i];
        mx = std::max(a[i], mx);
    }

    for (int i = 3; i <= n; i++)
        ans = std::max(f[i] - a[i], ans);

    std::cout << ans;

    return 0;
}
