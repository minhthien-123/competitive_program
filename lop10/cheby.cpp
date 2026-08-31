#include <bits/stdc++.h>
#define task "cheby"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int t;
int isPrime[maxn + 7];

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        isPrime[i] = 1;
    }

    for (int i = 2; i * i <= maxn; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = 1; i <= maxn; i++)
    {
        isPrime[i] += isPrime[i - 1];
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

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << isPrime[2 * n] - isPrime[n] << '\n';
    }

    return 0;
}
