#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    std::string c = ans.readString();
    std::string v = ouf.readString();

    if (c != v && (c == "IMPOSSIBLE" || v == "IMPOSSIBLE"))
    {
        quitf(_wa, "Ket qua sai");
    }
    else if (c == v && c == "IMPOSSIBLE")
    {
        quitf(_ok, "Ket qua dung");
    }

    int n = inf.readInt(), m = inf.readInt();
    std::vector<int> a;
    a.push_back(0);
    for (int i = 0; i <= v.size(); i++)
    {
        if (v[i] == '1')
        {
            a.push_back(1);
        }
        else if (v[i] == '2')
        {
            a.push_back(2);
        }
    }

    bool check = true;

    for (int i = 1; i <= m; i++)
    {
        int x = inf.readInt(), y = inf.readInt();
        if (a[x] == a[y])
        {
            check = false;
        }
    }

    if (check)
    {
        quitf(_ok, "Ket qua dung");
    }
    else
    {
        quitf(_wa, "Ket qua sai");
    }
}