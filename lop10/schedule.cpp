#include <bits/stdc++.h>
#define task "schedule"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

struct schedule{
    int val, time;
};

bool cmp(schedule x, schedule y) {
	return x.val * y.time > x.time * y.val;
}

int n, i, ans = 0, s = 0;
schedule a[1000005];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (i = 0; i < n; i++){
        std::cin >> a[i].val;
        s += a[i].val;
    }

    for (i = 0; i < n; i++) std::cin >> a[i].time;

    std::sort(a, a + n, cmp);

    for (i = 0; i < n; i++){
        ans += s * a[i].time;
        s   -= a[i].val;
    }

    std::cout << ans;

    return 0;
}
