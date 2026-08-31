#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6;
int t, minPrime[N + 5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= N; i++) minPrime[i] = i;

    for (int i = 2; i * i <= N; ++i) {
        if (minPrime[i] == i){
            for (int j = i * i; j <= N; j += i) {
                if (minPrime[j] == j){
                    minPrime[j] = i;
                }
            }
        }
    }

    cin >> t;
    while (t--){
        int n;
        cin >> n;
        ll ans = 1;
        while (n != 1){
            int tmp = minPrime[n], cmp = 1;
            while(n % tmp == 0){
                cmp++;
                n /= tmp;
            }

            ans *= cmp;
        }

        cout << ans << "\n";
    }
}
