#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Result {
    ll value;
    vector<int> items;
};

void solve() {
    int n, S;
    cin >> n >> S;

    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    function<Result(int, int)> rec = [&](int i, int cur_w) -> Result {
        if (i >= n) {
            return {0, {}};
        }

        Result exclude = rec(i + 1, cur_w);

        Result include = {0, {}};
        if (cur_w + w[i] <= S) {
            include = rec(i + 1, cur_w + w[i]);
            include.value += v[i];
            include.items.push_back(i);
        }

        if (include.value > exclude.value) {
            return include;
        } else {
            return exclude;
        }
    };

    Result ans = rec(0, 0);
    reverse(ans.items.begin(), ans.items.end());

    cout << ans.value << "\n";
    for (int item : ans.items) {
        cout << item + 1 << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt = 1;
    while (tt--)
        solve();

    return 0;
}