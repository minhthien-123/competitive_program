#include <bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
long long l, n, i, x, ans, y, a[1000005], s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("partition.inp", "r", stdin);
    freopen("partition.out", "w", stdout);

    cin >> l >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
        s += a[i];
    }

    if (l > s){
        a[++n] = l - s;
        pq.push(a[n]);
    }

    while (pq.size() > 1){
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();

        ans += x + y;
        pq.push(x + y);

        //cout << x << " " << y << " " << ans << "\n";
    }

    cout << ans;

    return 0;
}
