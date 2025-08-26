#include <bits/stdc++.h>
using namespace std;

struct minhthiendeptrai{
    long long val, dex;
};

struct greaterr{
    bool operator()(minhthiendeptrai x, minhthiendeptrai y){
        //if (x.val == y.val) return x.dex > x.dex;
        //else return x.val < y.val;
        return (x.val > y.val || (x.val == y.val && x.dex > y.dex));
    }
};

long long m, n, i, d = 0, k;
minhthiendeptrai a[1000005];
priority_queue <minhthiendeptrai, vector<minhthiendeptrai>, greaterr> pq;
priority_queue <long long, vector<long long>, greater<long long> > pq1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("chaybo.inp", "r", stdin);
    //freopen("chaybo.out", "w", stdout);

    cin >> n >> m;
    for (i = 0; i < n; i++){
        cin >> a[i].val >> a[i].dex;
        pq.push(a[i]);
    }
    for (i = 0; i < m; i++){
        cin >> k;
        pq1.push(k);
    }

    /*while(!pq.empty()){
            cout << pq.top().val << " " << pq.top().dex << "\n";
            pq.pop();
    }

    while (!pq1.empty()){
        cout << pq1.top();
        pq1.pop();
    }
    cout << "\n";*/

    while (!pq.empty() && m > 0){
        if (pq1.top() == pq.top().val){
            //cout << pq1.top() << " " << pq.top().val << " " << pq.top().dex << "\n";
            d += pq.top().dex;
            pq1.pop();
            pq.pop();

            m--;
        }else{
            pq.pop();
        }

    }

    if (m > 0) cout << -1;
    else cout << d;

    return 0;
}
