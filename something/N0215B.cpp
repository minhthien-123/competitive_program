#include <bits/stdc++.h>
using namespace std;

int x, d = 0;
map <int, int>a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 5; i++){
        cin >> x;
        if (a[x] == 0){
            d++;
            a[x] = 1;
        }
    }

    if (d <= 2) cout << "YES";
    else        cout << "NO";

    return 0;
}
