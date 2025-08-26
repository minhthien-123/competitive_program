#include <bits/stdc++.h>
using namespace std;
long n, a[1000009], f[1000009], s = 0, l = 1, min1 = LONG_MAX;
int main()
{
    cin.tie(0);
    cout.tie(0);
    freopen("SSUMMIN.inp","r",stdin);
    freopen("SSUMMIN.ans","w",stdout);
    cin >> n;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    long min2 = LONG_MAX;
    for (long i = 1; i <= n; i++)
        for (long j = i; j <= n; j++)
        {
            long s = f[j] - f[i - 1];
            min2 = min(min2, s);
        }
    cout << min2;
    return 0;
}