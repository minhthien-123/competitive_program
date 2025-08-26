#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct minhthiendeptrai{
    ll val, dex;
};

ll m, n, i, j, k, r, ans = 0, p, t;
char s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("bangkitu.inp", "r", stdin);
    //freopen("bangkitu.out", "w", stdout);

    cin >> t;
    for (p = 0; p < t; p++){
        cin >> m >> n >> k;

        ll a[m + 5][n + 5];
        char chr[m + 5][n + 5];
        bool check[m + 5][n + 5];
        ans = 0;

        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                cin >> chr[i][j];
            }
        }

        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                check[i][j] = false;
            }
        }

        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                a[i][j] = 0;
            }
        }

        a[1][1] = 1;
        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                if (chr[i][j] != chr[i - 1][j] && !check[i][j] && !check[i - 1][j] && i != 1){
                    a[i][j] = a[i - 1][j] - 1;
                    //a[i - 1][j]--;
                    for (r = j; r < j + k + 1; r++){
                        a[i - 1][r]--;
                    }
                    check[i][j] = true;
                    check[i - 1][j] = true;
                }else if (chr[i][j] != chr[i][j - 1] && !check[i][j] && !check[i][j - 1] && j != 1){
                    a[i][j] = a[i][j - 1] - 1;
                    //a[i][j - 1]--;
                    for (r = i; r < i + k + 1; r++){
                        a[r][j - 1]--;
                    }
                    check[i][j] = true;
                    check[i][j - 1] = true;
                }else if (chr[i][j] == chr[i - 1][j] && i != 1){
                    a[i][j] = a[i - 1][j] + 1;
                    if (a[i][j] > k) a[i][j] = k + 1;
                }else if (chr[i][j] == chr[i][j - 1] && j != 1){
                    a[i][j] = a[i][j - 1] + 1;
                    if (a[i][j] > k) a[i][j] = k + 1;
                }
            }
        }

        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                if (a[i][j] <= k) a[i][j] = 0;
                else              a[i][j] = 1;
            }
        }

        /*for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/

        vector<ll> arr(n + 5, 0), beg(n + 5), en(n + 5);

        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++) {
                if (a[i][j] == 1) arr[j] = 0;
                else              arr[j] += 1;
            }

            vector<minhthiendeptrai> v;

            for (j = 1; j <= n; j++) {
                while (!v.empty() && v.back().val >= arr[j]) v.pop_back();

                if (v.empty()) beg[j] = 0;
                else           beg[j] = v.back().dex;

                v.push_back({arr[j], j});
            }

            v.clear();

            for (j = n; j >= 1; j--) {
                while (!v.empty() && v.back().val >= arr[j]) v.pop_back();

                if (v.empty()) en[j] = n + 1;
                else           en[j] = v.back().dex;

                v.push_back({arr[j], j});
            }

            for (j = 1; j <= n; j++) {
                ans = max(ans, arr[j] * (en[j] - beg[j] - 1));
            }
        }

        cout << ans << "\n";
    }
}
