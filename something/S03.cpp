#include <bits/stdc++.h>
using namespace std;

int n, q, x;
map <int, int>a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < q; i++){
        cin >> x;
        if (a[x] == 0) cout << "NO" << "\n";
        else           cout << a[x] << "\n";
    }

}
