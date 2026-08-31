#include <bits/stdc++.h>
using namespace std;

long long t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        cout << n * (n + 1) / 2 + n << "\n";
    }
}
