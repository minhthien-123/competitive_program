#include <bits/stdc++.h>
#define task "divcnt"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;

int f[maxn + 7];
int divcnt[maxn + 7];

std::vector<int> sieve(int n)
{
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int a, b;
    std::cin >> a >> b;

    int x = sqrt(b);
    std::vector<int> primes = sieve(x);

    int n = b - a + 1;
    for (int i = 0; i < n; i++)
    {
        divcnt[i] = 1;
        f[i] = a + i;
    }

    for (int p : primes)
    {
        int tmp = ((a + p - 1) / p) * p;
        if (tmp > b)
            continue;
        for (int m = tmp; m <= b; m += p)
        {
            int cur = m - a;
            if (f[cur] % p != 0)
                continue;
            int e = 0;
            while (f[cur] % p == 0)
            {
                e++;
                f[cur] /= p;
            }
            divcnt[cur] *= (e + 1);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (f[i] > 1)
        {
            divcnt[i] *= 2;
        }
    }

    int q = 0, k = a, t = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = a + i;
        if (divcnt[i] > q)
        {
            q = divcnt[i];
            k = x;
            t = 1;
        }
        else if (divcnt[i] == q)
        {
            if (x < k)
                k = x;
            t++;
        }
    }

    std::cout << q << " " << k << " " << t;

    return 0;
}