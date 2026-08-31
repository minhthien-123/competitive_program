#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 16;
const ll test1 = 4;
const std::string task = "C:\\c++\\eop\\";

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (ll iTest = 1; iTest <= (test0 + test1); iTest++)
    {
        std::string tmp = task;
        if (iTest < 10)
            tmp += "0";
        tmp = tmp + std::to_string(iTest);
        ll n;
        std::string a;
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\eop";
        std::ofstream inp(tmp + ".inp");

        if (iTest <= test0)
        {
            n = rnd.next(1, 1000);
            inp << n << "\n";
            for (ll i = 1; i <= n; i++)
            {
                ll tmp = rnd.next(1, 9);
                inp << tmp;
                a.push_back(char(tmp + '0'));
            }
        }
        else
        {
            n = rnd.next(10000, 1000000);
            inp << n << "\n";
            for (ll i = 1; i <= n; i++)
            {
                ll tmp = rnd.next(1, 9);
                inp << tmp;
                a.push_back(char(tmp + '0'));
            }
        }


        inp.close();

        ll e = 0, o = 0;
        for (char c : a)
        {
            if ((c - '0') % 2 == 0) e++;
            else                    o++;
        }

        ll cnt = 0;
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