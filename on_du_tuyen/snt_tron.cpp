#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
bool prime[maxn + 7];

void sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                prime[j] = false;
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

    std::cin >> n;

    sieve();

    int ans = 0;

    for (int i = 2; i < n; i++)
    {
        if (!prime[i])
        {
            continue;
        }

        int k = 0, tmp = i;
        while (tmp)
        {
            tmp /= 10;
            k++;
        }
        int p = 1;
        for (int j = 1; j < k; j++)
        {
            p *= 10;
        }

        bool check = true;
        tmp = i;
        for (int j = 1; j <= k; j++)
        {
            //std::cout << tmp << " ";
            if (!prime[tmp])
            {
                check = false;
                break;
            }

            tmp = (tmp % p) * 10 + tmp / p;
        }
        if (check)
        {
            ans++;
        }
        //std::cout << "\n";
    }

    std::cout << ans;

    return 0;
}
