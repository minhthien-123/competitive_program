#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 30;
const ll test1 = 50;
// path
const std::string task = "C:\\c++\\ptb2\\";

const int maxn = 3e3 + 7;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= test1; i++)
    {
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\ptb2";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        int n;
        int a[maxn];
        std::map<int, int> mp;

        // sinh test
        if (i <= test0)
        {
            n = rnd.next(3, 100);
        }
        else if (i <= test1)
        {
            n = rnd.next(100, 1000);
        }

        inp << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (i % 5 == 0)
            {
                a[i] = a[i - 7] + a[i - 3];
            }
            else
            {
                a[i] = rnd.next(1, 1000000);
            }
            //std::cout << a[i] << "\n";
            inp << a[i] << " ";
        }

        // code full
        for (int i = 1; i <= n; i++)
        {
            mp[a[i]]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    ans += mp[a[i] + a[j]];
                }
            }
        }

        std::cout << ans << "\n";

        out << ans;

        inp.close();
        out.close();
    }
}