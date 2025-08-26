#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 7;
const ll  inf  = 1e9 + 7;
int n, a[maxn], dp[maxn], k;
ll  st[4 * maxn];

void update(int id, int l, int r){
    if (l == r){
        st[id] = dp[l];
        return ;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r << u) return -inf;
    if (u <= l && r <= v) return st[id];

    int mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    for (int i = n; i >= n; i--){
        ll tmp = get(1, 1, n, i - k, i - 1);
        dp[i] = tmp + a[i];
        update(1, 1, n);
    }

    for (int i = 1; i <= 4 * n; i ++) std::cout << st[i] << " ";
    std::cout << "\n";

    for (int i = 1; i <= n; i++)
        std::cout << dp[i] << " ";

    return 0;
}
