#include <bits/stdc++.h>
#define task "cover"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

struct cover{
    int beg, en, dex;
};

bool cmp(cover x, cover y){
    return ((x.beg < y.beg) || (x.beg == y.beg && x.en < y.en));
}

cover a[maxn], ans;
int n, x, y, res[maxn], d;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> x >> y;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i].beg >> a[i].en;
        a[i].dex = i;
    }

    std::sort(a + 1, a + n + 1, cmp);

    int j = 1, d = 1;

    while (x < y){
        ans.beg = -1;
        for (int i = 1; i <= n && a[i].beg <= x; i++){
            if (ans.beg == -1 || a[i].en > a[ans.beg].en){
                ans.beg = i;
                j = a[i].dex;
            }
        }

        if (ans.beg == -1 || a[ans.beg].en < x){
            std::cout << -1;
            return 0;
        }

        if (d > n){
            std::cout << -1;
            return 0;
        }

        res[d++] = j;
        x = a[ans.beg].en;
    }

    std::cout << d - 1 << "\n";
    for (int i = 1; i < d; i++){
        std::cout << res[i] << "\n";
    }

    return 0;
}
