#include <bits/stdc++.h>
using namespace std;

int n, x, mx;
map <int, int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }

    for (int i = 1; i < 262144; i++){
        a[i] = a[i] + (a[i - 1] / 2);
        if (a[i] == 0) break;
        else           mx = i;
    }

    cout << mx;

}
