#include <bits/stdc++.h>
#define task "treasure"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;

int n, k;
int a[maxn + 7], b[maxn + 7], c[maxn + 7], p[maxn + 7];
int par[maxn + 7], sz[maxn + 7];

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> c[i];
    }

    for (int i = 1; i <= k; i++)
    {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 1; i <+ k; i++)
    {
        std::cin >> p[i];
    }

    

    return 0;
}
