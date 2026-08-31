#include <bits/stdc++.h>
#define task "hexgame"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;
const std::string base = "1238004765";

int a[10][10] = {{0, 1, 5, 8, 7, 3}, {1, 2, 6, 9, 8, 4}};
std::string s;


signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    for (int i = 1; i <= 10; i++)
    {
        char c;
        std::cin >> c;
        s += c;
    }

    if (s == base)
    {
        std::cout << 0;
        return 0;
    }

    std::unordered_map<std::string, int> d;

    std::queue<std::string> q;

    d[s] = 0;
    q.push(s);

    while (q.size())
    {
        std::string tmp = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            std::string str = tmp;
            char c = str[a[i][5]];

            for (int j = 5; j > 0; j--)
            {
                str[a[i][j]] = str[a[i][j - 1]];
            }
            str[a[i][0]] = c;

            if (d[str] == 0)
            {
                d[str] = d[tmp] + 1;
                if (str == base)
                {
                    std::cout << d[str];
                    return 0;
                }

                q.push(str);
            }
        }
    }

    return 0;
}
