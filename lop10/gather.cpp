#include <bits/stdc++.h>
#define task "gather"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, ans = 0;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a, a + n);

    int mid;
    if (n % 2 == 1)
        mid = a[n / 2];
    else
        mid = a[n / 2 - 1];

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - mid);

    std::cout << ans;

    return 0;
}

