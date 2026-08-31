#include <bits/stdc++.h>
using namespace std;

struct minhthiendeptraivkl{
    long long val, time;
};

bool ss(minhthiendeptraivkl x, minhthiendeptraivkl y) {
	return x.val * y.time > x.time * y.val;
}

long long n, i, ans = 0, s = 0;
minhthiendeptraivkl a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("schedule.inp", "r", stdin);
    freopen("schedule.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i].val;
        s += a[i].val;
    }

    for (i = 0; i < n; i++) cin >> a[i].time;

    sort(a, a + n, ss);

    //for (i = 0; i < n; i++) cout << a[i].val << " " << a[i].time << "\n";

    for (i = 0; i < n; i++){
        ans += s * a[i].time;
        s   -= a[i].val;
    }

    cout << ans;
}
