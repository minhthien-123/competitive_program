#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 8;
const ll test1 = 2;
// path
const std::string task = "C:\\c++\\baso\\" ;

signed main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll z = 1; z <= (test0 + test1); z++)
    {
        std::string tmp = task;
        if (z < 10) tmp += "0";
        tmp = tmp + std::to_string(z);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\baso";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        ll n;

        // sinh test
        if (z <= test0)
        {
            n = rnd.next(1, 100);
        }
        else if (z <= (test0 + test1))
        {
            n = rnd.next(100, 1000000000);
        }

        std::cout << n << "\n";

        inp << n;

        // code full
        ll ans = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i + 1; j * j * i <= n; j++)
            {
                int x = n / i / j;
                x -= j;
                if (x > 0)
                {
                    ans += 6 * x;
                }
            }
        }

        for (int i = 1; i * i <= n; i++)
        {
            int x = n / i / i;
            if (x >= i)
            {
                x--;
            }
            ans += x * 3;
        }

        for (int i = 1; i * i * i <= n; i++)
        {
            ans ++;
        }

        out << ans;

        inp.close();
        out.close();
    }
}