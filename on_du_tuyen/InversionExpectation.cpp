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

const int maxn = 2e5;
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

std::vector<int> adj[maxn + 7];
int n;
int a[maxn + 7];
ll bit[maxn + 7];
bool flag[maxn + 7];
int f[maxn + 7];
ll ans = 0;
int cnt = 0;

void update(int id, ll val)
{
    for (; id <= n; id += id & -id)
    {
        bit[id] += val;
    }
}
int get(int id)
{
    ll sum = 0;
    for (; id >= 1; id -= id & -id)
    {
        sum += bit[id];
    }
    return sum;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] != -1)
        {
            flag[a[i]] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + !flag[i];
    }

    int m = f[n];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            int pre = get(a[i]);
            ans = add(ans, cnt - pre);
            update(a[i], 1);
            cnt++;
        }
    }

    // std::cout << ans << "\n";

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    /*for (int j = i + 1; j <= n; j++)
    {
    if (a[i] != -1 && a[j] == -1)
    {
        int cnt = f[a[i] - 1];
        ans = add(ans, mul(cnt, power(m, mod - 2)));
    }
    if (a[i] == -1 && a[j] != -1)
    {
        int cnt = m - f[a[j]];
        ans = add(ans, mul(cnt, power(m, mod - 2)));
    }*/
    {
        if (a[i] == -1)
        {
            cnt++;
        }
        else
        {
            if (m > 0)
            {

                int cnt1 = f[a[i] - 1];
                int cnt2 = m - f[a[i]];
                int d1 = cnt;
                int d2 = m - cnt;
                ans = add(ans, mul(cnt1, mul(d2, power(m, mod - 2))));
                ans = add(ans, mul(cnt2, mul(d1, power(m, mod - 2))));
            }
        }
    }

    // std::cout << ans << "\n";

    if (m > 0)
    {
        ans = add(ans, mul(m, mul(m - 1, power(4, mod - 2))));
    }

    std::cout << ans;

    return 0;
}
