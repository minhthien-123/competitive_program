#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull t, x;
bool flag;

ull sum(ull n){
    ull ans = 0;
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> x;
        ull n = x / 2;
        while (sum(n) != sum(x - n) && n < x){
            n++;
        }

        if (n < x) cout << n << " " << x - n << "\n";
        else       cout << "-1\n";

    }
}
