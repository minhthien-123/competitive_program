#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], k, d;

bool tknp(int x, int n){
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) / 2;
        if (a[g] == x) return 1;
        else if (a[g] < x) d = g + 1;
        else               c = g - 1;
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++){
        if (tknp(a[i] + k, n)) d++;
    }

    cout << d;

    return 0;
}
