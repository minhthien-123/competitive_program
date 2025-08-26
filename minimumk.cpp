#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000005], mn[1000005], i;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("minimumk.inp", "r", stdin);
    freopen("minimumk.out", "w", stdout);

    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1; i <= n; i++)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        if (i >= k)
            mn[i] = a[dq.front()];
    }

    for (i = k; i <= n; i++)
        cout << mn[i] << "\n";
}
