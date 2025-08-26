#include <bits/stdc++.h>
#define task "teams"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];
std::vector<ii> v;
std::vector<std::vector<int>> ans;
std::vector<int> cur;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;

    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> a[i];
        v.pb(ii(a[i], i));
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int lim = v[i].fi;
        cur.pb(v[i].se);
        if (cur.size() >= lim)
        {
            ans.pb(cur);
            cur.clear();
        }
    }

    if (!cur.empty())
    {
        if (ans.empty())
        {
            int mx = 0;
            for (int idx : cur)
            {
                mx = std::max(mx, a[idx]);
            }
            if (cur.size() >= mx)
            {
                ans.pb(cur);
                cur.clear();
            }
            else
            {
                std::cout << 0 << '\n';
                return 0;
            }
        }
        else
        {
            std::set<ii> s;
            for (int i = 0; i < ans.size(); i++)
            {
                s.ins({ans[i].size(), i});
            }

            for (int idx : cur)
            {
                int need = a[idx] - 1;
                auto it = s.lower_bound({need, -1});
                if (it == s.end())
                {
                    auto it2 = std::prev(s.end());
                    ii p = *it2;
                    s.erase(it2);
                    if (p.fi + 1 < a[idx])
                    {
                        std::cout << 0 << '\n';
                        return 0;
                    }
                    ans[p.se].pb(idx);
                    s.ins({p.fi + 1, p.se});
                }
                else
                {
                    ii p = *it;
                    s.erase(it);
                    ans[p.se].pb(idx);
                    s.ins({p.fi + 1, p.se});
                }
            }
            cur.clear();
        }
    }

    std::cout << ans.size() << "\n";
    for (auto i : ans)
    {
        std::cout << i.size();
        for (int x : i)
        {
            std::cout << ' ' << a[x];
        }
        std::cout << '\n';
    }

    return 0;
}
