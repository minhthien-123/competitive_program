#include "testlib.h"
#include <bits/stdc++.h>

const int maxn = 1e3 + 7;
int a[maxn][maxn];

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();

    int res = ans.readInt() + 1;
    int d = ouf.readInt(-1, res) + 1;

    for (int i = 1; i <= m; i++)
    {
        int u = inf.readInt();
        int v = inf.readInt();

        a[u][v] = 1;
    }

    int last_x = 1;
    for (int i = 1; i <= d; i++)
    {
        int x = ouf.readInt();
        if (i == 1)
        {
            if (x != 1)
            {
                quitf(_wa, "Ket qua sai");
            }
        }
        else
        {
            if (x == last_x)
            {
                quitf(_wa, "Ket qua sai");
            }

            if (a[last_x][x] == 0)
            {
                quitf(_wa, "ket qua sai");
            }
        }

        last_x = x;
    }

    int robot1 = last_x;
    last_x = n;

    for (int i = 1; i <= d; i++)
    {
        int x = ouf.readInt();
        if (i == 1)
        {
            if (x != n)
            {
                quitf(_wa, "Ket qua sai");
            }
        }
        else
        {
            if (x == last_x)
            {
                quitf(_wa, "Ket qua sai");
            }

            if (a[last_x][x] == 0)
            {
                quitf(_wa, "ket qua sai");
            }
        }

        last_x = x;
    }

    int robot2 = last_x;

    if (robot1 != robot2 || d < res)
    {
        quitf(_wa, "Hai robot chua gap nhau");
    }
    else
    {
        if (d > res)
        {
            quitf(_wa, "Duong di chua toi uu");
        }
        else
        {
            quitf(_ok, "Ket qua dung");
        }
    }
}