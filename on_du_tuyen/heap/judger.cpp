#include <bits/stdc++.h>
#define task "judger"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 1e6;

int n, m;
int a[maxn + 5];
bool f[maxn + 5];
std::set<ii> S;

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
        f[i] = true;
        S.insert({0, i});
    }

    while (m--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int i;
            std::cin >> i;
            if (!f[i])
            {
                f[i] = true;
                a[i] = 0;
                S.insert({a[i], i});
            }
        }
        else if (type == 2)
        {
            int i;
            std::cin >> i;
            if (f[i])
            {
                f[i] = false;
                S.erase({a[i], i});
            }
        }
        else if (type == 3)
        {
            int i, x;
            std::cin >> i >> x;
            if (f[i])
            {
                S.erase({a[i], i});
                a[i] += x;
                S.insert({a[i], i});
            }
        }
        else
        {
            if (S.empty())
            {
                std::cout << "EMPTY\n";
            }
            else
            {
                auto it = S.rbegin();
                int cnt = 0;
                while (it != S.rend() && cnt < 3)
                {
                    std::cout << it->fi << " ";
                    ++it;
                    ++cnt;
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}
