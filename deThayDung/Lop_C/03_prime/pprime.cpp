#include <bits/stdc++.h>
using namespace std;

long long reverse(int n){
    int val = 0;
    while (n > 0) {
        val = val * 10 + n % 10;
        n /= 10;
    }
    return val;
}

vector<bool> a(10e6, true);
long long i, j, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("PPRIME.INP", "r", stdin);
    freopen("PPRIME.OUT", "w", stdout);


    a[0] = false;
    a[1] = false;
    for (i = 2; i * i <= 10e6; i++){
        if (a[i]){
            for (j = i * i; j <= 10e6; j += i){
                a[j] = false;
            }
        }
    }

    cin >> n;

    if (n >= 2) cout << 2 << " ";
    for (int i = 3; i <= n; i += 2){
        if (a[i] && a[reverse(i)]){
            cout << i << " ";
        }
    }
}
