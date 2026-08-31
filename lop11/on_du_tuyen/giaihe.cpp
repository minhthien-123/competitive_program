#include <bits/stdc++.h>
#define task "giaihe"
#define int long long

const int maxn = 1e4 + 7;

int pow(int a, int b, int mod){
      if (b == 0)
           return 1;
      if (b == 1)
           return a;

      int tmp = pow(a, b / 2, mod) % mod;

      if (b % 2 == 0)
           return (tmp * tmp) % mod;
      else
           return (((tmp * tmp) % mod) * a) % mod;
}

int modulo_inverse(int a, int mod){
      return pow(a, mod - 2, mod);
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--){
        int q;
        std::cin >> q;
        int a[maxn], m[maxn], prod = 1, ans = 0;

        for (int i = 1; i <= q; i++){
            std::cin >> a[i] >> m[i];
            if (a[i] < 0) a[i] += m[i];
            a[i] %= m[i];
            prod *= m[i];
        }

        for (int i = 1; i <= q; i++){
            int n = prod / m[i];
            int inv = n % m[i];
            //std::cout << inv << " ";
            inv = modulo_inverse(inv, m[i]);
            inv %= m[i];

            //std::cout << prod / a[i] << "\n";
            //std::cout << inv  << '\n';
            //std::cout << n << " " << m[i] << "\n";

            ans = (ans % prod + a[i] * inv * n % prod) % prod;
        }

        if (ans == 0) ans = -1;
        std::cout << ans % prod << '\n';
    }

    return 0;
}
