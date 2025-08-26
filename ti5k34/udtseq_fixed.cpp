#include <bits/stdc++.h>
#define task "udtseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, m;
int a[maxn + 7];

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
        int l, r, k;
        std::cin >> l >> r >> k;
        a[l] += k;
        a[r + 1] -= k;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        std::cout << a[i] << " ";
    }

    return 0;
}
