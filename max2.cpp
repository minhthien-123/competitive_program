#include <bits/stdc++.h>
using namespace std;

struct arr{
    int val;
    int dex;
};

struct ara{
    int val;
    int beg;
    int en;
};

bool cmp(arr a, arr b){
    return a.val < b.val;
}

ara ans[1000005];
arr a[1000005], b[1000005];
int n;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("max2.inp", "r", stdin);
    freopen("max2.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].val >> b[i].val;
        a[i].dex = i;
        b[i].dex = i;
    }

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= n; i++) cout << a[i].val << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << b[i].val << " ";
    cout << "\n";

    ans[0].val = abs(a[n].val - a[2].val);
    ans[0].beg = min(a[n].dex, a[2].dex);
    ans[0].en  = max(a[n].dex, a[2].dex);

    ans[1].val = abs(a[n - 1].val - a[1].val);
    ans[1].beg = min(a[n - 1].dex, a[1].dex);
    ans[1].en  = max(a[n - 1].dex, a[1].dex);

    ans[2].val = abs(b[n].val - b[2].val);
    ans[2].beg = min(b[n].dex, b[2].dex);
    ans[2].en  = max(b[n].dex, b[2].dex);

    ans[2].val = abs(b[n - 1].val - b[1].val);
    ans[2].beg = min(b[n - 1].dex, b[1].dex);
    ans[2].en  = max(b[n - 1].dex, b[1].dex);

    int res = 0;

    for (int i = 0; i <= 4; i++){
        res = max(res, ans[i].val);
    }

    cout << res;
}
