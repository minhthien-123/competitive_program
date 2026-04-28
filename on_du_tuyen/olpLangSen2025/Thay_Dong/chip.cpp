#include <bits/stdc++.h>
#define task "chip"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 32;
const int mxx = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int m, n, k;
char c[maxn + 7][maxn + 7];
int pref[maxn + 7][maxn + 7];

struct HopcroftKarp
{
#define FOR(i, a, b) for (int i = a; i <= b; i++)
    int nx, ny, E;
    static const int M = mxx + 7;
    int adj[M], nxt[M], last[M];
    int matx[M], maty[M], que[M], level[M], run[M];

    void init(int _nx, int _ny)
    {
        nx = _nx;
        ny = _ny;
        E = 0;
        FOR(i, 1, nx)
        matx[i] = -1, last[i] = -1;
        FOR(i, 1, ny)
        maty[i] = -1;
    }

    void add(int x, int y)
    {
        adj[E] = y;
        nxt[E] = last[x];
        last[x] = E++;
    }

    bool bfs()
    {
        bool found = false;
        int qs = 0, qe = 0;
        FOR(x, 1, nx)
        {
            if (matx[x] == -1)
            {
                level[x] = 0;
                que[qe++] = x;
            }
            else
            {
                level[x] = -1;
            }
        }
        while (qs < qe)
        {
            int x = que[qs++];
            for (int e = last[x]; e != -1; e = nxt[e])
            {
                int y = adj[e];
                if (maty[y] == -1)
                {
                    found = true;
                }
                else if (level[maty[y]] == -1)
                {
                    level[maty[y]] = level[x] + 1;
                    que[qe++] = maty[y];
                }
            }
        }
        return found;
    }

    int dfs(int x)
    {
        for (int &e = run[x]; e != -1; e = nxt[e])
        {
            int y = adj[e];
            if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y])))
            {
                maty[y] = x;
                matx[x] = y;
                return 1;
            }
        }
        return 0;
    }

    int maxMatching()
    {
        int total = 0;
        while (bfs())
        {
            FOR(x, 1, nx)
            run[x] = last[x];
            FOR(x, 1, nx)
            if (matx[x] == -1)
                total += dfs(x);
        }
        return total;
    }
} hopkarp;

inline bool inside(int i, int j, int I, int J, int len)
{
    return (i >= I && i < I + len && j >= J && j < J + len);
}

bool check(int len, std::vector<iii> &vec)
{
    static int f_den[maxn + 7][maxn + 7], f_trang[maxn + 7][maxn + 7];
    for (int I = 1; I + len - 1 <= m; I++)
    {
        for (int J = 1; J + len - 1 <= n; J++)
        {
            int sum = pref[I + len - 1][J + len - 1] - pref[I - 1][J + len - 1] - pref[I + len - 1][J - 1] + pref[I - 1][J - 1];
            if (sum != len * len)
                continue;

            memset(f_den, -1, sizeof(f_den));
            memset(f_trang, -1, sizeof(f_trang));
            int cnt_den = 0, cnt_trang = 0;
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    if (c[i][j] == '.' && !inside(i, j, I, J, len))
                    {
                        if ((i + j) % 2 == 0)
                        {
                            f_den[i][j] = ++cnt_den;
                        }
                        else
                        {
                            f_trang[i][j] = ++cnt_trang;
                        }
                    }

            hopkarp.init(cnt_den, cnt_trang);
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (f_den[i][j] != -1)
                    {
                        int u = f_den[i][j];
                        for (int d = 0; d < 4; d++)
                        {
                            int ni = i + dx[d], nj = j + dy[d];
                            if (ni >= 1 && ni <= m && nj >= 1 && nj <= n && f_trang[ni][nj] != -1)
                            {
                                hopkarp.add(u, f_trang[ni][nj]);
                            }
                        }
                    }
                }
            }

            if (hopkarp.maxMatching() >= k)
            {
                vec.clear();
                for (int i = 1; i <= m && (int)vec.size() < k; i++)
                {
                    for (int j = 1; j <= n && (int)vec.size() < k; j++)
                    {
                        if (f_den[i][j] != -1)
                        {
                            int u = f_den[i][j];
                            int v = hopkarp.matx[u];
                            if (v != -1)
                            {
                                for (int d = 0; d < 4; d++)
                                {
                                    int ni = i + dx[d], nj = j + dy[d];
                                    if (ni >= 1 && ni <= m && nj >= 1 && nj <= n && f_trang[ni][nj] == v)
                                    {
                                        int huong;
                                        if (d < 2)
                                        {
                                            huong = 2;
                                        }
                                        else
                                        {
                                            huong = 1;
                                        }
                                        int x = i, y = j;
                                        if (huong == 1 && nj < j)
                                        {
                                            y = nj;
                                        }
                                        if (huong == 2 && ni < i)
                                        {
                                            x = ni;
                                        }
                                        vec.pb({{x, y}, huong});
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> c[i][j];
            pref[i][j] = (c[i][j] == '.') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    int l = 1, r = std::min(m, n), res = 0;
    std::vector<iii> ans, tmp;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, tmp))
        {
            res = mid;
            ans = tmp;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    // std::cout << res << "\n";
    for (auto &p : ans)
    {
        std::cout << p.fi.fi << " " << p.fi.se << " " << p.se << "\n";
    }
    return 0;
}