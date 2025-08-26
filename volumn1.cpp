#include <bits/stdc++.h>
using namespace std;

long double val = 0;
vector<long double> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> val &&val!=EOF)
        v.push_back(sqrt(val));

    for (int i = v.size()-1; i >=0; i--)
        cout<< fixed << setprecision(4) << v[i] << endl;

    return 0;
}
