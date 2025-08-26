#include <bits/stdc++.h>
#define task "deldec"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

    std::string s;
    std::cin >> s;

    std::string ans = "";

    for (int i = 0; i < s.size(); ++i) {
        std::string tmp = s.substr(0, i) + s.substr(i + 1);

        tmp.erase(0, tmp.find_first_not_of('0'));

        if (tmp.empty())
            tmp = "0";

        if (tmp > ans) {
            ans = tmp;
        }
    }

    std::cout << ans;

    return 0;
}
