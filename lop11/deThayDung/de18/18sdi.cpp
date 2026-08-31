#include <bits/stdc++.h>
#define ll long long

std::string s;
ll ans = 0;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("18sdi.inp", "r", stdin);
    std::freopen("18sdi.out", "w", stdout);

    getline(std::cin, s);
    for (int i = 0; i < s.size(); i++)
        ans = ans + s[i] - '0';

    std::cout << ans;

    return 0;
}
