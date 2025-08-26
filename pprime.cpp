#include <bits/stdc++.h>
#define task "pprime"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e7 + 7;

int dx(int n){
    int val = 0;
    while (n > 0) {
        val = val * 10 + n % 10;
        n /= 10;
    }
    return val;
}

std::vector<bool> a(maxn, true);
int i, j, n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    for (i = 0; i <= maxn; i++){
        a[i] = true;
    }

    a[0] = false;
    a[1] = false;
    for (i = 2; i * i <= maxn; i++){
        if (a[i]){
            for (j = i * i; j <= maxn; j += i){
                a[j] = false;
            }
        }
    }

    std::cin >> n;

    if (n >= 2) std::cout << 2 << " ";
    for (int i = 3; i <= n; i += 2){
        if (a[i] && a[dx(i)]){
            std::cout << i << " ";
        }
    }

    return 0;
}