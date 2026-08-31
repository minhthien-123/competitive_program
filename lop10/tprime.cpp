#include <bits/stdc++.h>
#define task "tprime"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e4;
  
int n;
bool isprime[maxn];
std::vector<int> primes;

void sieve()
{
    memset(isprime, true, sizeof isprime);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= maxn; ++i)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
                isprime[j] = false;
        }
    }

    for (int i = 2; i <= maxn; ++i)
        if (isprime[i])
            primes.push_back(i);
}

bool check(int x)
{
    bool res = true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res = false;
            break;
        }
    }

    return res;
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

    int cnt = 0;
    for (int i = 0; i * i + 4 <= n; i++)
    {
        if (isprime[i])
        {
            int j = i * i + 4;
            if (j <= maxn)
            {
                if (isprime[j])
                {
                    //std::cout << 2 << " " << i << " " << j << std::endl;
                    cnt++;
                }
            }
            else
            {
                if (check(j))
                {
                    //std::cout << 2 << " " << i << " " << j << std::endl;
                    cnt++;
                }
            }
        }
    }

    std::cout << cnt;

    return 0;
}