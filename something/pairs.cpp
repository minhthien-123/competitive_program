#include <bits/stdc++.h>
using namespace std;

long long i, n, ans, a[1000005];
stack<long long> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("pairs.inp", "r", stdin);
    freopen("pairs.out", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            ans++;
            st.pop();
        }
        if (!st.empty())
        {
            ans++;
            if (a[i] == a[st.top()])
                continue;
        }
        st.push(i);
    }

    cout << ans;
}
