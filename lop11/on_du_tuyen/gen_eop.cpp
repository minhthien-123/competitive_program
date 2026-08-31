#include <bits/stdc++.h>
#include "testlib.h"
#define int long long
const std::string task = "C:\\c++\\train\\";
const int test = 16;

std::mt19937_64 rd_gen(std::chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd_gen() % (r - l + 1);
}

signed main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= test; iTest++)
    {
        std::string tmp = task;
        if (iTest < 10) tmp += "0";
        tmp = tmp + std::to_string(iTest);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\train";

        int n;
        if (iTest <= 16)
            n = Rand(1, 1000);
        else
            n = Rand(100000, 1000000);

        std::ofstream inp(tmp + ".inp");
        inp << n << "\n";
        std::string a;
        a.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int tmp = Rand(1, 9);
            a.push_back(char('0' + tmp));
            inp << tmp;
        }
        inp.close();

        int e = 0, o = 0;
        for (char c : a)
        {
            if ((c - '0') % 2 == 0) e++;
            else                    o++;
        }

        int cnt = 0;
        for (char c : a)
        {
            if ((c - '0') % 2 == 0)
            {
                e--;
                cnt += o;
            }
            else
            {
                o--;
                cnt += e;
            }
        }

        std::ofstream out(tmp + ".out");
        out << cnt;
        out.close();
    }
    return 0;
}
