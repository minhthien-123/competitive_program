#include <bits/stdc++.h>
#define task "room"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e7 + 7;

int n, k, h;
int a[maxn], d[maxn], dp[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);\

    std::cin >> n >> k >> h;
    for (int i = 1 ; i <= n ; i++){
        std::cin >> a[i];
        d[a[i]]++;
    }

    for (int i = 1 ; i <= maxn ; i++)
    	dp[i] = dp[i / 10] + (i % 10);

    for (int i = maxn; i >= 1 ; i--){
        if(k >= d[i] && h > d[i] * dp[i]){
            k -= d[i];
            h -= d[i] * dp[i];
        }else{
            if(h <= d[i] * dp[i] && d[i] <= k){
                std::cout << "3M is the fattest of the fatman\n";
                return 0;
            }if(d[i] > k){
                h -= dp[i] * k;
                if(h > 0){
                    std::cout << h << "\n";
                    return 0;
                }else{
                    std::cout << "3M is the fattest of the fatman\n";
                    return 0;
                }
            }
        }
        
        d[i - dp[i]] += d[i];
    }
}
