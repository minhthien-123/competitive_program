#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxn = 10000005;
ll n, t, i, j, u, v, a[maxn], x, x1, x2;
bool prime[maxn], flag;

void sieve(ll n){
    for (i = 2; i <= n; i++)
        prime[i] = true;
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            for (j = i * 2; j <= n; j += i)
                prime[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve(maxn);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> x;
        flag = true;
        if (!prime[x]) flag = false;
        else{
            x1 = 10 * x;
            j = 0;
            while (j < 9 && !prime[x1 + j]) j++;
            //cout << x1 + j << " ";
            if (!prime[x1 + j]) flag = false;
            else{
                //cout << x << " ";
                while (trunc(log10(x)) != 0){
                    x2 = pow(10, trunc(log10(x)));
                    cout << x2 << " ";
                    x = x - (x / x2) * x2;
                    if (!prime[x]) flag = false;
                    cout << x << "\n";
                }
            }
        }

        if (flag) a[i] = 1;
        else a[i] = 0;

    }

    for (i = 0; i < n; i++)
        cout << a[i] << "\n";

    //cin >> t;
    //while (t--){
    //    cin >> u >> v;

    //}

    return 0;
}