#include <bits/stdc++.h>
using namespace std;

int n;
bool prime[1000005];


int main(){
    for (int i = 0; i <= 1000000; i++){
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for(int i = 2; i * i <= 1000000; i++){
        if (prime[i] == true){
            for (int j = i * i; j <= 1000000; j++){
                prime[j] = false;
            }
        }
    }

    cin >> n;
    for (int i = n; i > 0; i --){
        if (prime[i]) cout << i;

    }

    return 0;
}
