#include <bits/stdc++.h>
using namespace std;

bool cmp(long a, long b){
    return a > b;
}

long n, i, a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, x > y);

    for (i = 0; i < n; i++) cout << a[i] << " ";
}
