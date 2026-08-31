#include <bits/stdc++.h>
#define task "permutation"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

int n;
int a[maxn], b[maxn], d;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= n; i++){
        d = 0;
        for (int j = 1; j <= n; j++){
            if (b[j] == 0) d++;
            if (d == (a[i] + 1)){
                b[j] = i;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        std::cout << b[i] << " ";

    return 0;
}

