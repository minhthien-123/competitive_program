#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull sum(ull n){
    ull ans = 0;

    while (n > 0){
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

ull t, x, l, r, mid;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        ull n = x / 2;
        cin >> x;
        if (n + n == x) cout << n << " " << n << "\n";
        else if (sum(n - 4) == sum(n + 5)) cout << n - 4 << " " << n + 5 << "\n";
        else cout << "-1\n";
    }
}
