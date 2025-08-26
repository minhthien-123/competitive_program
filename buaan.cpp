#include <bits/stdc++.h>
using namespace std;

long long n, c, s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> c >> s;
    cout << n * c - s * (n / 15);

    return 0;
}
