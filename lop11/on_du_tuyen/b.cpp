#include <bits/stdc++.h>
#define task "b"
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

std::string s;
int nxt[maxn + 7][20];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> s;
    int n = s.size();

    for (int i = 0; i < 10; i++)
    {
        nxt[n][i] = -1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - '0'] = i;
    }

    std::queue<std::pair<std::string, int>> q;

    for (int i = 1; i < 10; i++)
    {
        int idx = nxt[0][i];
        std::string str = std::to_string(i);
        if (idx == -1)
        {
            std::cout << str;
            exit(0);
        }
        else
        {
            q.push({str, idx + 1});
        }
    }

    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        std::string str = tmp.fi;
        int pos = tmp.se;

        for (int i = 0; i < 10; i++)
        {
            int idx = nxt[pos][i];
            std::string nstr = str + char('0' + i);
            if (idx == -1)
            {
                std::cout << nstr;
                exit(0);
            }
            else
            {
                q.push({nstr, idx + 1});
            }
        }
    }

    return 0;
}
