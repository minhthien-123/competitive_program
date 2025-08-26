/*
From Loc bell tk5
❤❤❤
CHT
*/
#include<bits/stdc++.h>
#define task "BUILDING"
using namespace std;
long m,n,a[1009][1009],gmax[1009][1009],max1=LONG_MIN;
//memset(gmax,0,sizeof(gmax));
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
//freopen(task".inp","r",stdin);
//freopen(task".out","w",stdout);
cin>>m>>n;
for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
        cin>>a[i][j];
for(long i=1;i<=m;i++)
{
for(long j=1;j<=n;j++)
    if(a[i][j]>=max1)
{
    gmax[i][j]=1;
    max1=a[i][j];
}
for(long j=n;j>=1;j--)
    if(a[i][j]>=max1)
{
    gmax[i][j]=1;
    max1=a[i][j];
}
}
for(long j=1;j<=n;j++)
{
for(long i=1;i<=m;i++)
    if(a[i][j]>=max1)
{
    gmax[i][j]=1;
    max1=a[i][j];
}
for(long i=m;i>=1;i--)
    if(a[i][j]>=max1)
{
    gmax[i][j]=1;
    max1=a[i][j];
}
}
cout<<max1;
return 0;
}
