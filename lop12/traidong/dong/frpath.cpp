#include <bits/stdc++.h>
#define task "frpath"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 1e6;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

struct Frac
{
    ll x, y;
    friend bool operator<(Frac a, Frac b)
    {
        return (__int128)a.x * b.y < (__int128)b.x * a.y;
    }
    friend bool operator==(Frac a, Frac b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

ll get_depth(Frac a)
{
    ll d = 0;
    while (a.x != a.y)
    {
        if (a.x > a.y)
        {
            ll steps = (a.x - 1) / a.y;
            d += steps;
            a.x -= steps * a.y;
        }
        else
        {
            ll steps = (a.y - 1) / a.x;
            d += steps;
            a.y -= steps * a.x;
        }
    }
    return d;
}

Frac get_lca(Frac a, Frac b)
{
    std::vector<std::pair<char, ll>> pathA, pathB;
    Frac cur = a;
    while (cur.x != cur.y)
    {
        if (cur.x > cur.y)
        {
            ll s = (cur.x - 1) / cur.y;
            pathA.pb({'R', s});
            cur.x -= s * cur.y;
        }
        else
        {
            ll s = (cur.y - 1) / cur.x;
            pathA.pb({'L', s});
            cur.y -= s * cur.x;
        }
    }
    cur = b;
    while (cur.x != cur.y)
    {
        if (cur.x > cur.y)
        {
            ll s = (cur.x - 1) / cur.y;
            pathB.pb({'R', s});
            cur.x -= s * cur.y;
        }
        else
        {
            ll s = (cur.y - 1) / cur.x;
            pathB.pb({'L', s});
            cur.y -= s * cur.x;
        }
    }

    ll lx = 0, ly = 1, rx = 1, ry = 0;
    int n = std::min(pathA.size(), pathB.size());
    for (int i = 0; i < n; i++)
    {
        if (pathA[i].fi != pathB[i].fi)
        {
            break;
        }
        ll steps = std::min(pathA[i].se, pathB[i].se);
        if (pathA[i].fi == 'R')
        {
            lx += steps * rx;
            ly += steps * ry;
        }
        else
        {
            rx += steps * lx;
            ry += steps * ly;
        }
        if (pathA[i].se != pathB[i].se)
        {
            break;
        }
    }
    return {lx + rx, ly + ry};
}

bool is_anc(Frac u, Frac v)
{
    return get_lca(u, v) == u;
}

int k;
std::pair<Frac, Frac> pairs[maxn + 7];
std::vector<Frac> vec;
ll depth[4 * maxn + 7];
int idx[4 * maxn + 7];
ll diff[4 * maxn + 7];
int par[4 * maxn + 7];

int get_idx(Frac f)
{
    return std::lower_bound(vec.begin(), vec.end(), f) - vec.begin();
}

void solve()
{
    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        ll x, y, u, v;
        std::cin >> x >> y >> u >> v;
        ll g1 = std::__gcd(x, y);
        ll g2 = std::__gcd(u, v);
        x /= g1;
        y /= g1;
        u /= g2;
        v /= g2;
        pairs[i] = {{x, y}, {u, v}};
        vec.pb(pairs[i].fi);
        vec.pb(pairs[i].se);
    }

    std::sort(all(vec));
    vec.erase(std::unique(all(vec)), vec.end());

    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        vec.pb(get_lca(vec[i - 1], vec[i]));
    }
    std::sort(all(vec));
    vec.erase(std::unique(all(vec)), vec.end());

    n = vec.size();
    for (int i = 0; i < n; i++)
    {
        depth[i] = get_depth(vec[i]);
        idx[i] = i;
        par[i] = -1;
        diff[i] = 0;
    }

    std::sort(idx, idx + n, [&](int i, int j)
              {
              if (i == j) return false;
              Frac l = get_lca(vec[i], vec[j]);
              if (l == vec[i])
              {
                  return true;
              }
              if (l == vec[j])
              {
                  return false;
              }
              return vec[i] < vec[j]; });

    std::vector<int> st;
    for (int i = 0; i < n; i++)
    {
        int u = idx[i];
        while (!st.empty() && !is_anc(vec[st.back()], vec[u]))
        {
            st.pop_back();
        }
        if (!st.empty())
        {
            par[u] = st.back();
        }
        st.push_back(u);
    }

    for (int i = 0; i < k; i++)
    {
        Frac A = pairs[i].fi;
        Frac B = pairs[i].se;
        Frac L = get_lca(A, B);
        diff[get_idx(A)] += 1;
        diff[get_idx(B)] += 1;
        diff[get_idx(L)] -= 2;
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int u = idx[i];
        if (par[u] != -1)
        {
            if (diff[u] > 0)
            {
                ans += depth[u] - depth[par[u]];
            }
            diff[par[u]] += diff[u];
        }
    }

    std::cout << ans;
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}