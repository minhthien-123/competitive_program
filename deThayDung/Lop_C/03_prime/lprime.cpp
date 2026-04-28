#include <bits/stdc++.h>
using namespace std;

long long maxn = 10e6;
long long n, i, j;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("lprime.inp", "r", stdin);
    freopen("lprime.out", "w", stdout);

    cin >> n;

    vector<bool> is_prime(10e6, true);
    for(i = 2; i * i <= maxn; i++){
        if(is_prime[i]){
            for(j = i * i; j <= maxn; j += i){
                is_prime[j] = false;
            }
        }
    }

    while(is_prime[n] == false) n--;
    cout << n;

}