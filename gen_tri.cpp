#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 20;
const ll test1 = 30;
const std::string task = "C:\\c++\\tri\\";


int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1); i++){
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\tri";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        long double a, b, c, x, y;

        if (i <= test0){
            x = rnd.next(1, 1000);
            y = rnd.next(x, 1000);
        }else{
            x = rnd.next(1, 1000000) + rnd.next(1.99999);
            y = rnd.next(x, 1000000) + rnd.next(1.99999);
        }

        a = (x + y) - sqrt(2 * x * (x + y));
        b = y - a;
        c = sqrt(a * a + b * b);

        inp << std::fixed << std::setprecision(5) << x << " " << y;
        out << std::fixed << std::setprecision(5) << std::min(a, b) << " " << std::max(a, b) << " " << c;

        std::cout << std::fixed << std::setprecision(5) << x << " " << y << " " <<  std::min(a, b) << " " << std::max(a, b) << " " << " " << c << "\n";

        inp.close();
        out.close();
    }

    return 0;
}