#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], ans;
map<long long, long long>m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        //a[i] %= n;
        if (a[i] < 0) a[i] = n - (-a[i] % n);
        a[i] += a[i - 1];
        a[i] %= n;
    }

    //for (int i = 1; i <= n; i++) cout << a[i] << " ";

    m[0] = 1;
    for (int i = 1; i <= n; i++){
        ans += m[a[i]];
        m[a[i]]++;
    }

    cout << ans;
}
