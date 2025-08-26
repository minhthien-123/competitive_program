#include <bits/stdc++.h>
using namespace std;

stack<long long> s;
long long n, i, a[1000005], dex[1000005], j, st[1000005], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("lineup.inp", "r", stdin);
    //freopen("lineup.out", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];

    //s.push(a[0]);

    for (i = 1; i <= n; i++){
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (s.empty()) dex[i] = -1;
        else           dex[i] = s.top() - 1;

        s.push(i);
    }

    for (i = 1; i <= n; i++) cout << dex[i] << " ";
}


