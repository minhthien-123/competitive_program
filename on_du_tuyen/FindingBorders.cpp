#include <bits/stdc++.h>
#define task "FindingBorders"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 1e9 + 7;
const int p1 = 2;
const int p2 = 3;
const int maxn = 1e6 + 5;

int ans1[maxn], ans2[maxn], pre1, pre2, suf1, suf2;

std::string s;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> s;
    int n = s.size();

    ans1[0] = ans2[0] = 1;
    for (int i = 1; i < n; i++) {
        ans1[i] = (ans1[i - 1] * p1) % mod;
        ans2[i] = (ans2[i - 1] * p2) % mod;
    }

    for (int i = 0; i < n - 1; i++) {
        int l = (s[i] - 'a' + 1);
        int r = (s[n - i - 1] - 'a' + 1);

        pre1 = (pre1 + l * ans1[i]) % mod;
        pre2 = (pre2 + l * ans2[i]) % mod;
        suf1 = (suf1 * p1 + r) % mod;
        suf2 = (suf2 * p2 + r) % mod;

        if (pre1 == suf1 && pre2 == suf2)
            std::cout << i + 1 << " ";
    }

    return 0;
}
