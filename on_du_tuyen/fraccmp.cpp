#include <bits/stdc++.h>
#define task "fraccmp"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int t;
const int bs = 1000000000;
typedef std::vector<int> BigInt;

void Set(BigInt &a)
{
    while (a.size() > 1 && a.back() == 0)
    {
        a.pop_back();
    }
}

BigInt Int(const std::string &s_in)
{
    std::string s = s_in;
    while (s.size() % 9)
        s = '0' + s;
    BigInt a;
    for (int i = 0; i < (int)s.size(); i += 9)
    {
        int block = 0;
        for (int j = i; j < i + 9; j++)
        {
            block = block * 10 + (s[j] - '0');
        }
        a.insert(a.begin(), block);
    }
    Set(a);
    return a;
}

void Print(const BigInt &a)
{
    BigInt b = a;
    Set(b);
    if (b.empty())
    {
        std::cout << 0;
        return;
    }
    std::cout << b.back();
    char buf[16];
    for (int i = (int)b.size() - 2; i >= 0; i--)
    {
        // pad with leading zeros
        std::snprintf(buf, sizeof(buf), "%09d", b[i]);
        std::cout << buf;
    }
}

BigInt operator+(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    int n = std::max(a.size(), b.size());
    for (int i = 0; i < n; i++)
    {
        if (i < (int)a.size())
            carry += a[i];
        if (i < (int)b.size())
            carry += b[i];
        ans.pb(carry % bs);
        carry /= bs;
    }
    if (carry)
        ans.pb(carry);
    Set(ans);
    return ans;
}

BigInt operator-(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        long long cur = (long long)a[i] - carry - (i < (int)b.size() ? b[i] : 0);
        if (cur < 0)
        {
            cur += bs;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans.pb((int)cur);
    }
    Set(ans);
    return ans;
}

bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}

BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt ans(a.size() + b.size(), 0);
    for (int i = 0; i < (int)a.size(); i++)
    {
        long long carry = 0;
        for (int j = 0; j < (int)b.size() || carry; j++)
        {
            long long cur = ans[i + j] + carry + (long long)a[i] * (j < (int)b.size() ? b[j] : 0);
            ans[i + j] = (int)(cur % bs);
            carry = cur / bs;
        }
    }
    Set(ans);
    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        BigInt a, b, c, d;
        std::string sx, sy, sz, st;
        std::cin >> sx >> sy >> sz >> st;
        a = Int(sx);
        b = Int(sy);
        c = Int(sz);
        d = Int(st);

        BigInt x = a * d;
        BigInt y = c * b;

        if (x > y)
        {
            std::cout << 1;
        }
        else if (x < y)
        {
            std::cout << -1;
        }
        else
        {
            std::cout << 0;
        }

        std::cout << '\n';
    }
    return 0;
}
