#include <bits/stdc++.h>
#define task "hprime"
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

int n, h;
std::vector<int> a;
bool f[maxn + 7];

int sumdigit(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void sieve()
{
    std::memset(f, 1, sizeof(f));
    f[0] = f[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (f[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                f[j] = 0;
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

    std::cin >> n >> h;
    sieve();

    for (int i = 1; i <= n; i++)
    {
        if (f[i] && sumdigit(i) == h)
        {
            a.pb(i);
        }
    }

    std::cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}
