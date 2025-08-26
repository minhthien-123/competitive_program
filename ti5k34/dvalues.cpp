#include <bits/stdc++.h>
#define task "dvalues3"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e6 + 7;
const int tt = 1e6;
std::map<int, int> m;
int a[maxn];
std::set<int> s;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        if (a[x] == 0)
        {
            std::cout << x << " ";
        }
        a[x]++;
    }

    return 0;
}
