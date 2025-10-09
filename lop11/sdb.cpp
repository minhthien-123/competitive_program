#include <bits/stdc++.h>
#define task "sdb"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int maxn = 1000000;
const ll inf = (ll)1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;
const int lg = 20;

ll add(ll x, ll y)
{
    return (x + y + 2LL * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2LL * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
        return (tmp * tmp) % mod;
    else
        return ((tmp * tmp) % mod) * x % mod;
}

std::vector<ll> f;
std::vector<char> isprime;

void sieve()
{
    isprime.assign(maxn + 7, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= maxn; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isprime[j] = false;
            }
        }
    }

    for (int i = 2; i <= maxn; i++)
    {
        if (isprime[i])
        {
            f.push_back((ll)i * (ll)i);
        }
    }
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    sieve();

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        std::cin >> x;
        auto it = std::lower_bound(f.begin(), f.end(), x);
        std::cout << *it << " ";
    }
    std::cout << '\n';

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
