#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int k = inf.readInt();

    int a[n + 7], f[n + 7];
    for (int i = 1; i <= n; i++)
    {
        a[i] = inf.readInt();
    }

    int res = ans.readInt();
    if (ouf.seekEof()) {
        quitf(_fail, "Ket qua sai");
    }

    int resu = ouf.readInt();
    for (int i = 1; i <= n; i++)
    {
        if (ouf.seekEof()) {
           quitf(_fail, "Ket qua sai");
        }
        f[i] = ouf.readInt();
    }

    if (!ouf.seekEof()) {
        quitf(_fail, "Ket qua sai");
    }

    if (res != resu)
    {
        quitf(_wa, "Ket qua sai");
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += f[i] * a[i];
        }

        //std::cout << sum << " " << res << "\n";

        if (sum != res)
        {
            quitf(_wa, "Ket qua sai");
        }
        else
        {
            quitf(_ok, "Ket qua dung");
        }
    }
}