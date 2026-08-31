#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 10;
const ll test1 = 20;
const ll test2 = 20;
const std::string task = "C:\\c++\\train\\";



int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1 + test2); i++){
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        ll n, m, a, b;
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\train";

        if (i <= test0){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000); m = rnd.next(1, 1000); a = rnd.next(1, 1000); b = rnd.next(1, 1000);
            inp << n << " " << m << " " << a << " " << b;

            inp.close();
        }else if (i <= test1){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000000); m = rnd.next(1, 1000000); a = rnd.next(1, 1000000); b = rnd.next(1, 1000000);
            inp << n << " " << m << " " << a << " " << b;

            inp.close();
        }else{
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000000000); m = rnd.next(1, 1000000000); a = rnd.next(1, 1000000000); b = rnd.next(1, 1000000000);
            inp << n << " " << m << " " << a << " " << b;

            inp.close();
        }

        std::ofstream out(tmp + ".out");

        if (m * a <= b)
            out << n * a;
        else
            out << (n / m) * b + std::min((n % m) * a, b);

        out.close();
    }

    return 0;
}