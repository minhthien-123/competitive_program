#include <bits/stdc++.h>
using namespace std;

deque<long long> dq;
long long n, i, x, m, d = 0, a[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bicycles.inp", "r", stdin);
    freopen("bicycles.out", "w", stdout);

    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (i = 0; i < n; i++)
        dq.push_back(i);
    // cout << dq.back();

    while (!dq.empty())
    {
        if (a[dq.front()] + a[dq.back()] <= m)
        {
            d++;
            dq.pop_back();
            if (!dq.empty())
                dq.pop_front();
        }
        else
        {
            d++;
            dq.pop_back();
        }
    }

    cout << d;

    return 0;
}
