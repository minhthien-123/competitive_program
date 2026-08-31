#include <bits/stdc++.h>
using namespace std;

int n, a[25], t, s, i, j;

int main(){
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        t += a[i];
    }

    s = t / 2;
    while (s > 0){
        bool d[s + 5] = {};
        d[0] = 1;
        for (i = 1; i <= n; i++)
            for (j = s; j >= a[i]; j--)
                if (d[j - a[i]] == 1) d[j] = 1;
        if (d[s]) {
            cout << t - 2 * s;
            break;
        }else{
            s--;
        }
    }



    return 0;
}
