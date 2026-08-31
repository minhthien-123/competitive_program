#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000005];
bool kt[1000005];

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (j - a[i - 1] > 0){
            kt[j] = true;
            a[i] = j;
            if (i == k){
                for (int m = 1; m <= k; m++) cout << a[m] << " ";
                cout << "\n";
            }else Try(i + 1);
            kt[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("subset.inp", "r", stdin);
    freopen("subset.out", "w", stdout);

    cin >> n >> k;

    Try(1);
}
