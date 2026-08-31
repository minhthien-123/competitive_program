#include <bits/stdc++.h>
using namespace std;

long long n, k, ans;
long long a[1000005];
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    m[0] = 1;
    for (long long i = 1; i <= n; i++){
        ans += m[a[i] - k];
        m[a[i]]++;
    }

    cout << ans;

}
