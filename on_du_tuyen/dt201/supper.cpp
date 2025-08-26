#include <bits/stdc++.h>
#define task "supper"
#define int unsigned long long

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int a[maxn], deg[maxn], minPrime[maxn];
int mod, t;
int minn = inf;

int power(int a, int b, int mod){
    if (b == 0) return 1 % mod;
    else{
        int tmp = power(a, b / 2, mod);
        if (b % 2 == 0)
            return tmp * tmp % mod;
        else
            return a * (tmp * tmp % mod) % mod;
    }
}

void sieveA(int x, int y){
    while (x > 1){
        int p = minPrime[x];
        deg[p] += y;
        x /= p;
    }
}

void sieveB(int x, int y){
    while (x > 1){
        int p = minPrime[x];
        deg[p] -= y;
        x /= p;
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    for (int i = 2; i * i <= maxn; i++)
        if (minPrime[i] == 0)
            for (int j = i * i; j <= maxn; j += i)
                if (minPrime[j] == 0)
                    minPrime[j] = i;
    for (int i = 1; i <= maxn; i++)
        if (minPrime[i] == 0)
            minPrime[i] = i;

    std::cin >> mod >> t;

    std::fill_n(a, maxn, 1);

    for (int i = 1; i <= t; i++){
        int type, x, y;

        std::cin >> type;

        if (type == 3){
            minn = inf;
            for (int i = 1; i <= 1e4; i++)
                if (deg[i] != 0)
                    minn = std::min(minn, deg[i]);

            int ans = 1, res = 0;
            for (int i = 1; i <= 1e4; i++)
                if (deg[i] != 0){
                    int q = deg[i] / minn;
                    ans = ans * power(i, q, mod) % mod;
                }

            std::cout << ans << " " << minn << "\n";
        }else{
            std::cin >> x >> y;

            if (type == 1){
                sieveA(x, y);
                //a[y] *= x;
            }else{
                sieveB(x, y);
                //a[x] /= y;
            }
        }
    }

    return 0;
}
