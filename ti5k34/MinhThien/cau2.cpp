#include <bits/stdc++.h>
#define task "cau2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int n, k;
int a[maxn + 7];
std::unordered_map<int, int> mp;

void sub1()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] + a[j] == k)
            {
                cnt++;
            }
        }
    }

    std::cout << cnt;
}

void sub2()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += mp[k - a[i]];
        mp[a[i]]++;
    }
    std::cout << cnt;
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    if (n <= 1000)
    {
        sub1();
    }
    else
    {
        sub2();
    }

    return 0;
}
