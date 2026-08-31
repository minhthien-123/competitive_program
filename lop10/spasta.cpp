#include <bits/stdc++.h>
#define task "spasta"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, m, k, t;
int a[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> k >> n >> t;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int cnt = 0, lst = 0;
    int ans = 0;

    

    return 0;
}
