#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], i, d = 0, tmp, ans = 0;
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("covid.inp", "r", stdin);
    freopen("covid.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    pq.push(a[0]);
    //pq.push(a[1]);
    //cout << pq.top() << "\n";
    //pq.pop();
    //cout << pq.top() << "\n";

    for (i = 1; i < n; i++){
        if (a[i] == 6) d++;
        else if (!pq.empty()){
            if (a[i] + pq.top() == 6){
                //cout << "=\n";
                if (!pq.empty()) pq.pop();
                d++;
            }
            else if (a[i] + pq.top() > 6){
                //cout << ">\n";
                d++;
                pq.pop();
                pq.push(a[i]);
            }
            else{
                //cout << "<\n";
                tmp = pq.top();
                if (!pq.empty()) pq.pop();
                tmp = a[i] + tmp;
                if (!pq.empty()) pq.pop();
                pq.push(tmp);

            }
        }else{
            pq.push(a[i]);
        }
    }

    //cout << pq.top();
    //pq.pop();
    //cout << pq.top();

    cout << d;
}
