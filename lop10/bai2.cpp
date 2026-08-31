#include <bits/stdc++.h>
using namespace std;

long long n;
string s;

void bit(long long n){
    if (n == 0) return;
    if (n % 2 == 0) {
        s = '0' + s;
    }else{
        s = '1' + s;
    }

    bit(n / 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("ctbit.inp", "r", stdin);
    //freopen("ctbit.out", "w", stdout);

    cin >> n;
    s = ' ';
    bit(n);
    cout << s << "\n";

    return 0;
}
