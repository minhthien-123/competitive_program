#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long
#define ld long double

// số test
const ll test0 = 20;
const ll test1 = 40;
const ll test2 = 50;
// path
const std::string task = "C:\\c++\\avm\\";

const int maxn = 1e5 + 7;

int n, k;
ld f[maxn], a[maxn];

bool check(ld x)
{
    memset(f, 0, sizeof(f));
    ld mn = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + (a[i] - x);
        if (i >= k)
        {
            if (f[i] - mn >= 0) return true;
            mn = std::min(mn, f[i - k + 1]);
        }
    }

    return false;
}


int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= test2; i++)
    {
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\avm";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo


        // sinh test
        if (i <= test0)
        {
            n = rnd.next(1, 100);
            k = rnd.next(1, n);

            for (int i = 1; i <= n; i++)
            {
                a[i] = rnd.next(1, 1000);
            }
        }
        else if (i <= test1)
        {
            n = rnd.next(101, 1000);
            k = rnd.next(1, n);

            for (int i = 1; i <= n; i++)
            {
                a[i] = rnd.next(1, 1000000);
            }
        }
        else
        {
            n = rnd.next(80000, 100000);
            k = rnd.next(1, n);

            for (int i = 1; i <= n; i++)
            {
                a[i] = rnd.next(1, 1000000);
            }
        }

        inp << n << " " << k << "\n";
        for (int i = 1; i <= n; i++)
        {
            inp << a[i] << " ";
        }

        // code full

        ld l = 0, r = 1e9;
        int cnt = 0;
        while (cnt < 100)
        {
            ld mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
            cnt++;
        }

        out << std::fixed << std::setprecision(2) << (l + r) / 2;

        inp.close();
        out.close();
    }
}