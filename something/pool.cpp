#include <bits/stdc++.h>
using namespace std;

long long a[1000005];
long long n, m, i, mx = LLONG_MIN, beg, en, tmp, ans = 1, d, c, g;
vector<long long> v;

bool check(long long k){
    priority_queue<long long, vector<long long>, greater<long long> > pq;

    for (i = 1; i <= k; i++){
        pq.push(a[i]);
    }

    for (i = k + 1; i <= n; i++){
        if (a[i] + pq.top() > m) return false;
        else{
            tmp = pq.top();
            pq.pop();
            pq.push(tmp + a[i]);
        }
    }

    /*while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }*/

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("pool.inp", "r", stdin);
    freopen("pool.out", "w", stdout);

    cin >> n >> m;
    for (i = 1; i <= n; i++) cin >> a[i];

    d = 1;
    c = n;
    //g = (d + c) / 2;
    //check(g);

    while (d <= c){
        g = (d + c) / 2;
        //cout << g;
        if (check(g)){
            ans = g;
            //cout << g;
            //cout << g << "\n";
            c = g - 1;
        }else d = g + 1;
        //check(g)
    }

    cout << ans;

    return 0;
}
