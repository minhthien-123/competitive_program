#include <bits/stdc++.h>
#define task "permute"
#define ll long long
#define pb push_back

const int maxn = 1e6 + 7;

std::vector<int> a;
int n, q;
int f[maxn];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        a.pb(x);
    }

    while (q--){
        int l, r;
        std::cin >> l >> r;
    }

    return 0;
}
