#include <bits/stdc++.h>
#define task "mayui"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n;
int a[maxn];

bool check(int h){
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += a[i] - h;
        if (res < 0) return false;
    }
    return true;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    int l = 1, r = 1e9, ans;

    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    std::cout << ans;

    return 0;
}

