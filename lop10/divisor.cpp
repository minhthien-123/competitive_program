#include <bits/stdc++.h>
#define task "divisor"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int mod = 123456789;
const int maxn = 1e7;

int a[maxn], minPrime[maxn], deg[maxn];
int n, ans = 1;

void sieve()
{
    for (int i = 2; i * i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

void prime(int x){
    while (x != 1){
        int p = minPrime[x];
        deg[p]++;
        x /= p;
    }
}


signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    sieve();

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        prime(a[i]);
    }

    for (int i = 1; i < maxn; i++)
    {
        // if (deg[i] != 0)
        // {
        //     std::cout << i << " " << deg[i] << "\n"; 
        // }

        ans = ans * (deg[i] + 1);
        ans %= mod;
    }

    std::cout << ans;

    return 0;
}
