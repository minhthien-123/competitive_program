#include <bits/stdc++.h>
using namespace std;
long n, a[1000009], f[1000009], d[1000009], max1 = LONG_MIN, min1 = LONG_MAX;
int main()
{
    cin.tie(0);
    cout.tie(0);
    freopen("SSUMMIN.inp", "r", stdin);
    freopen("SSUMMIN.out", "w", stdout);
    cin >> n;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        d[i] = max(d[i - 1], f[i]);
        min1 = min(min1, a[i]);
    }
    for (long i = 1; i <= n; i++)
    {
        if (min1 > (f[i] - d[i]) && f[i] != d[i])
            min1 = f[i] - d[i];
    }
    cout << min1;
    return 0;
}
/*
8
4 6 12 8 10 5 18 26
4

*/
