#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("NQUEENS.INP","r",stdin);
    freopen("NQUEENS.OUT","w",stdout);
	long long n;cin>>n;
	if(n==2||n==3){
	    cout << "NO" << endl;
	    return 0;
	}
	long long r=n%12;
	vector<long long> even,odd;
	for(int i=1;i<=n;i++){
		if(i%2==0) even.push_back(i);
		if(i%2==1) odd.push_back(i);
	}
	if(r==3||r==9){
	    even.push_back(2);
	    even.erase(even.begin(),even.begin()+1);
	}
	if(r==8){
		for(int i=0;i<odd.size();i=i+2){
			swap(odd[i],odd[i+1]);
		}
	}
	if(r==2){
	    swap(odd[0],odd[2]);
	    odd.push_back(5);
	    odd.erase(odd.begin()+4,odd.begin()+5);

	}
	if(r==3||r==9){
	    odd.push_back(1);
	    odd.push_back(3);
	    odd.erase(odd.begin()+1,odd.begin()+2);
	    odd.erase(odd.begin(),odd.begin()+1);
	}
	vector<pair<long long,long long>> v;
	for(int i=0;i<even.size();i++) v.push_back({i+1,even[i]});
	for(int i=0;i<odd.size();i++) v.push_back({even.size()+i+1,odd[i]});

	//for(int i=0;i<even.size();i++) cout << even[i] << " ";
	//for(int i=0;i<odd.size();i++) cout << odd[i] << " ";

	sort(v.begin(),v.end());
	cout << "YES" << endl;
	for(auto x:v){
	    cout << x.first << " " << x.second << endl;
	}
}