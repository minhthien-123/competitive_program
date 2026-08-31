#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int ans = 0;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int l = 1, r = n;
    while (l <= r){
        //std::cout << l << " " << r << "\n";
        int tmp = a[r];
        while (tmp + a[l] <= 4){
            l++;
            tmp += a[l];
        }
        r--;
        ans++;
    }

    std::cout << ans;

    return 0;
}

