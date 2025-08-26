#include <bits/stdc++.h>
#define task "delarr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
int s = 0;

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
        s += a[i];
    }

    std::sort(a + 1, a + n + 1);
    int l = 1, r = n, d = 0;
    while (s != 0)
    {
        if (s < 0)
        {
            s -= a[l++];
        }
        else
        {
            s -= a[r--];
        }
        d++;
    }

    std::cout << d;

    return 0;
}
