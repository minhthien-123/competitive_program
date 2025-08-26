#include <bits/stdc++.h>
using namespace std;


long long a, b, n, x, y, i, a1, a2;
map<long long, long long> m;
vector<long long> arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("fnum.inp", "r", stdin);
    //freopen("fnum.out", "w", stdout);

    cin >> x >> y >> n;
    a = min(x, y);
    b = max(x, y);
    x = a * b / __gcd(a, b);
    //cout << x << "\n";
    /*if (b % a == 0) cout << a * n;
    else if (n % (b / a + 1) == 0) cout << b * (n / (b / a + 1));
    else if (__gcd(a, b) == 1){
        //cout << n / x << "\n";
        cout << a * (n - n / (x + 1));
    }else{

    }*/

    for (i = a; i <= x; i++){
        if (i % a == 0 && i % b == 0) arr.push_back(3);
        else if (i % a == 0) arr.push_back(1);
        else if (i % b == 0) arr.push_back(2);
    }

    //for (i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    //cout << "\n";
    for (i = 0; i < arr.size(); i++)
        if (arr[i] == 2){
            a1 = i + 1;
            break;
        }

    a2 = n / arr.size();

    if (a == 1 || b == 1) cout << n;
    else if (n % arr.size() == 0) cout << x * n / arr.size();
    else{
        x = n % arr.size();
        //cout << x << " " << arr[x - 1] << "\n";
        if (arr[x - 1] == 2){
            //cout << a1 << "\n";
            cout << b * (n / a1);
        }else{
            x = arr.size() / a1 - 1;
            //cout << x << "\n";

            //cout << arr.size() << " ";
            //cout << arr.size() - x << " " << (n + arr.size() - n % arr.size()) / arr.size() << "\n";
            cout << (arr.size() - x) * (n + arr.size() - n % arr.size()) / arr.size() / arr.size();
        }
    }


    //cout << (n - 1) * a * b / (a + b);
}
