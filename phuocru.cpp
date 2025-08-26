#include <bits/stdc++.h>
using namespace std;
long long a[(int)2e6 + 1], b[(int)2e6 + 1] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("CHALLENGE.inp", "r", stdin);
    freopen("CHALLENGE.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    if (k == 0)
    {
        long long dem = 0, m = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
                dem++;
            else
            {
                m = max(m, dem);
                dem = 0;
            }
            if (i == n)
            {
                m = max(m, dem);
                break;
            }
        }
        cout << n - m;
    }
    else
    {
        long dem = 0, s = 0, j = 1, m = 0;
        for (int i = 1; i <= n; i++)
        {
            while (j <= n and b[j] - b[i - 1] <= k)
                j++;
            if (b[j - 1] - b[i - 1] == k)
                m = max(m, j - i);
        }
        cout << n - m;
    }
    return 0;
}
