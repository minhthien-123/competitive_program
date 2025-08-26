#include <bits/stdc++.h>
using namespace std;

int n, a[100005], prf[100005], s, s_max;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    prf[0] = a[0];
    for (int i = 1; i < n; i++) prf[i] = prf[i - 1] + a[i];

    s = 1;
    s_max = 1;
    for (int i = 0; i < n; i++){
        if (a[i] > 0) s++;
        else{
            s_max = max(s, s_max);
            s = 1;
        }
    }

    cout << s_max;

    return 0;
}
