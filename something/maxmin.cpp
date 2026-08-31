#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 1;
int a[maxn], n, k;

bool check(int x) {
    int s = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(s + a[i] <= x) {
            s += a[i];
        }
        else if(s + a[i] > x) {
            s = a[i];
            cnt++;
        }
        if(s > x) cnt++;
        if(i == n && s <= x) cnt++;
    }
    return cnt <= k;
}
signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int l = 1, r = 1e18, ans = 0;
    while(l <= r) {

        int mid = (l + r) / 2;
        if(check(mid))
        {
            ans = r;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << l;
}
