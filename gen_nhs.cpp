#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 60;
const ll test1 = 40;
// path
const std::string task = "C:\\c++\\nhs\\" ;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll j = 1; j <= (test0 + test1); j++)
    {
        std::string tmp = task;
        if (j < 10) tmp += "0";
        tmp = tmp + std::to_string(j);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\nhs";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        ll n;

        // sinh test
        if (j <= test0)
        {
            n = rnd.next(1, 1000000);
        }
        else if (j <= test1)
        {
            n = rnd.next(1, 1000000000);
        }

        inp << n;

        // code full

        out << 18 * n;


        inp.close();
        out.close();
    }
}