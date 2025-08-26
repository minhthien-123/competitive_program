#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum < m) {
        cout << "NO" << endl;
        return 0;
    }

    // Giới hạn target tối đa là total_sum (1e5)
    int target = min(m, total_sum);
    vector<bool> dp(target + 1, false);
    vector<int> parent(target + 1, -1);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        int ai = a[i];
        for (int s = target; s >= ai; --s) {
            if (dp[s - ai] && !dp[s]) {
                dp[s] = true;
                parent[s] = i;
            }
        }
    }

    if (!dp[target]) {
        cout << "NO" << endl;
    } else {
        vector<int> subset;
        int s = target;
        while (s > 0) {
            int idx = parent[s];
            subset.push_back(a[idx]);
            s -= a[idx];
        }
        cout << "YES" << endl;
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}