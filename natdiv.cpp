#include <bits/stdc++.h>
#define task "us"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;

int t;
int sum[maxn], divv[maxn];

std::vector<ii> res(1e6 + 5, {0,0});

ii cal(int a){
    int suma = 0, cnta = 0;
    for(int i = 1; i <= a; i++){
        suma += (a / i) * i;
        cnta += a / i;
    }
    return {cnta, suma};
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> t;

    for (int i = 1; i <= t; i++){
        int x, y;
        std::cin >> x >> y;
        x--;

        ii u1, u2;
        if(res[x].fi == 0 && res[x].se == 0) u1 = cal(x);
        else u1 = res[x];

        if(res[y].fi == 0 && res[y].se == 0) u2 = cal(y);
        else u2 = res[y];

        res[x] = u1, res[y] = u2;
        std::cout << u2.fi - u1.fi << " " << u2.se - u1.se << "\n";
    }


    return 0;
}
