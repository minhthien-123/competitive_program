#include <bits/stdc++.h>
using namespace std;
int i,n,a[200000],b[200000],c[200000],dpa[200000],dpb[200000],dpc[200000];

int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    cout << "\n";
    dpa[1] = a[1];
    dpb[1] = b[1];
    dpc[1] = c[1];
    for(i=2;i<=n;i++){
        dpa[i] = max(dpb[i-1]+a[i],dpc[i-1]+a[i]);
        dpb[i] = max(dpa[i-1]+b[i],dpc[i-1]+b[i]);
        dpc[i] = max(dpa[i-1]+c[i],dpb[i-1]+c[i]);
    }
    cout<<max(max(dpa[n],dpb[n]),dpc[n]);
    
    return 0;
}
