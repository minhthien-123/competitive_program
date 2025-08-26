#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

void solve(){
    int n, m, q;
    std::cin >> n >> m >> q;

    int a[n + 7], b[m + 7];
    bool flag[n + 7] = {false};

    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)    {
        std::cin >> b[i];
    }

    int l = 1;
    flag[a[1]] = true;

    for(int i = 1; i <= m; i++){
        if (!flag[b[i]]){
            std::cout<<"TIDAK\n";
            return;
        }else{
            if(l + 1 <= n && a[l] == b[i]){
                flag[a[++l]] = true;
            }
        }
    }

    std::cout << "YA\n";
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

