#include <bits/stdc++.h>
#define task "iaptap"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int t;
int n, m;
int a[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7], c[maxn + 7][maxn + 7];
int cnt[maxn + 7];
bool ok[maxn + 7][maxn + 7];

struct swaptap
{
    int l, r, u, v;
};

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

    std::cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof cnt);
        memset(f, 0, sizeof f);
        memset(ok, 0, sizeof ok);
        std::cin >> m >> n;
        std::set<iii> s;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cin >> a[i][j];
                c[i][j] = a[i][j];
                cnt[a[i][j]]++;
            }
        }

        std::multiset<ii> mts;
        for (int j = 1; j <= n; j++)
        {
            mts.ins(ii(cnt[j], j));
        }

        for (int j = 1; j <= n; j++)
        {
            auto tmp = *mts.begin();
            int x = tmp.fi, val = tmp.se;
            if (x >= m)
            {
                mts.erase(mts.find(tmp));
                if (x - m != 0)
                {
                    mts.ins({x - m, val});
                }
                for (int i = 1; i <= m; i++)
                {
                    f[i][j] = val;
                }
            }
            else
            {
                for (int i = 1; i <= x; i++)
                {
                    f[i][j] = val;
                }

                mts.erase(mts.find(tmp));
                tmp = *mts.rbegin();
                int y = tmp.fi, color2 = tmp.se, cur = m - x;

                for (int i = x + 1; i <= m; i++)
                {
                    f[i][j] = color2;
                }
                mts.erase(mts.find(tmp));
                mts.insert({y - cur, color2});
            }
        }

        std::vector<swaptap> ans;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (f[i][j] == a[i][j])
                {
                    ok[i][j] = 1;
                }
                else
                {
                    ok[i][j] = 1;
                    bool flag = false;
                    for (int p = 1; p <= m; p++)
                    {
                        if (flag)
                            break;
                        for (int q = 1; q <= n; q++)
                        {
                            if (p == i && q == j)
                                continue;
                            if (!ok[p][q] && a[p][q] == f[i][j])
                            {

                                std::swap(a[p][q], a[i][j]);
                                ans.pb({i, j, p, q});
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        std::cout << ans.size() << "\n";
        for (auto e : ans)
        {
            std::cout << e.l << " " << e.r << " " << e.u << " " << e.v << "\n";
            std::swap(c[e.l][e.r], c[e.u][e.v]);
        }
    }

    return 0;
}
