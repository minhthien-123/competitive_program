#include <bits/stdc++.h>
#define task "sumarr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7], f[maxn + 7];
int ans[maxn + 7];

int add(int x , int y)
{
    return (x + y) % mod;
}

int mul(int x, int y)
{
    return (x * y) % mod;
}

void sub1()
{
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }

    for (int u = 0; u < n; u++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i | j) <= u)
                {
                    sum = add(sum, mul(a[i], a[j]));
                }
            }
        }
        ans[u] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << ' ';
    }
}

void sub2()
{
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = i | j;
            ans[u] = add(ans[u], mul(a[i], a[j]));
        }
    }

    for (int i = 1; i < n; i++)
    {
        ans[i] += ans[i - 1];
        ans[i] %= mod;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
}

void sub3()
{
    for (int i = 0; i < n; i++)
    {
        f[i] = a[i];
    }
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

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    if (n <= 500)
    {
        sub1();
    }
    else
    {
        sub2();
    }

    return 0;
}