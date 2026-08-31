#include <bits/stdc++.h>
#define task "rf"
#define int long long
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 2e3;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x % mod * (y % mod)) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

std::vector<int> adj[maxn + 7];
int m, n;
int a[maxn + 7], b[maxn + 8];

struct BigNum
{
    std::vector<int> d;

    BigNum() {}
    BigNum(long long v)
    {
        if (v == 0)
            d.push_back(0);
        while (v > 0)
        {
            d.push_back(v % 10);
            v /= 10;
        }
    }
    BigNum(std::string s)
    {
        if (s.empty())
        {
            d.push_back(0);
            return;
        }
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            d.push_back(s[i] - '0');
        }
        trim();
    }

    void trim()
    {
        while (d.size() > 1 && d.back() == 0)
            d.pop_back();
    }

    friend std::istream &operator>>(std::istream &is, BigNum &b)
    {
        std::string s;
        is >> s;
        b = BigNum(s);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BigNum &b)
    {
        if (b.d.empty())
            os << 0;
        for (int i = (int)b.d.size() - 1; i >= 0; i--)
            os << b.d[i];
        return os;
    }

    bool operator<(const BigNum &b) const
    {
        if (d.size() != b.d.size())
            return d.size() < b.d.size();
        for (int i = (int)d.size() - 1; i >= 0; i--)
        {
            if (d[i] != b.d[i])
                return d[i] < b.d[i];
        }
        return false;
    }
    bool operator>(const BigNum &b) const { return b < *this; }
    bool operator==(const BigNum &b) const { return !(*this < b) && !(b < *this); }
    bool operator<=(const BigNum &b) const { return *this < b || *this == b; }
    bool operator>=(const BigNum &b) const { return *this > b || *this == b; }

    BigNum operator+(const BigNum &b) const
    {
        BigNum res;
        int carry = 0;
        for (int i = 0; i < std::max(d.size(), b.d.size()) || carry; i++)
        {
            int sum = carry;
            if (i < d.size())
                sum += d[i];
            if (i < b.d.size())
                sum += b.d[i];
            res.d.push_back(sum % 10);
            carry = sum / 10;
        }
        return res;
    }

    BigNum operator-(const BigNum &b) const
    {
        BigNum res;
        int borrow = 0;
        for (int i = 0; i < d.size(); i++)
        {
            int sub = d[i] - borrow - (i < b.d.size() ? b.d[i] : 0);
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            res.d.push_back(sub);
        }
        res.trim();
        return res;
    }

    BigNum operator*(const BigNum &b) const
    {
        BigNum res;
        if ((d.size() == 1 && d[0] == 0) || (b.d.size() == 1 && b.d[0] == 0))
            return BigNum(0);
        res.d.assign(d.size() + b.d.size(), 0);
        for (int i = 0; i < d.size(); i++)
        {
            int carry = 0;
            for (int j = 0; j < b.d.size() || carry; j++)
            {
                long long cur = res.d[i + j] + d[i] * 1LL * (j < b.d.size() ? b.d[j] : 0) + carry;
                res.d[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        res.trim();
        return res;
    }
};

void solve()
{
    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        std::cin >> b[j];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == 1)
            {
                break;
            }
            if (b[j] == 1)
            {
                continue;
            }

            ll gcd = std::__gcd(a[i], b[j]);
            if (gcd > 1)
            {
                a[i] /= gcd;
                b[j] /= gcd;
            }
        }
    }

    BigNum P(1);
    for (int i = 1; i <= m; i++)
    {
        if (a[i] > 1)
        {
            P = P * BigNum(a[i]);
        }
    }

    BigNum Q(1);
    for (int j = 1; j <= n; j++)
    {
        if (b[j] > 1)
        {
            Q = Q * BigNum(b[j]);
        }
    }

    std::cout << P << "\n" << Q;
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}