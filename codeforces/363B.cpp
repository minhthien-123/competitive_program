#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    int ans = LLONG_MAX, res = 0;
    for (int i = 1; i + k - 1 <= n; i++){
        if (a[i + k - 1] - a[i - 1] <= ans){
            ans = a[i + k - 1] - a[i - 1];
            res = i;
        }
    }

    std::cout << res;

    return 0;
}

