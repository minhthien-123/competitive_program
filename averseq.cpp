#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6;
long long n, i, j;
long long a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("averseq.inp", "r", stdin);
    freopen("averseq.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    bool isPrime[N + 5];

    for (i = 0; i < N; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (i = 2; i * i <= N; ++i) {
        if (isPrime[i]){
            for (j = i * i; j <= N; j += i){
                isPrime[j] = false;
            }
        }
    }

    for (i = 0; i < n; i++){
        if (isPrime[a[i]]) break;
    }

    if (i == n) i = -1;

    cout << i + 1;

    return 0;

}

