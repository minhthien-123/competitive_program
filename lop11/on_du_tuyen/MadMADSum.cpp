#include <bits/stdc++.h>
#define task "MadMADSum"
#define int long long

int t;

int mad(int s, int n, std::vector<int> &a){
    std::map<int, int> m;
    int mx = 0;

    for(int i = 0; i < n; i++) {
        m[a[i]]++;
        if(m[a[i]] >= 2)
            if(a[i] > mx)
                mx = a[i];
        a[i] = mx;
    }

    m.clear();
    for(int i = 0; i < n; i++)
        m[a[i]]++;

    int p = 0, d = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != p) {
            s += a[i];
            if(m[a[i]] == 1) s += (n - i - 1) * d;
            else {
                s += (n - i - 1) * a[i];
                d = a[i];
            }
        }
    }

    return s;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            s += a[i];
        }

        std::cout << mad(s, n, a) << "\n";
    }

    return 0;
}
