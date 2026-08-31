#include <bits/stdc++.h>
#define task "cmpr"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const ll inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;
const int lg   = 20;

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
int n, q;
int prime[maxn + 7];
int cnt[maxn + 7];
std::vector<int> primes;

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (prime[i] == 0)
        {
            prime[i] = i;
            primes.pb(i);
        }
        for (int p : primes)
        {
            ll v = 1LL * p * i;
            if (v > maxn)
            {
                break;
            }
            prime[v] = p;
            if (p == prime[i])
            {
                break;
            }
        }
    }
}

_Thiendeptrai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    sieve();

    std::cin >> n >> q;

    int upto = std::min(n, maxn);
    for (int i = 2; i <= upto; i++)
    {
        cnt[prime[i]]++;
    }

    while (q--)
    {
        ll x;
        std::cin >> x;

        if (x > n)
        {
            std::cout << 0;
        }
        else
        {
            std::cout << cnt[x];
        }

        std::cout << "\n";
    }

    return 0;
}
