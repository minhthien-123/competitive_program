#include <bits/stdc++.h>
#define task "ucln2"
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}

int n, q;
int a[maxn + 7];
std::vector<int> divs[maxn + 7];
ll sum[maxn + 7];
ll ans;

void sieve()
{
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = i; j <= maxn; j += i)
        {
            divs[j].push_back(i);
        }
    }
}

void add_val(int x)
{
    for (int i : divs[x])
    {
        ll tmp1 = sum[i];
        ll tmp2 = x / i;
        ans = add(ans, tmp1 * tmp2 % mod);
        sum[i] += tmp2;
    }
}

void erase_val(int x)
{
    for (int i : divs[x])
    {
        ll tmp2 = x / i;
        sum[i] -= tmp2;
        ll tmp1 = sum[i];
        ans = sub(ans, tmp1 * tmp2 % mod);
    }
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

    sieve();

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        add_val(a[i]);
    }

    std::cout << ans << "\n";

    while (q--)
    {
        int i, x;
        std::cin >> i >> x;
        erase_val(a[i]);
        a[i] = x;
        add_val(a[i]);
        std::cout << ans << "\n";
    }

    return 0;
}
