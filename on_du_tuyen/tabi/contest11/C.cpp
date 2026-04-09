#include <bits/stdc++.h>
#define task "KEVIN"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int maxn = 2e5 + 5;
const ll inf = 1e18;
const int mod = 1e9 + 7;

int a[maxn];
int b[maxn];

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> cnt;
    ll sum_a = 0, sum_b = 0;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        cnt[a[i]]++;
        sum_a += a[i];
    }

    std::priority_queue<int> pq;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> b[i];
        pq.push(b[i]);
        sum_b += b[i];
    }

    if (sum_a != sum_b)
    {
        std::cout << "No\n";
        return;
    }

    while (!pq.empty())
    {
        if (sz(pq) > n)
        {
            std::cout << "No\n";
            return;
        }

        int u = pq.top();
        pq.pop();

        if (cnt[u] > 0)
        {
            cnt[u]--;
        }
        else
        {
            if (u == 1)
            {
                std::cout << "No\n";
                return;
            }
            pq.push(u / 2);
            pq.push((u + 1) / 2);
        }
    }

    std::cout << "Yes\n";
}

__Thien_dep_trai__
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
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
