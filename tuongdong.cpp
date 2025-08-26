#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int minprime[maxn];
std::vector<int> factor[maxn];
std::map<std::vector<int>, int> mp;
int l, r, ans = 0;

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (minprime[i] == 0)
        {
            for (int j = i; j <= maxn; j += i)
            {
                if (minprime[j] == 0)
                {
                    minprime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= maxn; i++)
    {
        int x = i;
        while (x > 1)
        {
            factor[i].pb(minprime[x]);
            x /= minprime[x];
        }
        std::sort(factor[i].begin(), factor[i].end());
        factor[i].erase(unique(factor[i].begin(), factor[i].end()), factor[i].end());
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

    std::cin >> l >> r;

    sieve();

    for (int i = l; i <= r; i++)
    {
        ans += mp[factor[i]];
        mp[factor[i]]++;
    }

    std::cout << ans;

    return 0;
}
