#include <bits/stdc++.h>
using namespace std;

struct minhthiendeptrai{
    long long time, val;
};

bool ss(minhthiendeptrai x, minhthiendeptrai y){
    if (x.time == y.time) return x.val < y.val;
    else return x.time < y.time;
}

long long n, l, r, i, beg, en, ans = 0, d = 0;
minhthiendeptrai a[1000005];
priority_queue<long long> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("peach.inp", "r", stdin);
    freopen("peach.out", "w", stdout);

    cin >> n >> l >> r;
    for (i = 0; i < n; i++) cin >> a[i].time >> a[i].val;

    sort(a, a + n, ss);

    //for (i = 0; i < n; i++) cout << a[i].time << " " << a[i].val << "\n";
    //cout << "\n";

    for (i = l; i < r; i++){
        while (d < n && a[d].time <= i){
            pq.push(a[d].val);
            d++;
        }

        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}

