#include <bits/stdc++.h>

std::string s, p;
int l, ans = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("scpair5.inp", "r", stdin);
    std::freopen("scpair5.out", "w", stdout);

    getline(std::cin, s);
    getline(std::cin, p);

    l = s.size();

    //std::cout << l << "\n";

    for (int i = 0; i < l; i++){
        //std::cout << s[i] << " " << p[l - i - 1] << "\n";
        if (s[i] == p[l - i - 1])
            ans++;
    }

    std::cout << ans;

    return 0;
}