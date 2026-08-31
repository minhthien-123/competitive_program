#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define str string
#define pu push
#define pb push_back
#define pii pair<long long, long long>
#define all(a) a.begin(), a.end()
#define piii pair<long long, pii>
#define __MaCodVN__ signed main()
#define task "EXCHANGE"

const ll N = 1e5 + 9;
const ll mod = 1e9 + 7;
const int AC = 0;

using namespace std;
ll n, tt, p;
map<ll, ll> d;

struct pt
{
    ll w;
    ll cost;
    ll val_type;
};

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

void solve()
{
    cin >> n >> p;
    ll res = 0;
    d.clear();
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        d[x]++;
        res += x;
    }
    vector<pt> items;
    for (auto x : d)
    {
        ll v = x.fi;
        ll c = x.se;
        if (v == 0)
            continue;
        ll cnt = c - 1;
        ll k = 1;
        while (cnt > 0)
        {
            ll take = min(cnt, k);
            items.pb({take * v, 0, v});
            cnt -= take;
            k *= 2;
        }
        items.pb({v, 1, v});
    }
    ll ma = res + 1;
    vector<ll> dp(ma, 1e9);
    dp[0] = 0;
    ll K_items = items.size();
    vector<vector<bool>> taken(K_items, vector<bool>(ma, false));
    for (ll i = 0; i < K_items; i++)
    {
        ll w_item = items[i].w;
        ll c_item = items[i].cost;
        for (ll w = ma - 1; w >= w_item; w--)
        {
            if (dp[w - w_item] + c_item < dp[w])
            {
                dp[w] = dp[w - w_item] + c_item;
                taken[i][w] = true;
            }
        }
    }
    ll min_cost = 1e9;
    ll best_S = -1;
    for (ll w = p; w < ma; w++)
    {
        if (dp[w] < min_cost)
        {
            min_cost = dp[w];
            best_S = w;
        }
    }
    ll D = d.size() - min_cost;
    cout << D << " " << best_S << "\n";
    vector<ll> s;
    ll curr_w = best_S;
    for (ll i = K_items - 1; i >= 0; i--)
    {
        if (taken[i][curr_w])
        {
            ll w_item = items[i].w;
            ll val = items[i].val_type;
            ll cnt = w_item / val;
            for (ll k = 0; k < cnt; k++)
                s.pb(val);
            curr_w -= w_item;
        }
    }
    sort(all(s));
    for (auto x : s)
        cout << x << " ";
    cout << "\n";
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
