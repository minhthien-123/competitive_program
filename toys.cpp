#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if (n > k){
        if (k % 2 == 0) cout << k / 2 - 1;
        else            cout << k / 2;
    }else if(n * 2 <= k){
        cout << 0;
    }else{
        cout << n - k / 2;
    }

    return 0;
}
