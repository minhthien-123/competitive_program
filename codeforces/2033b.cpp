    #include <bits/stdc++.h>
    #define task "codeforces"
    #define int long long
    #define ii std::pair<int, int>
    #define fi first
    #define se second
    #define pb push_back
    #define ins insert

    signed main(){
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0); std::cout.tie(0);

        if (std::fopen(task".inp", "r")){
            std::freopen(task".inp", "r", stdin);
            std::freopen(task".out", "w", stdout);
        }

        int t;
        std::cin >> t;
        while (t--){
            int n, m, res = 0;
            std::cin >> n;
            int a[n][n];
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    std::cin >> a[i][j];
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (a[i][j] < 0) {
                        int tmp = -a[i][j];
                        res += tmp;

                        for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
                            a[i - k][j - k] += tmp;
                        }
                    }
                    //std::cout << a[i][j] << " ";
                }

                //std::cout << "\n";
            }

            std::cout << res << "\n";
        }

        return 0;
    }

