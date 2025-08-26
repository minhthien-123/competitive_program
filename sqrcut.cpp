#include <bits/stdc++.h>
using namespace std;

int t, a, b, d = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b;


        while (!(a == b == 1) && !(a == 0 || b == 0)){
            int x = a, y = b;
            a = max(x, y);
            b = min(x, y);
            //cout << a << " " << b << endl;
            if (!(a == 0 || b == 0 || (a == 0 && b == 0))){
                d += a / b;
                a = a % b;
            }

        }

        cout << d - 1<< endl;

        //cout << a << " " << b << endl;
    }


    return 0;
}
