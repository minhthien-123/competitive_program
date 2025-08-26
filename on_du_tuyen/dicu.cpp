#include <bits/stdc++.h>
#define task "dicu"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 10000000;
const int inf = (int)1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char huong[4] = {'^', '>', 'v', '<'};

int n, r, s;
std::vector<std::string> a;
int sx = -1, sy = -1, tx = -1, ty = -1;
static int d[maxn + 7];

auto idx(int i, int j)
{
    return i * s + j;
}

void bfs01(int st, int en)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
    }
    std::deque<int> dq;
    d[st] = 0;
    dq.push_front(st);
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        int x = u / s;
        int y = u % s;
        if (u == en)
        {
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= s)
            {
                continue;
            }
            int v = idx(nx, ny);
            int w;
            if (a[x][y] == 'o')
            {
                w = 0;
            }
            else
            {
                w = (a[x][y] != huong[k]);
            }

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (w == 1)
                {
                    dq.push_back(v);
                }
                else
                {
                    dq.push_front(v);
                }
            }
        }
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

    std::cin >> r >> s;
    for (int i = 0; i < r; i++)
    {
        std::string str;
        std::cin >> str;
        a.pb(str);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (a[i][j] == 'o')
            {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'x')
            {
                tx = i;
                ty = j;
            }
        }
    }

    n = r * s;

    int st = idx(sx, sy);
    int en = idx(tx, ty);

    bfs01(st, en);

    if (d[en] == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << d[en];
    }

    return 0;
}
