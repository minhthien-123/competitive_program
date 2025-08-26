#include <bits/stdc++.h>
#define task "findnum"
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
std::vector<ii> a;

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
        int x, y;
        std::cin >> x >> y;
        a.pb({x, 1});
        a.pb({y + 1, -1});
    }

    std::sort(a.begin(), a.end());

    int i = 0, tmp = 0, ans = 0, res = 0;

    while (i < a.size())
    {
        int pos = a[i].fi;
        while (i < a.size() && a[i].fi == pos)
        {
            tmp += a[i].se;
            i++;
        }

        int nxt = inf;
        if (i < a.size())
        {
            nxt = a[i].fi;
        }
        if (pos < nxt)
        {
            if (tmp > ans)
            {
                ans = tmp;
                res = pos;
            }
        }
    }

    std::cout << res;

    return 0;
}
