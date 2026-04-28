#include <bits/stdc++.h>
#define task "group"
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 2000000;
bool is_prime[maxn + 7];
int N;
int a[maxn + 7];
std::vector<ii> odd, even;
std::vector<int> adj[maxn + 7];
int f[maxn + 7];
bool flag[maxn + 7];
std::multiset<int, std::greater<int>> chan, le;

void sieve(int N)
{
    std::fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

bool dfs(int u, std::vector<int> &used)
{
    for (int v : adj[u])
    {
        if (used[v])
        {
            continue;
        }
        used[v] = 1;
        if (f[v] == 0 || dfs(f[v] - 1, used))
        {
            f[v] = u + 1;
            return true;
        }
    }
    return false;
}

void sub4()
{
    for (int i = 1; i <= N; i++)
    {
        if (a[i] & 1)
        {
            le.insert(a[i]);
        }
        else
        {
            chan.insert(a[i]);
        }
    }

    std::vector<ii> ans;

    for (auto i : chan)
    {
        for (auto j : le)
        {
            if (is_prime[i + j])
            {
                ans.pb(ii(i, j));
                auto it = le.find(j);
                if (it != le.end())
                    le.erase(it);
                break;
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (auto &p : ans)
    {
        std::cout << p.fi << " " << p.se << "\n";
    }
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
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> a[i];
        if (a[i] & 1)
        {
            odd.pb(ii(a[i], i));
        }
        else
        {
            even.pb(ii(a[i], i));
        }
    }
    if (N > 1000)
    {
        sieve(maxn);
        sub4();
        return 0;
    }
    int m = odd.size();
    int n = even.size();

    std::sort(odd.begin(), odd.end(), std::greater<ii>());
    std::sort(even.begin(), even.end(), std::greater<ii>());

    sieve(maxn);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (is_prime[odd[i].fi + even[j].fi])
            {
                adj[i].pb(j);
            }
        }
    }

    std::vector<ii> res;
    int dem = 0;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> used(n, 0);
        if (dfs(i, used))
        {
            dem++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (f[i] > 0)
        {
            int j = f[i] - 1;
            flag[odd[j].se] = 1;
            flag[even[i].se] = 1;
            // std::cout << odd[j].se << " " << even[i].se << "\n";
            // std::cout << a[odd[j].se] << " " << a[even[i].se] << "\n";
            res.pb(ii(odd[j].se, even[i].se));
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!flag[i])
        {
            if (a[i] == 1)
            {
                if (cnt != 0)
                {
                    // std::cout << cnt << " " << i << "\n";
                    // std::cout << a[cnt] << " " << a[i] << "\n";
                    res.pb(ii(cnt, i));
                    cnt = 0;
                }
                else
                {
                    cnt = i;
                }
            }
        }
    }

    std::cout << res.size() << "\n";
    for (const auto &p : res)
    {
        std::cout << p.fi << " " << p.se << "\n";
    }

    return 0;
}
