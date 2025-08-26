#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,res=0;
main(){
	     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
       cout.tie(NULL);
	cin>>n;
	for(int i=5,j=0;i<=n;i*=5,j++){
		int m=n-n%i;
		int cnt=m/i;
		res+=cnt*n+cnt-i*(cnt+1)*cnt/2;
	}
	cout<<res;
}