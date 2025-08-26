#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 15;
const ll test1 = 15;
const ll test2 = 20;
const std::string task = "C:\\c++\\pri\\";
const ll maxn = 1e5 + 7;

int main(ll argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1 + test2); i++){
        ll n, x;
        ll a[maxn], d[maxn];

        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\pri";

        if (i <= test0){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 100);
            inp << n << "\n";

            for (ll i = 1; i <= n; i++)
            {
                x = rnd.next(1, 100);  // Thêm phạm vi cho a[i]
                a[i] = x;
                inp << x << " ";
            }

            inp.close();
        }else if (i <= test1){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000);  // Thêm phạm vi cho n

            inp << n << "\n";

            for (ll i = 1; i <= n; i++)
            {
                x = rnd.next(1, 100000);  // Thêm phạm vi cho a[i]
                a[i] = x;
                inp << x << " ";
            }

            inp.close();
        }else if (i <= test2){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 100000);  // Thêm phạm vi cho n
            inp << n << "\n";

            for (ll i = 1; i <= n; i++)
            {
                x = rnd.next(1, 100000);  // Thêm phạm vi cho b[i]
                a[i] = x;
                inp << x << " ";
            }

            inp.close();
        }

        std::ofstream out(tmp + ".out");

        for (int i = 1; i <= n; i++){
            d[a[i]];
        }

        bool check = false;
        for (int i = maxn; i >= 1; i--){
            int cnt = 0;
            for (int j = i; j <= maxn; j += i)
                cnt += a[j];
            if (cnt > 1){
                if (!check)
                out << i;
                check = true;
            }
        }

        out.close();
    }

    return 0;
}