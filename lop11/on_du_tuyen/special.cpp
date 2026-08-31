#include <bits/stdc++.h>
#define task "special"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1000000;
int q;
bool prime[maxn + 1];
std::vector<int> primes;

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (!prime[i])
        {
            primes.pb(i);
            if (i * i <= maxn)
            {
                for (int j = i * i; j <= maxn; j += i)
                {
                    prime[j] = true;
                }
            }
        }
    }
}

void solve(int n, std::map<int, int> &fac)
{
    for (int p : primes)
    {
        if (p * p > n)
        {
            break;
        }
        while (n % p == 0)
        {
            fac[p]++;
            n /= p;
        }
    }
    if (n > 1)
    {
        int k = sqrtl(n);
        if (k * k == n)
        {
            fac[k] += 2;
        }
        else
        {
            fac[n]++;
        }
    }
}

void gen(const std::vector<ii> &f, int i, int cur, std::vector<int> &v)
{
    if (i == f.size())
    {
        v.pb(cur);
        return;
    }
    int p = f[i].fi, e = f[i].se;
    for (int k = 0; k <= e; k++)
    {
        gen(f, i + 1, cur, v);
        cur *= p;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    sieve();

    std::cin >> q;
    while (q--)
    {
        int n;
        std::cin >> n;

        std::map<int, int> fac;
        solve(n, fac);

        std::vector<ii> f(fac.begin(), fac.end());
        std::vector<int> divs;
        gen(f, 0, 1, divs);

        std::vector<int> ans;
        for (int d : divs)
        {
            if (d > 0 && n % (d + 1) == 0)
            {
                ans.pb(d);
            }
        }

        std::sort(ans.begin(), ans.end());
        if (ans.empty())
        {
            std::cout << "-1\n";
        }
        else
        {
            for (int x : ans)
            {
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
