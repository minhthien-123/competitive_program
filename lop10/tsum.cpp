#include <bits/stdc++.h>
#define task "tsum"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e6;
const int tt   = 1e6;
const int mod  = 1e9 + 7;

int n;
int a[maxn], m[maxn];
int ans = 0;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 2; i <= n - 2; i++)
    {
        for (int j = 1; j < i; j++)
        {
            m[a[i] + a[j]]++;
        }
        for (int k = i + 2; k <= n; k++)
        {
            ans += m[a[k] - a[i + 1]];
            ans %= mod;
        }
    }

    std::cout << ans;

    return 0;
}
