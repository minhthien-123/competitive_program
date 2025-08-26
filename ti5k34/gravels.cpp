#include <bits/stdc++.h>
#define task "gravels"
#define int __int128
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

std::istream &operator>>(std::istream &in, __int128 &x)
{
    long long t;
    in >> t;
    x = t;
    return in;
}
std::ostream &operator<<(std::ostream &out, const __int128 &x)
{
    if (x == 0)
    {
        out << '0';
        return out;
    }
    __int128 t = x;
    if (t < 0)
    {
        out << '-';
        t = -t;
    }
    char buf[40];
    int len = 0;
    while (t > 0)
    {
        buf[len++] = char('0' + t % 10);
        t /= 10;
    }
    while (len--)
        out << buf[len];
    return out;
}

const long long maxn = 1000000;
const int inf = (__int128)1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];

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
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        s += a[i];
    }

    int m = s / n;
    int ans = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp += a[i] - m;
        ans += (tmp < 0 ? -tmp : tmp);
    }

    std::cout << ans;
    return 0;
}
