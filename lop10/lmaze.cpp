#include <bits/stdc++.h>
#define task "lmaze"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
const int inf  = 1e18;

int n;
int a[maxn], f[maxn];
int f1[maxn], f2[maxn];

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
        std::cin >> f[i];
        f1[i] = f2[i] = inf;
    }

    for (int i = 1; i <= n; i++)
    {
        a[f[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    int id = 1;

    return 0;
}
