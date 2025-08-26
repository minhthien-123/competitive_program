#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 35;
const ll test1 = 15;
// path
const std::string task = "C:\\c++\\aplusb\\";


int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1); i++)
    {
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\aplusb";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        ll a = rnd.next(1, 1000000000);
        ll b = rnd.next(1, 1000000000);
        inp << a << " " << b << "\n";

        out << a + b << "\n";

        // code full


        inp.close();
        out.close();
    }
}