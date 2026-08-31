#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> a(N + 5, 0);
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = N; i >= 1; i--){
        int tmp = 0;
        for (int j = i; j <= N; j += i){
            tmp += a[j];
        }

        if (tmp >= 2){
            cout << i;
            break;
        }
    }
}
