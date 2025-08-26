#include "testlib.h"
#include <bits/stdc++.h>

bool check(int a, int b, int c, int d)
{
    if (a == c && (abs(b - d) == 1))
    {
        return true;
    }
    if (b == d && (abs(a - c) == 1))
    {
        return true;
    }

    return false;
}

const int maxn = 1e3 + 7;

int a[maxn][maxn];

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int res = ans.readInt();
    int kq = 0;
    int d = ouf.readInt(0, res);

    int n = inf.readInt();
    int m = inf.readInt();
    int x = inf.readInt();
    int y = inf.readInt();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = inf.readInt();
        }
    }

    int last_u = 0, last_v = 0;
    for (int i = 1; i <= d; i++)
    {
        int u = ouf.readInt(0, n);
        int v = ouf.readInt(0, m);

        //std::cout << u << " " << v << " ";
        //std::cout << a[u][v] << "\n";

        if (a[u][v] == 1)
        {
            quitf(_wa, "Ket qua sai");
        }

        if (i == 1)
        {
            if (u != x || v != y)
            {
                quitf(_wa, "Ket qua sai");
            }
        }
        else
        {
            if (!check(u, v, last_u, last_v))
            {
                quitf(_wa, "Ket qua sai");
            }
        }

        last_u = u;
        last_v = v;
        kq++;
    }

    //std::cout << kq << " " << res << "\n";
    //std::cout << last_u << " " << last_v << "\n";

    if (kq < res)
    {
        quitf(_wa, "Nha tham hiem chua thoat khoi me cung");
    }
    else if (kq > res)
    {
        quitf(_wa, "Duong di chua toi uu");
    }
    else
    {
        if (last_u != 1 && last_v != 1 && last_u != n && last_v != m)
        {
            quitf(_wa, "Nha tham hiem chua thoat khoi me cung");
        }
        else
        {
            quitf(_ok, "Ket qua dung");
        }
    }

    return 0;
}