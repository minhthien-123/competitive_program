#include <bits/stdc++.h>
#define task "fibonacci"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e18;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int f[2][2], m[2][2];

void fibo(int f1[2][2], int f2[2][2])
{
    int a = (f1[0][0] * f2[0][0] % mod + f1[0][1] * f2[1][0] % mod) % mod;
    int b = (f1[0][0] * f2[0][1] % mod + f1[0][1] * f2[1][1] % mod) % mod;
    int c = (f1[1][0] * f2[0][0] % mod + f1[1][1] * f2[1][0] % mod) % mod;
    int d = (f1[1][0] * f2[0][1] % mod + f1[1][1] * f2[1][1] % mod) % mod;
    f[0][0] = a;
    f[0][1] = b;
    f[1][0] = c;
    f[1][1] = d;
}

void power(int a[2][2], int n)
{
    if (n <= 1)
    {
        return;
    }
    power(a, n / 2);
    fibo(a, a);
    if (n % 2 != 0)
    {
        fibo(a, m);
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

    f[0][0] = f[0][1] = f[1][0] = 1;
    f[1][1] = 0;
    m[0][0] = m[0][1] = m[1][0] = 1;
    m[1][1] = 0;

    if (n == 0)
    {
        std::cout << 0;
    }
    else
    {
        power(f, n);
        std::cout << f[0][0];
    }

    return 0;
}
