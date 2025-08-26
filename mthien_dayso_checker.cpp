#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int k = inf.readInt();
    int a[n + 7];
    for (int i = 1; i <= n; i++)
    {
        a[i] = inf.readInt();
    }

    int l = ouf.readInt(0, n);
    int r = ouf.readInt(0, n);

    int l1 = ans.readInt();
    int r1 = ans.readInt();

    if (l < 0 || r < 0 || l > n || r > n)
    {
        quitf(_wa, "Ket qua dung");
    }

    if (l == 0 && r == 0)
    {
        if (l1 == 0 && r1 == 0)
        {
            quitf(_ok, "Ket qua dung");
        }
        else
        {
            quitf(_wa, "Ket qua sai");
        }
    }

    if (abs(a[l] - a[r]) == abs(k))
    {
        quitf(_ok, "Ket qua dung");
    }
    else
    {
        quitf(_wa, "Ket qua sai");
    }
}
