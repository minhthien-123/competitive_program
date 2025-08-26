#include <bits/stdc++.h>
#define task "rook"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int t;

void add(std::set<int> &s, int x)
{
    s.ins(x);
    s.ins(x - 1);
    s.ins(x + 1);
}

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

    int t;
    std::cin >> t;
    while (t--)
    {
        int xs, ys, xt, yt, n;
        std::cin >> xs >> ys >> xt >> yt >> n;

        std::vector<ii> obs(n);
        std::set<ii> obs_set;
        for (auto &p : obs)
        {
            std::cin >> p.fi >> p.se;
            obs_set.ins(p);
        }

        std::set<int> R, C;
        add(R, xs);
        add(R, xt);
        add(C, ys);
        add(C, yt);
        for (auto e : obs)
        {
            add(R, e.fi);
            add(C, e.se);
        }
        std::vector<int> Rv(R.begin(), R.end()), Cv(C.begin(), C.end());

        std::map<int, std::set<int>> r_obs, c_obs;
        for (auto e : obs)
        {
            r_obs[e.fi].ins(e.se);
            c_obs[e.se].ins(e.fi);
        }

        std::map<int, std::set<int>> r_vis, c_vis;
        for (int u : Rv)
        {
            for (int v : Cv)
            {
                if (!obs_set.count({u, v}))
                {
                    r_vis[u].ins(v);
                    c_vis[v].ins(u);
                }
            }
        }

        if (!r_vis[xs].count(ys))
        {
            std::cout << -1 << '\n';
            continue;
        }

        std::queue<iii> q;
        q.push({{xs, ys}, 0});
        r_vis[xs].erase(ys);
        c_vis[ys].erase(xs);

        int ans = -1;
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int u = tmp.fi.fi, v = tmp.fi.se, d = tmp.se;
            if (u == xt && v == yt)
            {
                ans = d;
                break;
            }

            int L = -inf, R = inf;
            if (r_obs.count(u))
            {
                auto &s = r_obs[u];
                auto it = s.lower_bound(v);
                if (it != s.end())
                {
                    R = *it - 1;
                }
                if (it != s.begin())
                {
                    auto nit = it;
                    --nit;
                    L = *nit + 1;
                }
            }
            if (r_vis.count(u))
            {
                auto &s = r_vis[u];
                auto itL = s.lower_bound(L);
                auto itR = s.upper_bound(R);
                std::vector<int> vec(itL, itR);
                for (int y2 : vec)
                {
                    s.erase(y2);
                    c_vis[y2].erase(u);
                    q.push({{u, y2}, d + 1});
                }
                if (s.empty())
                {
                    r_vis.erase(u);
                }
            }

            L = -inf;
            R = inf;
            if (c_obs.count(v))
            {
                auto &s = c_obs[v];
                auto it = s.lower_bound(u);
                if (it != s.end())
                {
                    R = *it - 1;
                }
                if (it != s.begin())
                {
                    auto nit = it;
                    --nit;
                    L = *nit + 1;
                }
            }
            if (c_vis.count(v))
            {
                auto &s = c_vis[v];
                auto itL = s.lower_bound(L);
                auto itR = s.upper_bound(R);
                std::vector<int> vec(itL, itR);
                for (int x2 : vec)
                {
                    s.erase(x2);
                    r_vis[x2].erase(v);
                    q.push({{x2, v}, d + 1});
                }
                if (s.empty())
                {
                    c_vis.erase(v);
                }
            }
        }

        std::cout << ans << '\n';
    }
    return 0;
}