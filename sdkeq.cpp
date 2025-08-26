#include<bits/stdc++.h>
using namespace std;
const int nmax=1000001;
int n,k;
long long a[nmax],f[nmax];

main(){
    freopen("SDKEQ.inp","r",stdin);
    freopen("SDKEQ.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
        a[i]+=a[i-1];
    }
    for (int t=0;t<k;t++){
        long long best=-1000000000000000000LL*(t!=0),most=-1000000000000000000LL;
        for (int i=1;i<=n;i++){
            long long F=f[i];
            f[i]=max(most,a[i]+best);
            best=max(best,F-a[i]);
            most=max(most,f[i]);
        }
    }
    long long res=-1000000000000000000LL;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    printf("%lld",res);
}
