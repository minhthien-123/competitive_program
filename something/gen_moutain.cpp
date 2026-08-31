#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

// số test
const ll test0 = 15;
const ll test1 = 30;
const ll test2 = 50;
// path
const std::string task = "C:\\c++\\moutain";

const ll maxn = 3e4 + 7;
std::pair<ll, ll> a[maxn];
ll n;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= test2; i++)
    {
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\moutain";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo


        // sinh test
        if (i <= test0)
        {
            n = rnd.next(1, 100);
            inp << n << "\n";
            for (int i = 1; i <= n; i++)
            {
                a[i].fi = rnd.next(1, 100);
                a[i].se = rnd.next(1, 100);
                inp << a[i].fi << " " << a[i].se << "\n";
            }
        }
        else if (i <= test1)
        {
            n = rnd.next(100, 1000);
            inp << n << "\n";
            for (int i = 1; i <= n; i++)
            {
                a[i].fi = rnd.next(100, 1000);
                a[i].se = rnd.next(100, 1000);
                inp << a[i].fi << " " << a[i].se << "\n";
            }
        }
        else
        {
            n = rnd.next(10000, 30000);
            inp << n << "\n";
            for (int i = 1; i <= n; i++)
            {
                a[i].fi = rnd.next(10000, 50000);
                a[i].se = rnd.next(10000, 50000);
                inp << a[i].fi << " " << a[i].se << "\n";
            }
        }

        // code full
        std::sort(a + 1, a + n + 1);
        ll s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
        {
            s1 = s1 + a[i].fi;
            s2 = std::max(s1 + a[i].se, s2 + a[i].se);
        }

        out << s2;

        inp.close();
        out.close();
    }
}