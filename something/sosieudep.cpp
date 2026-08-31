#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;

long long minPrime[10000000], x, i, j, ans, d, k;
map<long long, long long> m;
vector<long long> res;

vector<long long> factorize(long long n) {
    res.clear();
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k;

    for (i = 2; i <= N; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (j = i * 2; j <= N; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (i = 2; i <= N; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }

    x = min(N, k);

    for (i = 1; i <= x; i++){
        factorize(i);
        ans = 1;
        m.clear();
        for (j = 0; j < res.size(); j++){
            //cout << res[j] << " ";
            m[res[j]]++;
            if (m[res[j]] == 3) ans = res[j];
        }
        //cout << "\n";

        if (i / (ans * ans * ans) < ans && ans * ans * ans != i && res.size() == 4) d++;
    }

    cout << d;

}

