#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    return 0;
}

long long n, i, length = 0, len, top, r;
long long a[1000005], st[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("delnum.inp", "r", stdin);
    //freopen("delnum.out", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];

    top = 2; r = 3;

    st[1] = a[1];
    st[2] = a[2];

    while (r <= n){
        //for (i = 1; i <= top; i++) cout << a[i] << " ";
        //cout << "\n";
        //cout << r << " " << a[r] << "\n\n";

        while (a[top] < a[top - 1] && a[top] < a[r] && top > 1){
            top--;
        }

        a[++top] = a[r];

        r++;
    }

    cout << top;

    return 0;
}
