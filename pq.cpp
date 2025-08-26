#include <bits/stdc++.h>
using namespace std;

string s;
priority_queue<long> pq;
long n, i, mx, d, a[1000005], x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("pq.inp", "r", stdin);
    //freopen("pq.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] == '+')
        {
            s.erase(s.begin() + 0);
            x = atol(s.c_str());
            // cout << x << "\n";
            pq.push(x);
        }
        else
        {
            if (!pq.empty())
            {
                mx = pq.top();
                while (!pq.empty() && pq.top() == mx)
                    pq.pop();
            }
        }
    }
    // cout << "\n";

    d = 0;
    while (!pq.empty())
    {
        mx = pq.top();
        // cout << mx << "\n";
        while (!pq.empty() && pq.top() == mx)
            pq.pop();
        a[d] = mx;
        d++;
    }

    cout << d << "\n";
    for (i = 0; i < d; i++)
        cout << a[i] << " ";
}
