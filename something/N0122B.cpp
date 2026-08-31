#include <bits/stdc++.h>
using namespace std;

long long n;

int main(){
    cin >> n;

    long long i = 1;
    while (n % i != 0 || (n / i) % 2 == 0) i++;
    cout << n / i;

    return 0;
}
