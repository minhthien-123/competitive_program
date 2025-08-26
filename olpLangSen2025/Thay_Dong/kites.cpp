#include <bits/stdc++.h>
#define task "kites"
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 45;
const int inf = 1e5;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct point2d
{
    long double x, y;
    point2d() {}
    point2d(long double x, long double y) : x(x), y(y) {}
    point2d operator+(point2d t)
    {
        return point2d(x + t.x, y + t.y);
    }
    point2d operator-(point2d t)
    {
        return point2d(x - t.x, y - t.y);
    }
    friend bool operator<(point2d x, point2d y)
    {
        return x.x < y.x || (x.x == y.x && x.y < y.y);
    }
    friend bool operator==(point2d x, point2d y)
    {
        return x.x == y.x && x.y == y.y;
    }
    point2d operator*(long double k) const { return point2d(x * k, y * k); }
    point2d operator/(long double k) const { return point2d(x / k, y / k); }
} c[maxn + 7], b[maxn + 7];

long double cross(point2d a, point2d b)
{
    return a.x * b.y - a.y * b.x;
}

long double dot(point2d a, point2d b)
{
    return a.x * b.x + a.y * b.y;
}

bool check(point2d a, point2d b, point2d c, point2d d)
{
    long double q = cross(b - a, c - a);
    long double w = cross(b - a, d - a);
    long double e = cross(d - c, a - c);
    long double r = cross(d - c, b - c);
    if (q == 0 || w == 0 || e == 0 || r == 0)
    {
        if (q == 0 && dot(a - c, b - c) <= 0)
            return true;
        if (w == 0 && dot(a - d, b - d) <= 0)
            return true;
        if (e == 0 && dot(c - a, d - a) <= 0)
            return true;
        if (r == 0 && dot(c - b, d - b) <= 0)
            return true;
        return false;
    }
    return (q * w < 0 && e * r < 0);
}

int add(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int mul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}

int dp[maxn + 7][maxn + 7][maxn + 7][maxn + 7];
int n;

bool cmp1(point2d x, point2d y)
{
    return x.x < y.x;
}

bool cmp2(point2d x, point2d y)
{
    if (x.x == y.x)
    {
        return x.y < y.y;
    }
    return x.x < y.x;
}

int dnc(int l, int r, int x, int y)
{
    if (l == r - 1)
    {
        return 1;
    }
    if (dp[l][r][x][y] != -1)
    {
        return dp[l][r][x][y] % mod;
    }
    dp[l][r][x][y] = 0;
    int lim = std::min(b[x].y, b[y].y);
    int top = -1, pos = -1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i].y <= lim)
        {
            if (check(c[l + 1], b[i], c[l], b[x]) || check(c[l + 1], b[i], c[r], b[y]))
            {
                continue;
            }
            cnt++;
            if (b[i].y > top)
            {
                top = b[i].y;
                pos = i;
            }
        }
    }

    if (pos == -1 || cnt != r - l - 1)
    {
        return 0;
    }
    for (int i = l + 1; i <= r - 1; i++)
    {
        dp[l][r][x][y] = add(dp[l][r][x][y], mul(dnc(l, i, x, pos), dnc(i, r, pos, y)));
    }
    //std::cout << dp[l][r][x][y] << "\n";
    return dp[l][r][x][y] % mod;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> c[i].x;
        c[i].y = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i].x >> b[i].y;
    }

    c[0].x = -inf;
    c[n + 1].x = inf;
    b[0].x = -inf;
    b[0].y = inf;
    b[n + 1].x = inf;
    b[n + 1].y = inf;
    std::sort(c + 1, c + n + 1, cmp1);
    std::sort(b + 1, b + n + 1, cmp2);

    std::memset(dp, -1, sizeof dp);

    std::cout << dnc(0, n + 1, 0, n + 1);

    return 0;
}
