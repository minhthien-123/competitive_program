#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define str string
#define pu push
#define pb push_back
#define pii pair<long long, long long>
#define all(a) a.beign(), a.end()
#define piii pair<long long, pii>
#define __MaCodVN__ signed main()
#define task "HoanDoiDoan"

const ll N = 2e5 + 9;
const ll mxN = 1e6 + 9;
const ll mod = 1e9 + 7;
const int AC = 0;

using namespace std;
ll n, tt, q, r[N][21], ma[N], mi[N];

ll mul(ll x, ll y)
{
    return (x % mod * y % mod) % mod;
}

ll add(ll x, ll y)
{
    return (x % mod + y % mod) % mod;
}

ll sub(ll x, ll y)
{
    return ((x % mod - y % mod) + mod) % mod;
}

bool get_bit(ll n, ll mask)
{
    return (n & (1 << mask));
}

ll get(ll u, ll k)
{
    if (r[u][k] == u)
        return u;
    return r[u][k] = get(r[u][k], k);
}

void join(ll u, ll v, ll k)
{
    u = get(u, k);
    v = get(v, k);
    if (u != v)
    {
        if (k == 0)
        {
            ma[v] = max(ma[v], ma[u]);
            mi[v] = min(mi[v], mi[u]);
        }
        r[u][k] = v;
    }
}

void down(ll u, ll v, ll k)
{
    if (r[u][k] != r[v][k])
    {
        join(u, v, k);
        if (k > 0)
        {
            down(u, v, k - 1);
            down(u + (1 << (k - 1)), v + (1 << (k - 1)), k - 1);
        }
    }
}

void solve()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j <= 19; j++)
        {
            r[i][j] = i;
            ma[i] = i;
            mi[i] = i;
        }
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 2)
        {
            ll l, r, len;
            cin >> l >> r >> len;
            int k = 31 - __builtin_clz(len);
            down(l, r, k);
            down(l + len - (1 << k), r + len - (1 << k), k);
        }
        else
        {
            ll x;
            cin >> x;
            ll ans_mi = x, ans_ma = x;
            ll x2 = get(x, 0);
            cout << mi[x2] << " " << ma[x2] << '\n';
        }
    }
}

__MaCodVN__
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(task ".INP", "r"))
    {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
    tt = 1;
    while (tt--)
        solve();
    return AC;
}