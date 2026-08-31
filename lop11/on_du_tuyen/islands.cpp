#include <bits/stdc++.h>
#define task "islands"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int m, n;
int sz[maxn + 7], par[maxn + 7];
std::vector<iii> vec;
bool flag[maxn + 7];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void make_set(int v)
{
    par[v] = v;
    sz[v] = 1;
    flag[v] = false;
}

int find_set(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
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

    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int h;
            std::cin >> h;
            vec.pb({h, {i, j}});
        }
    }

    std::sort(vec.begin(), vec.end(), std::greater<>());

    for (int i = 0; i < m * n; i++)
    {
        make_set(i);
    }

    int ans = 0, res = 0;
    int i = 0;
    while (i < m * n)
    {
        int h = vec[i].fi;
        int j = i;
        while (j < m * n && vec[j].fi == h)
        {
            int x = vec[j].se.fi;
            int y = vec[j].se.se;
            int id = x * n + y;
            flag[id] = true;
            res++;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < m && 0 <= ny && ny < n)
                {
                    int nid = nx * n + ny;
                    if (flag[nid] && union_sets(id, nid))
                    {
                        res--;
                    }
                }
            }
            j++;
        }
        ans = std::max(ans, res);
        i = j;
    }

    std::cout << ans;

    return 0;
}
