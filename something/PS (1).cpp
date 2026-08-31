#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct mang{
    ll vt,gt;
};
ll n,a[1000009],i,j,l,r,mx=LLONG_MIN;
mang mn[1000009];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("ps.inp","r",stdin);
    freopen("ps.out","w",stdout);

    cin>>n;
    a[0]=0;
    for(i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i-1]+a[i];
    }
    mn[n].gt=a[n];
    mn[n].vt=n;
    for(i=n-1;i>=1;i--){
        if(mn[i+1].gt>a[i]){
            mn[i].gt=mn[i+1].gt;
            mn[i].vt=mn[i+1].vt;
        }
        else{
            mn[i].gt=a[i];
            mn[i].vt=i;
        }
    }
    i=0;
    j=1;
    while(i<=n && j<=n){
        if(mn[j].gt>a[i])
        {
            if(mx<=mn[j].vt-i){
                mx=mn[j].vt-i;
                j=mn[j].vt+1;
                l=i+1;
                r=j-1;
            }
            else j++;
        }
        else{
            i++;
        }

        cout << i << " " << j << "\n";
    }
    cout<<l<<" "<<r;
}
