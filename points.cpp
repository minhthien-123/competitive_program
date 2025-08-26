#include <bits/stdc++.h>
using namespace std;

long long n, k, a[200005], i, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;


    for (i = 0; i < n; i++) cin >> a[i];

    for (i = 0; i < k; i++){
        cin >> x;
        a[x - 1]--;
    }

    for (i = 0; i < n; i++){
        cout << a[i] + k << " ";
    }

    return 0;
}
