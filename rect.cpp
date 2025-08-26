#include <bits/stdc++.h>
using namespace std;

long long m, n, i, beg[1000005], en[1000005], a[1000005], begin_ans, end_ans, ans = LLONG_MIN, height_ans, res;
stack<long long> st;

void minhthiendeptrai(){
    stack<long long> st;
    for (i = 1; i <= n; i++){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) beg[i] = 0;
        else            beg[i] = st.top();
        st.push(i);
    }

    //stack<long long> st;
    while (!st.empty()) st.pop();

    for (i = n ; i >= 1; i--){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) en[i] = n + 1;
        else            en[i] = st.top();
        st.push(i);

        if ((en[i] - beg[i] - 1) * a[i] > ans){
            ans = (en[i] - beg[i] - 1) * a[i];
            begin_ans = beg[i];
            end_ans    = en[i];
            height_ans = a[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (i = 1; i <= n; i++) cin >> a[i];

    minhthiendeptrai();
    res = ans;
    //cout << res << "\n";
    // << begin_ans << " " << end_ans << " " << height_ans << "\n";

    for (i = 1; i <= n; i++) a[i] = m - a[i];

    minhthiendeptrai();
    //cout << ans << "\n";

    if (res >= ans){
        cout << res << "\n";
        cout << 1 << " " << begin_ans + 1 << "\n";
        cout << height_ans << " " << end_ans - 1;
    }else{
        cout << ans << "\n";
        cout << m - height_ans + 1 << " " << begin_ans + 1 << "\n";
        cout << m << " " << end_ans - 1;
        //cout << "\n";
    }

    //cout << 1 << " " << begin_ans + 2 << "\n";
    //cout << height_ans << " " << end_ans;
    //cout << begin_ans << " " << end_ans << " " << height_ans << "\n";

}

// 2 4 5 9 10 31 34 40
