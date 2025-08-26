#include <bits/stdc++.h>
#define task "inversion"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

int n;
int a[maxn], b[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        for (int j = i; j >= 1; j--){
            if (a[j] > a[i]){
                b[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        int j = 1;
        while (j <= n && a[j] != i){
            j++;
        }

        std::cout << b[j] << " ";
    }

    return 0;
}

