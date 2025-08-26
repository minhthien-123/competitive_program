#include <bits/stdc++.h>
using namespace std;

long long n, a, b, i, ans;

long long tong_uoc(long long n){
    ans = 1;
    for (i = 2; i <= trunc(sqrt(n)); i++){
        if (n % i == 0){
            ans += i;
            if (n / i != i) ans += (n / i);
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("friends.inp", "r", stdin);
    freopen("friends.out", "w", stdout);

    cin >> n;
    while (n--){
        cin >> a >> b;
        //cout << tong_uoc(a) << " " << tong_uoc(b) << "\n";
        if (tong_uoc(a) == b && tong_uoc(b) == a) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}

//31