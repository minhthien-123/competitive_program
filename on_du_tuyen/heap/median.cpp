#include <bits/stdc++.h>
#define task "median"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m, N;
int a[maxn + 7], f[maxn + 7];
std::multiset<int> l, r;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    int N = 2 * n + 1;
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
        f[i] = a[i];
    }

    std::sort(f, f + N);

    for (int i = 0; i <= n; i++)
    {
        l.ins(f[i]);
    }

    for (int i = n + 1; i < N; i++)
    {
        r.ins(f[i]);
    }

    while (m--)
    {
        int i, k;
        std::cin >> i >> k;

        int tmp = a[i];
        int x = *l.rbegin();

        if (tmp <= x)
        {
            l.erase(l.find(tmp));
        }
        else
        {
            r.erase(r.find(tmp));
        }

        if (k <= x)
        {
            l.ins(k);
        }
        else
        {
            r.ins(k);
        }

        if (l.size() > r.size() + 1)
        {
            r.ins(*l.rbegin());
            l.erase(*l.rbegin());
        }
        else if (l.size() < r.size() + 1)
        {
            l.ins(*r.begin());
            r.erase(r.begin());
        }

        a[i] = k;
        std::cout << *l.rbegin() << "\n";
    }

    return 0;
}
