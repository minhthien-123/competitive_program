#include <bits/stdc++.h>
#define task "table"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 400;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int m, n;
int a[maxn + 7][maxn + 7];
std::vector<int> v;
int maxval = -inf;

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

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            v.pb(a[i][j]);
            if (a[i][j] > maxval)
            {
                maxval = a[i][j];
            }
        }
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        std::vector<std::unordered_set<int>> colset(n + 7);
        std::vector<std::vector<int>> col(n + 7);
        std::vector<bool> check(n + 7, 0);

        for (int j = i; j <= m; j++)
        {
            int h = j - i + 1;
            for (int k = 1; k <= n; k++)
            {
                if (check[k])
                {
                    continue;
                }

                int val = a[j][k];
                if (colset[k].count(val))
                {
                    check[k] = 1;
                    colset[k].clear();
                    col[k].clear();
                }
                else
                {
                    colset[k].ins(val);
                    col[k].pb(val);
                }
            }

            std::vector<int> d(maxval + 5, 0);
            int k = 1;
            while (k <= n)
            {
                while (k <= n && check[k])
                {
                    k++;
                }
                if (k >= (n + 1))
                {
                    break;
                }

                int L = k;
                while (k <= n && !check[k])
                {
                    k++;
                }
                int R = k - 1;

                int l = L;
                for (int r = L; r <= R; r++)
                {
                    bool flag = false;

                    for (int val : col[r])
                    {
                        if (d[val] > 0)
                        {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag)
                    {
                        for (int val : col[r])
                        {
                            d[val]++;
                        }
                    }
                    else
                    {
                        while (true)
                        {
                            for (int val : col[l])
                            {
                                d[val]--;
                            }
                            l++;
                            flag = false;
                            for (int val : col[r])
                            {
                                if (d[val] > 0)
                                {
                                    flag = true;
                                    break;
                                }
                            }
                            if (!flag)
                            {
                                for (int val : col[r])
                                {
                                    d[val]++;
                                }
                                break;
                            }
                        }
                    }

                    int w = r - l + 1;
                    ans = std::max(ans, h * w);
                }
                for (int t = L; t <= R; t++)
                {
                    for (int val : col[t])
                    {
                        d[val] = 0;
                    }
                }
            }
        }
    }

    std::cout << ans;

    return 0;
}
