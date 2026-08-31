#include "testlib.h"
#include <bits/stdc++.h>
#define task "trip"
#define ll long long

const ll test1 = 31;
const ll test2 = 50;

void maketest1(int i){
    std::string tmp = task + std::to_string(i);
    std::ofstream inp(tmp + ".inp");
    ll n = rnd.next(1, 1000000), m = rnd.next(1, 1000000), a = rnd.next(1, 1000000), b = rnd.next(1, 1000000);
    inp << n << " " << m << " " << a << " " << b;
}

void maketest2(int i){
    std::string tmp = task + std::to_string(i);
    std::ofstream inp(tmp + ".inp");
    ll n = rnd.next(1, 1000000000), m = rnd.next(1, 1000000000), a = rnd.next(1, 1000000000), b = rnd.next(1, 1000000000);
    inp << n << " " << m << " " << a << " " << b;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    for (ll i = 1; i <= (test1 + test2); i++){
        if (i <= test1){
            maketest1(i);
        }else{
            maketest2(i);
        }
    }
}
