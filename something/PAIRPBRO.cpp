#include <bits/stdc++.h>
#define task "PAIRPBRO"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e7;

int n, k;
bool isPrime[maxn + 7];

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
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    sieve();

    std::cin >> n >> k;
    int cnt = 0;

    for (int i = 2; i + k <= n; i++)
    {
        if (isPrime[i] && isPrime[i + k])
        {
            cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}
