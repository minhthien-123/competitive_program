#include <bits/stdc++.h>
using namespace std;

int d,n,j,i;
int main(){
    cin>>n>>d;
    array <int,100000> a,dp;
    dp.fill(1);
    int m = INT_MIN;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=i-1;j++){
            if(a[i]-a[j]==d) dp[i]=max(dp[i],dp[j]+1);
            m = max(m,dp[i]);
        }
    }
    cout << m;
    return 0;
}
