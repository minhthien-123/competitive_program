#include <bits/stdc++.h>
#define task ""
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const ll inf = 1e18;
const int mod = 998244353;
const int inv = (mod + 1) / 2;
const int lg = 20;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

std::vector<int> adj[maxn + 7];
int n, mx;
std::map<int, int> mp;
bool flag = true;

ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}
_Thiendeptrai_
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
        std::cin >> x;
        mp[x]++;
        mx = std::max(mx, x);
        if (i == 1 && x != 0 || i != 1 && x == 0)
        {
            flag = false;
        }
    }

    if (flag)
    {
        int ans = 1;
        for (int i = 1; i <= mx; i++)
        {
            ans = mul(ans, power(mp[i - 1], mp[i]));
        }
        std::cout << ans;
    }
    else
    {
        std::cout << 0;
    }

    return 0;
}
