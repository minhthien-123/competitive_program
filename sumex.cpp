#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int mod = 1e9;

int n;
int a[maxn], b[maxn];

int sub3()
{
    int d[maxn];
    d[1] = a[1];
    for (int i = 2; i <= maxn; i++)
    {
        d[i] = d[i - 1] * a[1] % mod;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + d[b[i]]) % mod;
    }

    return ans;
}

long long power(long long x, long long y){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2);
    if (y % 2 == 0) return (tmp * tmp) % mod;
    else            return x * (tmp * tmp % mod) % mod;
}

int sub4()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + power(a[i], b[i])) % mod;
    }

    return ans;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    bool check = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            check = false;
        }
    }

    if (check)
    {
        std::cout << sub3();
    }
    else
    {
        std::cout << sub4();
    }

    return 0;
}
