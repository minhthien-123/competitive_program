#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	cin >> n;
	
	long f[40];
    f[1] = 0;
    f[2] = 1;
    f[3] = 1;
        
    for (int i = 4; i <= n + 1; i++){
        f[i] = f[i - 3] + f[n - 2] + f[n - 1];
    }
    
	for (int i = 1; i <= n + 1; i++){
		cout << f[i] << endl;
	}

    //cout << f[n + 1];
}
