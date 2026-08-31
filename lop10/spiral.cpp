#include <bits/stdc++.h>
#define task "spiral"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100;

int n, m;
int a[maxn][maxn];

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
    int x = 1, y = m, z = 1, c2 = n;
    int cnt = 1;

    while (x <= y && z <= c2)
    {
        for (int i = z; i <= c2; i++)
        {
            a[x][i] = cnt;
            cnt++;
        }
        x++;

        for (int i = x; i <= y; i++)
        {
            a[i][c2] = cnt;
            cnt++;
        }
        c2--;

        if (x <= y)
        {
            for (int i = c2; i >= z; i--)
            {
                a[y][i] = cnt;
                cnt++;
            }
            y--;
        }

        if (z <= c2)
        {
            for (int i = y; i >= x; i--)
            {
                a[i][z] = cnt;
                cnt++;
            }
            z++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
