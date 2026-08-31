#include <bits/stdc++.h>
#define task "sdb"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e7;

int t, a, b;
int isPrime[maxn + 7];
std::vector<int> primes, res;

void sieve()
{
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxn; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxn; i++)
    {
        if (isPrime[i] && i != 3)
        {
            primes.pb(i);
        }
    }
}

void init()
{
    sieve();
    for (int i : primes)
    {
        int tmp = 9 * i * i;
        if (tmp > maxn)
        {
            break;
        }
        res.pb(tmp);
    }
    res.pb(6561);

    std::sort(res.begin(), res.end());

    // for (int i : res)
    // {
    //     std::cout << i << "\n";
    // }
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

    init();

    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> b;

        std::cout << std::upper_bound(res.begin(), res.end(), b) - std::lower_bound(res.begin(), res.end(), a) << "\n";
    }
}