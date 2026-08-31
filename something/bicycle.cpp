#include <bits/stdc++.h>
using namespace std;

long long n, x, mx;
vector <long long> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("bicycle.inp", "r", stdin);
    freopen("bicycle.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < (2 * n); i++){
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    mx = LLONG_MIN;
    int i = 0;

    for (int i = 0; i < n; i++) mx = max(mx, a[i] + a[2 * n - i - 1]);

    cout << mx;

    return 0;
}
