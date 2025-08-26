#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[1000005], d1, d2, ans, x;
map<int, int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("triangles.inp", "r", stdin);
    //freopen("triangles.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        m[x]++;
        if (m[x] == 1){
            a[d1] = x;
            d1++;
        }else if (m[x] == 2){
            b[d2] = x;
            d2++;
        }
        //else if (m[x] == 3)  ans++;
    }

    sort(a, a + d1);
    for (int i = 0; i < d1 - 1; i++){
        for (int j = i + 1; j < d1; j++){
            x = lower_bound(a + j + 1, a + d1, a[i] + a[j]) - a;
            ans += x - j - 1;
        }
    }

    //cout << ans << "\n";

    for (int i = 0; i < d2; i++){
        for (int j = 0; j < d1; j++){
            if ((b[i] + b[i] > a[j])) ans++;
        }
    }

    cout << ans;
}
