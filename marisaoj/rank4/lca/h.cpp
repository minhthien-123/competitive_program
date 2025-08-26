#include <bits/stdc++.h>
#define task "h"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7], b[maxn + 7], pre[maxn + 7];
std::vector<int> va[maxn + 7], vb[maxn + 7];

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
        va[a[i]].pb(i);
    }
    for (int j = 1; j <= n; j++)
    {
        std::cin >> b[j];
        vb[b[j]].pb(j);
    }

    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            s += i * (i - 1) / 2 + (n - i) * (n - i + 1) / 2;
        }
    }

    for (int j = 1; j <= n; j++)
    {
        std::vector<int> tmpa = va[j], tmpb = vb[j];

        for (int i = 1; i <= tmpa.size(); i++)
        {
            pre[i] = pre[i - 1] + tmpa[i - 1];
        }

        for (int i : tmpb)
        {
            int x = n - i + 1;
            int l = std::min(i, x);
            int r = std::max(i, x);

            int cnt1 = std::lower_bound(tmpa.begin(), tmpa.end(), l) - tmpa.begin();
            int cnt2 = std::lower_bound(tmpa.begin(), tmpa.end(), r) - tmpa.begin();

            int val;
            if (i >= x)
            {
                val = n - i + 1;
            }
            else
            {
                val = i;
            }

            int cnt3 = tmpa.size() - cnt2;

            s += pre[cnt1] + (cnt2 - cnt1) * val + cnt3 * (n + 1) - (pre[tmpa.size()] - pre[cnt2]);
        }
    }

    std::cout << s;

    return 0;
}
