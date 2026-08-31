#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz size

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<int> a, b;
    for (int i = 0; i < s1.sz(); i++)
        a.pb((int)s1[i] -'0');
    for (int i = 0; i < s2.sz(); i++)
        b.pb((int)s2[i] - '0');

    int ans = 0;
    for (int i : a)
        for (int j : b)
            ans += i * j;

    std::cout << ans;

    return 0;
}

