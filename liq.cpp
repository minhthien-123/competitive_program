#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], dp[1000005], ans[1000005], res;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("LIQ.INP", "r", stdin);
    freopen("LIQ.OUT", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) dp[i] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                ans[i] = j;
            }
        }
    }

    res = 1;
    for (int i = 1; i <= n; i++)
        if (dp[i] > dp[res])
            res = i;

    while (res){
        v.push_back(res);
        res = ans[res];
    }

    cout << v.size() << "\n";
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}
