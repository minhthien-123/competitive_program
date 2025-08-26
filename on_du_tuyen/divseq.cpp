#include <bits/stdc++.h>
#define task "divseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, s = 0;
int a[3 * maxn + 7];
int pre[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
int ans[maxn + 7];
bool used[maxn + 7];
std::vector<ii> vec;

void gen(int pos, int cnt, int flag, int sum)
{
    if (cnt == n)
    {
        vec.pb({flag, sum});
        return;
    }

    if (pos > m)
    {
        return;
    }

    gen(pos + 1, cnt + 1, flag | (1LL << (pos - 1)), sum + a[pos]);
    gen(pos + 1, cnt, flag, sum);
}

void sub1()
{
    vec.clear();
    gen(1, 0, 0, 0);
    std::vector<int> tmp;
    for (auto i : vec)
    {
        if (i.se == s)
        {
            tmp.pb(i.fi);
        }
    }

    bool check = false;
    for (int i = 0; i < tmp.size() && !check; i++)
    {
        for (int j = i + 1; j < tmp.size() && !check; j++)
        {
            if ((tmp[i] & tmp[j]) == 0)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (tmp[i] & (1LL << (k - 1)))
                    {
                        std::cout << 1;
                    }
                    else if (tmp[j] & (1LL << (k - 1)))
                    {
                        std::cout << 2;
                    }
                    else
                    {
                        std::cout << 3;
                    }
                }
                check = true;
            }
        }
    }
    std::cout << '\n';
}

std::vector<int> find(std::vector<int> v)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            pre[i][j] = f[i][j] = -1;
        }
    }

    pre[0][0] = -2;

    for (int i = 0; i < v.size(); i++)
    {
        int val = a[v[i]];
        for (int j = n - 1; j >= 0; j--)
        {
            for (int k = s - val; k >= 0; k--)
            {
                if (pre[j][k] != -1 && pre[j + 1][k + val] == -1)
                {
                    pre[j + 1][k + val] = i;
                    f[j + 1][k + val] = k;
                }
            }
        }
    }

    std::vector<int> res;
    int trace = n, sum = s;
    while (trace > 0)
    {
        int pos = pre[trace][sum];
        res.pb(v[pos]);
        sum = f[trace][sum];
        trace--;
    }

    return res;
}

void sub2()
{
    std::vector<int> id;
    for (int i = 1; i <= m; i++)
    {
        id.pb(i);
    }
    memset(ans, 0, sizeof ans);
    std::vector<int> s1 = find(id);
    memset(used, false, sizeof used);
    for (int i : s1)
    {
        used[i] = true;
    }
    id.clear();
    for (int i = 1; i <= m; i++)
    {
        if (!used[i])
        {
            id.pb(i);
        }
    }
    std::vector<int> s2 = find(id);
    for (int i : s1)
    {
        ans[i] = 1;
    }
    for (int i : s2)
    {
        ans[i] = 2;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = 3;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        std::cout << ans[i];
    }
    std::cout << "\n";
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

    int t;
    std::cin >> t;
    while (t--)
    {

        std::cin >> n;
        m = 3 * n;
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            std::cin >> a[i];
            sum += a[i];
        }
        s = (sum / 3);

        if (n <= 7)
        {
            sub1();
        }
        else
        {
            sub2();
        }
    }

    return 0;
}