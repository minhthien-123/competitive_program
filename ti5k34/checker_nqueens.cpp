#include <bits/stdc++.h>
#define task "nqueens"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 80;
const int inf  = 1e18;

int n;
char a[maxn + 7][maxn + 7];

bool check(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[x][i] == 'Q' && i != y)
        {
            //chk << "1\n";
            return false;
        }
        if (a[i][y] == 'Q' && i != x)
        {
            //chk << "2\n";
            return false;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (x + i <= n && y + i <= n && a[x + i][y + i] == 'Q')
        {
            //chk << "3\n";
            return false;
        }
        if (x - i >= 1 && y - i >= 1 && a[x - i][y - i] == 'Q')
        {
            //chk << "4\n";
            return false;
        }
        if (x + i <= n && y - i >= 1 && a[x + i][y - i] == 'Q')
        {
            //chk << "5\n";
            return false;
        }
        if (x - i >= 1 && y + i <= n && a[x - i][y + i] == 'Q')
        {
            //chk << "6\n";
            return false;
        }
    }

    return true;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::ifstream inp(task".inp");
    std::ifstream out(task".out");
    std::ofstream chk(task".chk");

    inp >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = '.';
        }
    }
    //system("nqueens.exe");
    std::string s;
    out >> s;
    if (n == 2 || n == 3)
    {
        if (s == "YES")
        {
            chk << "WRONG ANSWER\n";
            return 0;
        }
        else
        {
            chk << "ACCEPTED\n";
            return 0;
        }
    }
    else
    {
        if (s == "NO")
        {
            chk << "WRONG ANSWER\n";
            return 0;
        }
    }

    int cnt = 0;
    int x, y;
    while (out >> x >> y)
    {
        if (x < 1 || y < 1 || x > n || y > n)
        {
            chk << "WRONG ANSWER\n";
            return 0;
        }
        a[x][y] = 'Q';
        cnt++;
    }

    if (cnt != n)
    {
        chk << "WRONG ANSWER\n";
        return 0;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         chk << a[i][j];
    //     }
    //     chk << "\n";
    // }

    // chk << "HEHE\n";
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'Q')
            {
                if (!check(i, j))
                {
                    flag = false;
                    break;
                }
            }
        }
    }

    if (flag)
    {
        chk << "ACCEPTED\n";
    }
    else
    {
        chk << "WRONG ANSWER\n";
    }

    return 0;
}
