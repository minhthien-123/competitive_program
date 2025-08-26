#include <bits/stdc++.h>
#define task "rep"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz size()

const int maxn = 1e5 + 7;

bool cmp(ii x, ii y){
    if (x.se == y.se) return x.fi > y.fi;
    return x.se < y.se;
}

ii a[maxn];
std::map<int, int> m;
int n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1, cmp);

    int beg = a[1].se - 1, en = a[1].se;
    m[beg]++; m[en]++;

    for (int i = 2; i <= n; i++){
        if (beg < a[i].fi && a[i].fi <= en){
            m[a[i].se]++;
            beg = en;
            en = a[i].se;
        }
        if(en < a[i].fi){
            beg = a[i].se - 1; en = a[i].se;
            m[beg]++; m[en]++;
        }
    }

    std::cout << m.sz << "\n";
    for (auto i : m){
        std::cout << i.fi << " ";
    }

    return 0;
}

