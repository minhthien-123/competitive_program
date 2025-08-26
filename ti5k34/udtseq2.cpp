#include <bits/stdc++.h>
#define task "udtseq2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int mod  = 1e9 + 7;

int n, m;
int a[maxn], l[maxn], r[maxn], k[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        std::cin >> l[i] >> r[i] >> k[i];

        a[l[i]] += k[i] % mod;
        //a[l + 1] += k;
        a[r[i] + 1] -= k[i] % mod;
        //a[r[i] + 2] -= k * (r - l + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i] + a[i - 1] % mod);
    }

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";*/

    for (int i = 1; i <= m; i++)
    {
        a[r[i] + 1] -= (k[i] * (r[i] - l[i] + 1) % mod);
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i]) % mod;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}