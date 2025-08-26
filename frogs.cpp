#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], b[1000005], ans[1000005], st[1000005], top, i;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("frogs.inp", "r", stdin);
    freopen("frogs.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n; i++)
        cin >> b[i];

    top = 0;
    st[0] = INT_MAX;

    for (i = n - 1; i >= 0; i--)
    {
        while (st[top] <= a[i])
            top--;
        st[++top] = a[i];
        if (top <= b[i])
            ans[i] = -1;
        else
            ans[i] = st[top - b[i]];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
