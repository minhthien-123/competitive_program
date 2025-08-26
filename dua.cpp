#include <bits/stdc++.h>
using namespace std;

bool ss(long long x, long long y){
    return x > y;
}

long long n, k, i, a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("dua.inp", "r", stdin);
    freopen("dua.out", "w", stdout);

    cin >> k >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, ss);
    for(i = 0; i  < n; i++) cout << a[i] << " ";

    i = 0;


    return 0;
}
