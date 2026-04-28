#include <bits/stdc++.h>
#define task "Cashback"
#define int long long

const int maxn = 1e5 + 7;

std::multiset<int> s;
int n, c, a[maxn], dp[maxn], sum = 0;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> c;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i < c; i++)
        s.insert(a[i]);

    for (int i = c; i <= n; i++){
        s.insert(a[i]);
        if (s.find(a[i - c]) != s.end())
            s.erase(s.find(a[i - c]));
        int p = (int)*s.begin();
        dp[i] = std::max(dp[i - 1], dp[i - c] + p);
    }

    //for (int i = 1; i <= n; i++)
        //std::cout << dp[i] << " ";

    std::cout << sum - dp[n];

    return 0;
}
