#include <bits/stdc++.h>
#define task "fence"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, k;
int a[maxn];

bool check(int m){
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        int tmp = a[i + 1] - a[i];
        cnt += (tmp - 1) / m;
    }

    return cnt <= k;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int l = 1, r = 1e18;
    int res = LLONG_MIN;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    std::cout << res;

    return 0;
}
