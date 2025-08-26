#include <bits/stdc++.h>
using namespace std;

long long n, i, t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        bool check = false;
        cin >> n;

        long long a[n + 5];
        for (i = 1; i <= n; i++) cin >> a[i];
        for (i = 1; i <= n; i++){
            if (a[a[a[i]]] == i) check = true;
            //cout << a[a[a[i]]] << " " << i << "\n";
        }

        //cout << check;
        if (check) cout << "<3\n";
        else       cout << "</3\n";
    }

    return 0;
}

//a[a[a[1]]]
//a[a[4]]
//a[2]
