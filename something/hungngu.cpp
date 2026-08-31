#include<bits/stdc++.h>
using namespace std;
long long a,b,s;
int main()
{
     //ios_base::sync_with_stdio(0);
     //cin.tie(0); cout.tie(0);
     //freopen("a.inp","r",stdin);
     //freopen("a.out","w",stdout);
     cin>>a>>b;
     s=a*b;
     s=s%100;
     if (s&3==0)
        cout<<"YES";
     else
        cout<<"NO";
}
