#include <bits/stdc++.h>
using namespace std;

struct minhthiendeptrai{
    int val, type, dex;
};

minhthiendeptrai a[1000005];
int n, beg, en, m, meet[1000005], i, j, tmp;
vector<int> room[1000005];
stack<int>  st;

bool ss(minhthiendeptrai x, minhthiendeptrai y){
    if (x.val == y.val) return x.type > y.type;
    else return x.val < y.val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("rooms.inp", "r", stdin);
    freopen("rooms.out", "w", stdout);
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> beg >> en;
        a[i * 2 - 1].val   = beg;
        a[i * 2].type      = 0;
        a[i * 2 - 1].dex   = i;

        a[i * 2].val  = en;
        a[i * 2].type = 1;
        a[i * 2].dex  = i;
    }

    for (i = n; i >= 1; i--) st.push(i);

    sort (a + 1,a + 2 * n + 1,ss);

    for (i = 1; i <= 2 * n; i++){
        if (a[i].type == 0) {
            tmp = st.top();
            st.pop();
            meet[a[i].dex] = tmp;

            room[tmp].push_back(a[i].dex);
            m = max(m, tmp);
        }
        else st.push(meet[a[i].dex]);
    }

    cout << m << "\n";
    for (i = 1; i <= m; i++){
        for (j = 0;j <room[i].size(); j++) cout << room[i][j] << " ";
        cout << "\n";
    }
}
