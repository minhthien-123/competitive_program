#include <bits/stdc++.h>
#define task "main"
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
const int inv  = (mod + 1) / 2;

int n, q;
int a[maxn + 7];
int f[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    f[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] ^ a[i];
    }

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << (f[y] ^ f[x - 1]) << '\n';
    }

    return 0;
}
