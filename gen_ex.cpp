#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 25;
const ll test1 = 25;
const ll test2 = 25;
const ll test3 = 25;
const std::string task = "C:\\c++\\ex\\";
const ll maxn = 1e5 + 7;
const ll mod = 1e9;

long long power(long long x, long long y){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2);
    if (y % 2 == 0) return (tmp * tmp) % mod;
    else            return x * (tmp * tmp % mod) % mod;
}

int main(ll argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1 + test2 + test3); i++){
        ll n, x;
        ll a[maxn], b[maxn];

        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\ex";

        if (i <= test0){
            std::ofstream inp(tmp + ".inp");
            n = 1;
            a[1] = rnd.next(1, 100000); b[1] = rnd.next(1, 100000);

            inp << n << "\n";
            inp << a[1] << "\n" << b[1];

            inp.close();
        }else if (i <= test1){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 10000);  // Thêm phạm vi cho n

            inp << n << "\n";

            for (ll i = 1; i <= n; i++) {
                a[i] = rnd.next(1, 100);  // Gán giá trị cho a[i]
                inp << a[i] << " ";
            }
            inp << "\n";

            for (ll i = 1; i <= n; i++) {
                b[i] = rnd.next(1, 100);  // Gán giá trị cho b[i]
                inp << b[i] << " ";
            }

            inp.close();
        }else if (i <= test2){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 100000);  // Thêm phạm vi cho n
            inp << n << "\n";

            ll z = rnd.next(1, 100000);  // Chọn một giá trị ngẫu nhiên cho z
            a[1] = z;  // Gán giá trị cho a[1]
            for (ll i = 1; i <= n; i++) {
                a[i] = z;  // Giữ giá trị giống nhau cho tất cả a[i]
                inp << a[i] << " ";
            }
            inp << "\n";

            for (ll i = 1; i <= n; i++) {
                b[i] = rnd.next(1, 100000);  // Gán giá trị cho b[i]
                inp << b[i] << " ";
            }

            inp.close();
        }else{
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 100000);  // Thêm phạm vi cho n
            inp << n << "\n";

            for (ll i = 1; i <= n; i++) {
                x = rnd.next(1, 100000);  // Gán giá trị hợp lệ cho a[i]
                a[i] = x;
                inp << a[i] << " ";
            }
            inp << "\n";

            for (ll i = 1; i <= n; i++) {
                x = rnd.next(1, 100000);  // Gán giá trị hợp lệ cho b[i]
                b[i] = x;
                inp << b[i] << " ";
            }

            inp.close();
        }


        std::ofstream out(tmp + ".out");

        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + power(a[i], b[i])) % mod;
        }

        out << ans;

        out.close();
    }

    return 0;
}