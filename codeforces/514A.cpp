#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int x;
std::vector<int> ans;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> x;

    while (x > 0){
        int tmp = x % 10;
        x /= 10;
        if (tmp >= 5) tmp = 9 - tmp;
        ans.pb(tmp);
    }

    int res = ans[ans.size() - 1];
    if (res == 0) res = 9;
    for (int i = ans.size() - 2; i >= 0; i--){
        //std::cout << res << " " << i << "\n";
        res *= 10;
        res += ans[i];
    }

    std::cout << res;

    return 0;
}
