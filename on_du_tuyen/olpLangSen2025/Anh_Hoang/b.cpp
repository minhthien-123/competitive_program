#include <bits/stdc++.h>
#define task "task"
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

int t, n;
ii a[maxn + 7];
int f[maxn + 7];

bool cmp(ii a, ii b)
{
    if (a.fi == b.fi)
    {
        return a.se < b.se;
    }
    return a.fi > b.fi;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i].fi;
            a[i].se = i;
            f[i] = a[i].fi;
        }
        std::set<int> s;
        for (int i = 1; i <= n; i++)
        {
            s.ins(i);
        }

        std::sort(a + 1, a + n + 1, cmp);
        bool flag = false;
        std::vector<int> v;
        v.pb(0);
        for (int i = 1; i <= n; i++)
        {
            if (a[i].se > v.back())
            {
                v.pb(a[i].se);
                s.erase(a[i].se);
            }
            else
            {
                int tmp1 = v.back();
                if (!flag)
                {
                    int tmp2 = v[v.size() - 2];
                    if (tmp2 < a[i].se && a[i].se < tmp1)
                    {
                        v.pb(a[i].se);
                        s.erase(a[i].se);
                        flag = true;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                continue;
            }
            if (!flag)
            {
                auto pos = s.upper_bound(v.back());
                if (pos != s.end())
                {
                    v.pb(*pos);
                    s.erase(*pos);
                    flag = true;
                }
            }
        }

        for (int i = 1; i < v.size(); i++)
        {
            std::cout << f[v[i]] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
