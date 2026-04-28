#include <bits/stdc++.h>
using namespace std;

long long n, i, h[1000005], f[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> h[i];

    f[1] = 0;
    f[2] = abs(h[2] - h[1]);
    for (i = 3; i <= n; i++){
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << f[n];
}