#include <bits/stdc++.h>
#define task "count"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
int a[maxn + 7];
int f[6], vis[6];

void sub1()
{
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        std::unordered_map<int, int> d;
        memset(f, 0, sizeof f);
        for (int r = l; r <= n; r++)
        {
            int x = a[r];
            int pre = d[x];
            int cur = pre + 1;
            d[x] = cur;
            if (pre >= 1 && pre <= k)
            {
                f[pre]--;
            }
            if (cur >= 1 && cur <= k)
            {
                f[cur]++;
            }
            bool check = true;
            for (int p = 1; p <= k; p++)
            {
                if (f[p] <= 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                ans++;
            }
        }
    }

    std::cout << ans;
}

bool check()
{
    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= k; i++)
    {
        int x = f[i];
        if (x < 1 || x > k)
        {
            return false;
        }
        if (vis[x])
        {
            return false;
        }
        vis[x] = 1;
    }

    return true;
}

void sub2()
{
    int s = k * (k + 1) / 2;
    if (s > n)
    {
        std::cout << 0;
        exit(0);
    }
    for (int i = 1; i <= s; i++)
    {
        int x = a[i];
        f[x]++;
    }

    int ans = 0;
    if (check())
    {
        ans++;
    }

    for (int i = s + 1; i <= n; i++)
    {
        int l = a[i - s];
        int r = a[i];
        f[l]--;
        f[r]++;
        if (check())
        {
            ans++;
        }
    }

    std::cout << ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> k;
    bool check_sub2 = true;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] > k)
        {
            check_sub2 = false;
        }
    }

    if (n <= 1000)
    {
        sub1();
    }
    else if (check_sub2)
    {
        sub2();
    }
    else
    {

    }

    return 0;
}
