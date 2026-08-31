#include <bits/stdc++.h>
#define task "bridges"
#define int long long
#define ii std::pair<int, int>

int n, res=0;
std::vector<int>b;
struct pt{
    int u;
    int v;
}a[100009];

bool cmp(pt x,pt y){
    if(x.u < y.u) return true;
    if(x.u == y.u && x.v < y.v)return true;
    return false;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i].u>>a[i].v;
        b.push_back(a[i].v);
    }

    std::sort(a+1,a+n+1,cmp);
    std::sort(b.begin(),b.end());

    for(int i=1;i<=n;i++){
        auto e=std::lower_bound(b.begin(),b.end(),a[i].v);
        res+=e-b.begin();
        b.erase(e);
    }

    std::cout<<res;

    return 0;
}
