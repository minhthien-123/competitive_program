#include <bits/stdc++.h>
#define task "cau1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e7;
const int inf  = 1e18;

bool isPrime[maxn];

int dx(int n){
    int val = 0;
    while (n > 0) {
        val = val * 10 + n % 10;
        n /= 10;
    }
    return val;
}

bool check(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

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

int a, b;

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

    std::cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (i == dx(i))
        {
            if (i <= maxn)
            {
                if (isPrime[i])
                {
                    cnt++;
                }
            }
            else
            {
                if (check(i))
                {
                    cnt++;
                }
            }
        }
    }

    std::cout << cnt;

    return 0;
}
