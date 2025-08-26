#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 10;
const ll test2 = 20;
const ll test1 = 20;
const std::string task = "C:\\c++\\sbp\\";

int cp(int x)
{
    if (sqrt(x) * sqrt(x) == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(int x, int n)
{
    if (cp(x) && x % n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sub1(int n)
{
    int ans = n * n;
    while (!check(ans, n))
    {
        ans--;
    }
    return ans;
}

int sub2(int n)
{
    return (n - 1) * (n - 1);
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= (test0 + test1); i++){
        ll n;
        std::string tmp = task;
        if (i < 10) tmp += "0";
        tmp = tmp + std::to_string(i);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\sbp";

        if (i <= test0){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 100);
            inp << n;

            inp.close();
        }else if (i <= test1){
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000);
            inp << n;

            inp.close();
        }else{
            std::ofstream inp(tmp + ".inp");
            n = rnd.next(1, 1000000000);
            inp << n;

            inp.close();
        }

        std::ofstream out(tmp + ".out");

        out << sub2(n);

        out.close();
    }

    return 0;
}