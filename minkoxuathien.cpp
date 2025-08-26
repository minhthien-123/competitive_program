#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], ans = -1;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    if (a[0] != 0) ans = 0;
    else{
        for (int i = 1; i < n; i++){
            if (a[i] - a[i - 1] != 0 && a[i] - a[i - 1] != 1){
                ans =  a[i - 1] + 1;
                break;
            }
        }
    }

    if (ans == -1) cout << a[n - 1] + 1;
    else           cout << ans;

    return 0;
}
