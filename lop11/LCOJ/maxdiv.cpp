#include <bits/stdc++.h>
using namespace std;

long long n, k, x, a[1000005], i, ans = 0;
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    a[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> x;
        if (x % k == 0) a[i] = 1;
        else            a[i] = 0;

        a[i] += a[i - 1];
    }

    ans = n;

    for (i = 0; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    for (i = 0; i <= n; i++) m[a[i]]++;
    m[0]--;

    for (i = 0; i <= a[n]; i++) cout << m[a[i]] << " ";
    cout << "\n";

    for (i = 0; i < a[n]; i++)
        ans += m[a[i]] * m[a[i] + 1];

    cout << ans;

    return 0;
}