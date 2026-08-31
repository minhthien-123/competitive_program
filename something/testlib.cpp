#include <bits/stdc++.h>
#include "testlib.h"
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int main(int argc, char* argv[]){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    registerGen(argc, argv, 1);
    registerTestlibCmd(argc, argv);

    std::string a, b;
    a = inf.readToken();
    b = inf.readToken();

    std::string s;
    s = ouf.readToken();

    int size_ans = ans.readInt();

    if (s.size() != size_ans){
        quitf(_wa, "baka");
    }

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size() && k < s.size()){
        if (a[i] == b[j] && b[j] == s[k]){
            i++;
            j++;
            k++;
        }
        if (a[i] != s[k]){
            i++;
        }
        if (b[j] != s[k]){
            j++;
        }
    }

    if (k == s.size()){
        quitf(_ok, "kawaii");
    }else{
        quitf(_wa, "baka");
    }

    return 0;
}
