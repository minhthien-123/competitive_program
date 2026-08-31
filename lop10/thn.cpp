#include <bits/stdc++.h>
#define task "thn"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int n, ans = 0;
    std::string s[3] = {"UYEN", "LE", "HA"};
    std::cin >> n;

    while (n > 0){
        //std::cout << n << "\n";
        n /= 2;
        ans++;
    }


    ans %= 3;

    std::cout << s[ans];

    return 0;
}

/*
LE
HA
HA
UYEN
UYEN
UYEN
UYEN
LE
LE
LE
LE
LE
LE
LE
LE
*/
