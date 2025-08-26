#include <bits/stdc++.h>
#define task "post"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 50;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n;
int a[maxn + 7][maxn + 7], d[maxn + 7][maxn + 7];
char f[maxn + 7][maxn + 7];
bool vis[maxn + 7][maxn + 7];
int sx, sy, cnt;
std::vector<ii> K;
std::vector<int> v;

bool check(int mn, int mx)
{
    if (a[sx][sy] < mn || a[sx][sy] > mx)
    {
        return false;
    }

    for (auto k : K)
    {
        int x = k.fi, y = k.se;
        if (a[x][y] < mn || a[x][y] > mx)
        {
            return false;
        }
    }

    memset(vis, false, sizeof vis);
    std::queue<ii> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    cnt = 0;
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        int x = tmp.fi;
        int y = tmp.se;

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny])
            {
                continue;
            }
            if (a[nx][ny] < mn || a[nx][ny] > mx)
            {
                continue;
            }
            vis[nx][ny] = true;
            if (f[nx][ny] == 'K')
            {
                cnt++;
                if (cnt == K.size())
                {
                    return true;
                }
            }
            q.push({nx, ny});
        }
    }

    return (cnt == K.size());
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
        for (int j = 1; j <= n; j++)
        {
            std::cin >> f[i][j];
            if (f[i][j] == 'P')
            {
                sx = i;
                sy = j;
            }
            if (f[i][j] == 'K')
            {
                K.pb({i, j});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            v.pb(a[i][j]);
        }
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    int ans = inf;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (check(v[i], v[j]))
            {
                ans = std::min(ans, v[j] - v[i]);
                //std::cout << v[i] << " " << v[j] << "\n";
            }
        }
    }

    std::cout << ans;

    return 0;
}
