#include <bits/stdc++.h>
#define task "equa"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;

int a, b, c, d, n, mod;
std::ofstream eans("equa.ans");
int ans = 0;

typedef std::vector<int> vi;


/*
std::ostream &operator<<(std::ostream &cout, const vi &a)
{
    for (auto d : a)
        cout << d;

    return cout;
}

void del_zero(vi &a)
{
    reverse(a.begin(), a.end());

    while (a.size() >= 2)
        if (a.back() == 0)
            a.pop_back();
            else
            break;

    reverse(a.begin(), a.end());
}

vi int_to_vi(int n)
{
    vi res;
    if (n == 0)
    {
        res.push_back(n);
        return res;
    }

    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }

    return res;
}

vi operator*(vi a, vi b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < (int)a.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j)
        {
            c[i + j] += (a[i] * b[j]);
            c[i + j + 1] += (c[i + j] / 10);
            c[i + j] %= 10;
        }

    c.push_back(0);
    for (int i = 0; i < (int)c.size() - 1; ++i)
    {
        c[i + 1] += (c[i] / 10);
        c[i] %= 10;
    }

    reverse(c.begin(), c.end());
    del_zero(c);

    return c;
}
*/

void sub_trau()
{
    int cnt = 0;
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            for (int z = 0; z <= n; z++)
            {
                for (int t = 0; t <= n; t++)
                {
                    if (a * x + b * y + c * z + d * t == n)
                    {
                        cnt++;
                        cnt %= mod;
                    }
                }
            }
        }
    }

    eans << cnt << "\n";
}

int f(int x)
{
    return ((x * (x + 1) * (2 * x + 1)) / 6) % mod;
}

int f1(int x)
{
    return ((x * (x + 1) / 2) % mod);
}

int f2(int x)
{
    return ((x * (x + 1) % mod * (x + 2) % mod) / 3) % mod;
}

void solve()
{
    int x, y;
    if (n % 2 == 0)
    {
        x = n / 2 + 1;
        int ans = (((n + 1) * x % mod) * x % mod - 2 * f(x - 1) % mod + mod) % mod;
        std::cout << ans;
    }
    else
    {
        x = (n + 1) / 2;
        int ans = (2 * (((n + 1) * f1(x) % mod - f2(x - 1) % mod + mod) % mod)) % mod;
        std::cout << ans;
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
    //     std::freopen(task ".out", "w", stdout);
    }

    std::cin >> a >> b >> c >> d >> n >> mod;

    //solve();
    // std::cout << ans;
    sub_trau();

    return 0;
}
