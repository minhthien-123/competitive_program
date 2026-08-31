#include <bits/stdc++.h>
#define task "happy"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
bool isPrime[maxn];
int res[maxn], ans;

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        isPrime[i] = true;
    }

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

    std::cin >> n;

    int i = n;
    while (i > 0)
    {
        if (isPrime[i] || n % i == 0)
        {
            ans++;
            res[ans] = i;
        }
        i--;
    }

    std::cout << ans << "\n";
    for (int i = 1; i <= ans; i++)
    {
        std::cout << res[i] << " ";
    }

    return 0;
}
