#include <bits/stdc++.h>
#define task "SonRao"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;

int n, k;
int f[maxn + 7], pre[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        pre[i] = pre[i - 1] + 1;
        f[i] = 1;
    }

    for (int i = k + 1; i <= n; i++)
    {
        f[i] = (pre[i - k] + f[i]) % mod;
        pre[i] = (pre[i - 1] + f[i]) % mod;
    }

    std::cout << f[n] + 1;

    return 0;
}
